/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"

/***************************************************/
/* Function: random_num Date:                      */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{
  if (inf < 0 || inf >sup){
    return ERR;
  }

  if ((sup-inf)> RAND_MAX){
    return ERR;
  } 

  return inf +(rand() % (sup-inf +1));
}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int generate_perm(int *perm, int N) {
    int i, rand_idx, temp;

    if (perm == NULL || N <= 0) {
        return ERR;
    }

    for (i = 0; i < N; i++) {
        perm[i] = i + 1;
    }

    for (i = 0; i < N; i++) {
        rand_idx = random_num_unbiased(i, N - 1);

        temp = perm[i];
        perm[i] = perm[rand_idx];
        perm[rand_idx] = temp;
    }

    return OK;
}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors:                                        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{
    int** perms = NULL;
    int i;

    if (n_perms <= 0 || N <= 0) {
        return NULL;
    }

    perms = (int**)calloc(n_perms, sizeof(int*));
    if (perms == NULL) {
        return NULL;
    }

    for (i = 0; i < n_perms; i++) {
        perms[i] = generate_perm(N);
        
        if (perms[i] == NULL) {
            while (i > 0) { 
                i--;   
                free(perms[i]);
            }
            free(perms);
            return NULL;
        }
    }

    return perms;
}
