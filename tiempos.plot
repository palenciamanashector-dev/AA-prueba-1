# Configurar la salida a una imagen PNG
set terminal pngcairo size 800,600
set output 'grafica_insertsort.png'

# Etiquetas y título
set title 'Tiempos medios de CPU - InsertSort'
set xlabel 'Tamaño de la permutación (N)'
set ylabel 'Tiempo (segundos)'

# Dibujar la gráfica leyendo la columna 1 (N) y la 3 (time) del fichero de datos
# (Recordad que vuestro fichero tiene el orden: N, n_elems, time, average_ob, min_ob, max_ob)
plot 'datos_insertsort.txt' using 1:3 with linespoints title 'Tiempo CPU'