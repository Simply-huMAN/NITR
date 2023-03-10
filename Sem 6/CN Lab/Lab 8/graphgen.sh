set terminal png
set output 'Result.png'
set xrange [0.0:100.0]
set xlabel "Time(in seconds)"
set autoscale
set yrange [0:40000]
set ylabel "Throughput(in Kbps)"
set grid
set style data linespoints
plot "graph1" using 1:2 title "TCP Tahoe Throughput" lt rgb "blue" ,\
 "graph2" using 1:2 title "TCP Reno Throughput" lt rgb "red"

