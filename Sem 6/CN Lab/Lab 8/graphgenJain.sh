set terminal png
set output 'JainFairnessIndex.png'
set xrange [0.0:100.0]
set xlabel "Time(in seconds)"
set autoscale
set yrange [0.00:0.80]

set ylabel "Jain fairness Index"
set grid
set style data linespoints
plot "jainGraphReno" using 1:2 title "TCP Reno Jain Index" lt rgb "blue" ,\
 "jainGraphTahoe" using 1:2 title "TCP Tahoe Jain Index" lt rgb "red"

