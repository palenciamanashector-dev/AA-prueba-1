/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */


#include "sorting.h"

/***************************************************/
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int InsertSort(int* array, int ip, int iu)
{
  int ob = 0, i, j, x;
  
  if (array == NULL || ip < 0 || ip > iu) {
    return ERR;
  }

  for (i = ip + 1; i <= iu; i++) {
    x = array[i];
    j = i - 1;
      
    while (j >= ip) {
      ob++;
      if (array[j] > x) { 
        array[j + 1] = array[j];
        j--;
      } else {
        break;
      }
    }
    array[j + 1] = x;
  }

  return ob;
}


/***************************************************/
/* Function: SelectSort    Date:                   */
/* version v2                                      */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  int ob = 0, i = iu, j, x, flag = 1;

  if (array == NULL || ip < 0 || ip > iu) {
    return ERR;
  }

  while (flag == 1 && i >= ip + 1) {
    flag = 0;

    for (j = ip; j <= i - 1; j++) {
      ob++;
            
      if (array[j] > array[j + 1]) {
        x = array[j];
        array[j] = array[j + 1];
        array[j + 1] = x;    
        flag = 1;
      }
    }
    i--;
  }

  return ob;
}






