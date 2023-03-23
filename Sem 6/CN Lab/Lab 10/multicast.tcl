set ns [new Simulator -multicast on]
$ns color 1 Blue
$ns color 2 Red
set tracefile1 [open out.tr w]
$ns trace-all $tracefile1
set namfile [open out.nam w]
$ns namtrace-all $namfile

proc finish {} {
    global ns tracefile1 namfile
    $ns flush-trace
    close $tracefile1
    close $namfile
    exec nam out.nam &
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]

$ns duplex-link $n0 $n1 5Mb 2ms DropTail
$ns duplex-link $n1 $n2 5Mb 1ms DropTail
$ns duplex-link $n2 $n3 5Mb 1ms DropTail
$ns duplex-link $n0 $n4 5Mb 2ms DropTail
$ns duplex-link $n4 $n3 5Mb 2ms DropTail
$ns duplex-link $n3 $n5 5Mb 2ms DropTail
$ns duplex-link $n5 $n6 5Mb 2ms DropTail
$ns duplex-link $n5 $n7 5Mb 2ms DropTail
$ns duplex-link $n6 $n8 5Mb 2ms DropTail
$ns duplex-link $n7 $n8 5Mb 2ms DropTail

$ns duplex-link-op $n0 $n1 orient right-up
$ns duplex-link-op $n0 $n1 orient right-up
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n4 $n3 orient right-up
$ns duplex-link-op $n3 $n5 orient right
$ns duplex-link-op $n5 $n6 orient right-up
$ns duplex-link-op $n5 $n7 orient right-down
$ns duplex-link-op $n6 $n8 orient right-down
$ns duplex-link-op $n7 $n8 orient right-up

set mproto DM
set mrthandle [$ns mrtproto $mproto {}]

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n8 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set grp0 [Node allocaddr]

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
$udp set fid_ 2
$udp set dst_addr_ $grp0
$udp set dst_port_ 0

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp

set rcvr1 [new Agent/LossMonitor]
set rcvr2 [new Agent/LossMonitor]
set rcvr3 [new Agent/LossMonitor]

$ns attach-agent $n6 $rcvr1
$ns attach-agent $n7 $rcvr2
$ns attach-agent $n8 $rcvr3

$ns at 0.3 "$n6 join-group $rcvr1 $grp0"
$ns at 0.3 "$n7 join-group $rcvr2 $grp0"
$ns at 0.3 "$n8 join-group $rcvr3 $grp0"

$ns at 0.1 "$ftp start"
$ns at 0.1 "$cbr start"
$ns at 89.5 "$ftp stop"
$ns at 89.5 "$cbr stop"

$ns at 90.0 "finish"
$ns run
