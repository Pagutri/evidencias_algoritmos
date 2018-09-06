/*
 * Adaptación del algoritmo merge sort que
 * determina si, dado un conjunto S de n
 * enteros y otro entero x, existen dos
 * elementos en S cuya suma sea exacta-
 * mente x.
 *
 * Patricia Gutiérrez, Septiembre 2018
 * gutierrezrs2015@licifug.ugto.mx
 *
 */

#include "libraries.h"

int main()
{
unsigned int n;
unsigned int resp = 0;
int *S;
int x;

scanf("%i", &n);
allocate_array(&S, n);
save_array(S, n);
scanf("%i", &x);

resp = merge_sort(S, n);

return(1);
}



unsigned int allocate_array(int **array, unsigned int N)
{
*array = (int *)malloc(N * sizeof(int));
if(NULL == *array)
  {
  printf("\n\nMemory allocation error in function\n"\
         "'callocate_intarray()'.\n\n");
  exit(0);
  }
return(N);
}



void save_array(int *array, unsigned int arraylen)
{
unsigned int i;

for(i = 0; i < arraylen; i++)
  {
  scanf("%i", array + i);
  }
}



int copy_array(int *src, int *dst, unsigned int N)
{
unsigned int i;

for(i = 0; i < N; i++)
  {
  dst[i] = src[i];
  }

return(i+1);
}



unsigned int merge_sort(int *array, unsigned int N)
{
int *buffer;
unsigned int resp = 0;

allocate_array(&buffer, N);

copy_array(array, buffer, N);

resp = split_merge_sorted(buffer, array, 0, N-1, 0);

free(buffer);
return(resp);
}



unsigned int split_merge_sorted(int *src, int *dst,\
                                unsigned int firstindex, unsigned int lastindex\
                                unsigned int resp)
{
unsigned int middleindex;

if(lastindex - firstindex < 1)
  {
  return(resp);
  }

middleindex = (firstindex + lastindex) / 2;

resp = split_merge_sorted(dst, src, firstindex, middleindex, resp);
resp = split_merge_sorted(dst, src, middleindex+1, lastindex, resp);

resp = merge_sorted(src, dst, firstindex, middleindex, lastindex, resp);

return(resp);
}



unsigned int merge_sorted(int *src, int *dst,\
                          unsigned int firstindex,\
                          unsigned int middleindex,\
                          unsigned int lastindex, unsigned int resp)
{
unsigned int lo_srcindex, hi_srcindex, dstindex;

lo_srcindex = firstindex;
hi_srcindex = middleindex + 1;

for(dstindex = firstindex; dstindex <= lastindex; dstindex++)
  {
  if(lo_srcindex <= middleindex) /* Numbers remain in the lower array part */
    {
    if(hi_srcindex > lastindex) /* No numbers remain in the higher array part */
      {
      dst[dstindex] = src[lo_srcindex];
      lo_srcindex++;
      }
    else /* Numbers remain in the higher array part */
      {
      if(src[lo_srcindex] < src[hi_srcindex])
        {
        dst[dstindex] = src[lo_srcindex];
        lo_srcindex++;
        }
      else 
        {
        dst[dstindex] = src[hi_srcindex];
        hi_srcindex++;
        }
      } 
    }   
  else /* No numbers remain in the lower array part */
    {
    dst[dstindex] = src[hi_srcindex];
    hi_srcindex++;
    }
  }

return(resp);
}

