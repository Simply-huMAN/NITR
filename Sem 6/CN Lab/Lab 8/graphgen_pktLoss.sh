set terminal png
set output 'pktLoss.png'
set xrange [0.0:100.0]
set xlabel "Time(in seconds)"
set autoscale
set yrange [0.000:0.008]

set ylabel "packet loss ratio "
set grid
set style data linespoints
plot "pktLossReno" using 1:2 title "TCP Reno pkt loss " lt rgb "blue" ,\
 "pktLossTahoe" using 1:2 title "TCP tahoe pkt loss" lt rgb "red"

