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
#Create links between the nodes
$ns duplex-link $n1 $n2 300Mb 20ms DropTail
$ns duplex-link $n5 $n2 300Mb 20ms DropTail
$ns duplex-link $n2 $n3 500Mb 10ms DropTail
$ns duplex-link $n3 $n4 300Mb 20ms DropTail
$ns duplex-link $n3 $n6 300Mb 20ms DropTail
#Position of nodes
$ns duplex-link-op $n1 $n2 orient right-down
$ns duplex-link-op $n5 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n6 orient right-down


#Setup a TCP connection
set tcp0 [new Agent/TCP]
$tcp0 set class_ 1
$ns attach-agent $n1 $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n4 $sink0
$ns connect $tcp0 $sink0

#Setup a FTP over TCP Connection
set ftp0 [new Application/FTP]
#$ftp0 set packetSize_ 500
#$ftp0 set interval_ 0.01
$ftp0 attach-agent $tcp0


#Setup a UDP connection
set udp0 [new Agent/UDP]
$ns attach-agent $n5 $udp0
set null [new Agent/Null]

$ns attach-agent $n6 $null
$ns connect $udp0 $null
$udp0 set fid_ 2

#Setup a CBR over UDP connection
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp0
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false

$ns at 1.0 "$ftp0 start"
$ns at 15.0 "$cbr stop"

$ns at 100.0 "finish"
#Run the simulation
$ns run
