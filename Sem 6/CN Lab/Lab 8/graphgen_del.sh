set terminal png
set output 'delay.png'
set xrange [0.000:100.000]

set xlabel "Time(in seconds)"
set autoscale
set yrange [50.00:50.09 ]

set ylabel "delay in milli seconds"
set grid
set style data linespoints
plot "del_tahoe" using 1:2 title "delay graph "
 


