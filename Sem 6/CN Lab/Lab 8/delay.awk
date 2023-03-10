BEGIN{
receiveNum = 0;
 time_interval = 0.1;
start = 0.01;
tot_delay=0;
cur_delay=0;
tot_pkt=0;
mn=2;
mx=0;
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
   sendTime[pkt_id]=time;
}
if(event=="r" && int(to_node) == int(dest_addr) && pkt_type!="ack" )
{
   recvTime[pkt_id]=time;
   delay[pkt_id] = recvTime[pkt_id]-sendTime[pkt_id];
   tot_delay+=delay[pkt_id];
   #print " before cur_delay " , cur_delay;
   cur_delay+=delay[pkt_id];
   #print " after cur_delay " , cur_delay;
   receiveNum++;
     tot_pkt++;
   
   
} 
if(time >start )
{

    if(receiveNum!=0)
      y=cur_delay/receiveNum;
    else
    y=0;
      print time , y*1000;
       
    #print time , y;
    start+=time_interval;
    receiveNum=0;
    cur_delay=0;
}
}
END{
if (tot_pkt != 0) 
{
avg_delay = tot_delay / tot_pkt;
}
else 
{
avg_delay = 0
 }
printf(" avgDelay: %f s\n", avg_delay)
printf(" overall delay: %f s\n", tot_delay)
printf(" overall packet: %d\n", tot_pkt);
printf(" (mn,mx): %f %f \n", mn,mx);
}
