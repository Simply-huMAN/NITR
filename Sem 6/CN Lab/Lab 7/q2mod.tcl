#Lab 7 q2
set ns [new Simulator]
#Define different colours for data flow between nodes
$ns color 1 Blue
$ns color 2 Red
#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf
#Define a 'finish' procedure
proc finish {} {
global ns nf
$ns flush-trace
#close the trace file
close $nf
#Execute nam on the trace file
exec nam out.nam &
exit 0
}
#Create 6 nodes
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]
set n11 [$ns node]
set n12 [$ns node]
set n13 [$ns node]
set n14 [$ns node]
#Create links between the nodes
$ns duplex-link $n1 $n7 300Mb 20ms DropTail
$ns duplex-link $n2 $n7 300Mb 20ms DropTail
$ns duplex-link $n3 $n7 300Mb 20ms DropTail
$ns duplex-link $n4 $n7 300Mb 20ms DropTail
$ns duplex-link $n5 $n7 300Mb 20ms DropTail
$ns duplex-link $n6 $n7 300Mb 20ms DropTail
$ns duplex-link $n7 $n8 300Mb 20ms DropTail
$ns duplex-link $n8 $n9 300Mb 20ms DropTail
$ns duplex-link $n8 $n10 300Mb 20ms DropTail
$ns duplex-link $n8 $n11 300Mb 20ms DropTail
$ns duplex-link $n8 $n12 300Mb 20ms DropTail
$ns duplex-link $n8 $n13 300Mb 20ms DropTail
$ns duplex-link $n8 $n14 300Mb 20ms DropTail
#$ns duplex-link $n6 $n1 100Mb 2ms DropTail
#Position of nodes
#$ns duplex-link-op $n1 $n5 orient down


#Setup a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n1 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n11 $sink
$ns connect $tcp $sink
#$tcp set fid_ 1

#Setup a FTP over TCP Connection
set ftp [new Application/FTP]
$ftp set packetSize_ 500
$ftp set interval_ 1
$ftp attach-agent $tcp
#$ftp set type_ FTP

set udp [new Agent/UDP]
#$udp set class_2
$ns attach-agent $n5 $udp

set null [new Agent/Null]
$ns attach-agent $n13 $null
$ns connect $udp $null

#Setup a CBR over UDP connection
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set rate_ 1mb
$cbr set random_ false

$ns at 1.0 "$ftp start"
$ns at 15.0 "$cbr start"
$ns at 100.0 "finish"
#Run the simulation
$ns run
