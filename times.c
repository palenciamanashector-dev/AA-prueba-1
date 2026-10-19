/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"

/***************************************************/
/* Function: average_sorting_time Date: 18/10/26           */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort method, int n_perms, int N, PTIME_AA ptime) {
    if (method == NULL || ptime == NULL || n_perms <= 0 || N <= 0) {
        return ERR;
    }

    int **perms = generate_permutations(n_perms, N);
    if (perms == NULL) {
        return ERR;
    }

    int min_ob = -1, max_ob = -1;
    long long total_ob = 0; /

    clock_t start = clock();
    if (start == (clock_t)-1) {
        for (int i = 0; i < n_perms; i++) free(perms[i]);
        free(perms);
        return ERR;
    }

    for (int i = 0; i < n_perms; i++) {
        int ob = method(perms[i], 0, N - 1); 
        
        if (ob == ERR) {
            for (int j = 0; j < n_perms; j++) free(perms[j]);
            free(perms);
            return ERR;
        }

        total_ob += ob;
        if (i == 0 || ob < min_ob) min_ob = ob;
        if (i == 0 || ob > max_ob) max_ob = ob;
    }

    clock_t end = clock();
    if (end == (clock_t)-1) {
        for (int i = 0; i < n_perms; i++) free(perms[i]);
        free(perms);
        return ERR;
    }

    ptime->N = N;
    ptime->n_elems = n_perms;
    ptime->time = (double)(end - start) / (CLOCKS_PER_SEC * (double)n_perms); 
    ptime->average_ob = (double)total_ob / n_perms;
    ptime->min_ob = min_ob;
    ptime->max_ob = max_ob;

    for (int i = 0; i < n_perms; i++) free(perms[i]);
    free(perms);

    return OK;
}
/***************************************************/
/* Function: generate_sorting_times Date:18/10/26          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms) {
    if (method == NULL || file == NULL || num_min < 1 || num_max < num_min || incr <= 0 || n_perms <= 0) {
        return ERR;
    }

    int n_times = ((num_max - num_min) / incr) + 1;
    
    PTIME_AA times = (PTIME_AA)malloc(n_times * sizeof(TIME_AA));
    if (times == NULL) {
        return ERR;
    }

    int current_N = num_min;
    
    for (int i = 0; i < n_times; i++) {
        if (average_sorting_time(method, n_perms, current_N, &times[i]) == ERR) {
            free(times);
            return ERR;
        }
        current_N += incr;
    }

    if (save_time_table(file, times, n_times) == ERR) {
        free(times);
        return ERR;
    }

    free(times);
    return OK;
}
/***************************************************/
/* Function: save_time_table Date:19/10/26                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA time, int n_times) {
    if (file == NULL || time == NULL || n_times <= 0) {
        return ERR;
    }

    FILE *f = fopen(file, "w");
    if (f == NULL) {
        return ERR;
    }

    for (int i = 0; i < n_times; i++) {

        fprintf(f, "%d %d %f %f %d %d\n", 
                time[i].N, 
                time[i].n_elems, 
                time[i].time, 
                time[i].average_ob, 
                time[i].min_ob, 
                time[i].max_ob);
    }

    if (fclose(f) != 0) {
        return ERR;
    }

    return OK;
}