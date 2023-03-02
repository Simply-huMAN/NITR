#Lab 7 q1
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
#Create links between the nodes
$ns duplex-link $n1 $n2 100Mb 2ms DropTail
$ns duplex-link $n2 $n3 100Mb 2ms DropTail
$ns duplex-link $n3 $n4 100Mb 2ms DropTail
$ns duplex-link $n4 $n5 100Mb 2ms DropTail
$ns duplex-link $n5 $n6 100Mb 2ms DropTail
$ns duplex-link $n6 $n1 100Mb 2ms DropTail
#Position of nodes
$ns duplex-link-op $n1 $n2 orient right-down
$ns duplex-link-op $n2 $n3 orient down
$ns duplex-link-op $n3 $n4 orient left-down
$ns duplex-link-op $n4 $n5 orient left-up
$ns duplex-link-op $n5 $n6 orient up
$ns duplex-link-op $n6 $n1 orient right-up


#Setup a TCP connection
set tcp0 [new Agent/TCP]
$tcp0 set class_ 1
$ns attach-agent $n1 $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n4 $sink0
$ns connect $tcp0 $sink0

#Setup a FTP over TCP Connection
set ftp0 [new Application/FTP]
$ftp0 set packetSize_ 500
$ftp0 set interval_ 0.01
$ftp0 attach-agent $tcp0

$ns at 0.5 "$ftp0 start"
$ns at 10.0 "$ftp0 stop"

$ns at 100.0 "finish"
#Run the simulation
$ns run
