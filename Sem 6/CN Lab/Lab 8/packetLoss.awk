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
src_addr = $9;
dest_addr = $10;
pkt_id = $12



if( event=="+" && int(from_node) ==int(src_addr) && pkt_type!="ack")
{
   sentPkt+=1;
}
if(event=="d" )
{
   dropCnt+=1;
   
   
} 
if(time >start )
{

    if(sentPkt!=0)
      y=dropCnt/sentPkt;
    else
    y=1;
      print time , y;
       
    #print time , y;
    start+=time_interval;
   sendPkt=0;
   dropCnt=0;
}
}
END{
;
}
