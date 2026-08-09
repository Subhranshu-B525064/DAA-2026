set title 'Merge Sort vs Modified Merge Sort'
set xlabel 'Number of elements (n)'
set ylabel 'Number of Comparisons'
set grid
set key left top
plot 'data.txt' using 1:2 with linespoints title 'Merge Sort', 'data.txt' using 1:3 with linespoints title 'Modified Merge Sort'
pause -1
