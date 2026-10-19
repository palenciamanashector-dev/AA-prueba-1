# ----------------------------------------------------
# CONFIGURACIÓN GENERAL
# ----------------------------------------------------
# Configuramos la salida para generar imágenes PNG
set terminal pngcairo size 800,600
set grid

# ----------------------------------------------------
# GRÁFICA 1: Comparativa de tiempos de CPU
# ----------------------------------------------------
set output 'grafica_tiempos_cpu.png'
set title 'Tiempos medios de CPU - InsertSort vs BubbleSort'
set xlabel 'Tamaño de la permutación (N)'
set ylabel 'Tiempo (segundos)'
set key left top

# Columna 1 = N, Columna 3 = time
plot 'datos_insertsort.txt' using 1:3 with linespoints lw 2 title 'InsertSort', \
     'datos_bubblesort.txt' using 1:3 with linespoints lw 2 title 'BubbleSort'

# ----------------------------------------------------
# GRÁFICA 2: Operaciones Básicas (OB) - InsertSort
# ----------------------------------------------------
set output 'grafica_ob_insertsort.png'
set title 'Operaciones Básicas (OB) - InsertSort'
set xlabel 'Tamaño de la permutación (N)'
set ylabel 'Número de ejecuciones de la OB'

# Columna 1 = N, Columna 4 = avg, Columna 5 = min, Columna 6 = max
plot 'datos_insertsort.txt' using 1:5 with linespoints lw 2 title 'Mínimo', \
     'datos_insertsort.txt' using 1:4 with linespoints lw 2 title 'Medio', \
     'datos_insertsort.txt' using 1:6 with linespoints lw 2 title 'Máximo'

# ----------------------------------------------------
# GRÁFICA 3: Operaciones Básicas (OB) - BubbleSort
# ----------------------------------------------------
set output 'grafica_ob_bubblesort.png'
set title 'Operaciones Básicas (OB) - BubbleSort'
set xlabel 'Tamaño de la permutación (N)'
set ylabel 'Número de ejecuciones de la OB'

plot 'datos_bubblesort.txt' using 1:5 with linespoints lw 2 title 'Mínimo', \
     'datos_bubblesort.txt' using 1:4 with linespoints lw 2 title 'Medio', \
     'datos_bubblesort.txt' using 1:6 with linespoints lw 2 title 'Máximo'