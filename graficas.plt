#scrip de gnuplo para generar las graficas

set datafile separator ";"


# grafica bubblesort
set terminal pngcairo size 800,600
set output 'bubblesort.png'

set title "BubbleSort"
set xlabel "N"
set ylabel "Timepo (us)"
set grid

plot 'resultados.csv' using 1:2 with linespoints title "BubbleSort"


# grafica teorica

set output 'teorica.png'

set title "Teorica O(n²)"
set ylabel "N²"

plot 'resultados.csv' using 1:4 with linespoints title "Teorica O(n²)"

# grafica bricksort 

set output 'bricksort.png'

set title "BrickSort"
set ylabel "Tiempo (us)"

plot 'resultados.csv' using 1:3 with linespoints title "Teorica O(n²)"

