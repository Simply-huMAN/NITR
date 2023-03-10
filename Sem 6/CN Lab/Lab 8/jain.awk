BEGIN{

 time_interval = 0.1;
start = 0.01;
sentPkt=0;
dropCnt=0;

}

{
event = $1
time = $2
from_node = $3;
to_node = $4;
pkt_type = $5;
pkt_size=$6;
src_addr = $9;
dest_addr = $10;
pkt_id = $12



if( event=="+" && int(from_node) ==int(src_addr) && pkt_type!="ack")
{
   node=int(from_node);
   sentSize[node]+= pkt_size;
}
 
if(time >start )
{

    sigmax=0;
    sigmaxSqr=0;
       for (i = 0; i <= 5; ++i)
       {
             sigmax+=sentSize[i];
             sigmaxSqr+= sentSize[i]*sentSize[i];
             sentSize[i]=0;
        }

    if(sigmaxSqr!=0)
      y=sigmax*sigmax/(6*sigmaxSqr);
    else
    y=0;
      print time , y;
       
    #print time , y;
    start+=time_interval;
 
}
}
END{
;
}
