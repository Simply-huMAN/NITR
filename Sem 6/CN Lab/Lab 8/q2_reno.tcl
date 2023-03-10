#Reno
set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red
$ns color 3 Yellow
$ns color 4 Pink
$ns color 5 Black
$ns color 6 Green

set tracefile [open reno.tr w]
$ns trace-all $tracefile

set namfile [open reno.nam w]
$ns namtrace-all $namfile


for {set i 0} {$i < 6} {incr i} {
 set n($i) [$ns node] 
}

for {set i 0} { $i < 6} {incr i} {
set r($i) [$ns node] 
}

set b(0) [$ns node]
set b(1) [$ns node]


for {set i 0} { $i < 6} {incr i} {
$ns duplex-link $n($i) $b(0) 300Kb 20ms DropTail
}


$ns duplex-link $b(0) $b(1) 150Kb 10ms DropTail

for {set i 0} { $i < 6} {incr i} {
$ns duplex-link $r($i) $b(1) 300Kb 20ms DropTail
}





#tcp setup

for {set i 0} { $i < 4} {incr i} {
  set tcp($i) [new Agent/TCP/Reno]
set sink($i) [new Agent/TCPSink]
$ns attach-agent $n($i) $tcp($i)
$ns attach-agent $r($i) $sink($i)
set ftp($i) [new Application/FTP]
$ftp($i) attach-agent $tcp($i)

$ns connect $tcp($i) $sink($i)
$tcp($i) set fid_ $i+1

}

#udp setup

set udp(0) [new Agent/UDP]
set udp(1) [new Agent/UDP]
set null(0) [new Agent/Null]
set null(1) [new Agent/Null]

$ns attach-agent $n(4) $udp(0)
$ns attach-agent $r(4) $null(0)
set cbr(0) [new Application/Traffic/CBR]

$cbr(0) attach-agent $udp(0)

$ns connect $udp(0) $null(0)
$udp(0) set fid_ 5

$ns attach-agent $n(5) $udp(1)
$ns attach-agent $r(5) $null(1)
set cbr(1) [new Application/Traffic/CBR]

$cbr(1) attach-agent $udp(1)

$ns connect $udp(1) $null(1)
$udp(1) set fid_ 6






 $ns at 1.0 "$ftp(0) start"
 $ns at 1.0 "$ftp(1) start"
 $ns at 1.0 "$ftp(2) start"
 $ns at 1.0 "$ftp(3) start"
 
 $ns at 15.0 "$cbr(0) start"
 $ns at 15.0 "$cbr(1) start"
#for {set i 0} { $i < 4} {incr i} {
 # $ns at 1.0 "$ftp($i) start"
#}

#for {set i 4} { $i < 6} {incr i} {
#set j $i-4
 # $ns at 15.0 "$udp($j) start"
#}






$ns at 100.0 "finish"

proc finish {} {
   global ns tracefile namfile
   $ns flush-trace
   close $tracefile
   close $namfile
   exit 0
}


$ns run

