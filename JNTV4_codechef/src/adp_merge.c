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
  
#define VERBOSE_N 1000


int main()
{
unsigned int n;
int *S;
int x;

scanf("%i", &n);
allocate_uintarray(&S, n);
save_array(S, n);
scanf("%i", &x);

return(1);
}



unsigned int allocate_uintarray(unsigned int **array, unsigned int N)
{
*array = (unsigned int *)malloc(N * sizeof(unsigned int));
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



int copy_uintarray(unsigned int *src, unsigned int *dst, unsigned int N)
{
unsigned int i;

for(i = 0; i < N; i++)
  {
  dst[i] = src[i];
  }

return(i+1);
}



unsigned int merge_sort(unsigned int *array, unsigned int N)
{
unsigned int *buffer;
unsigned int operations = 0;

allocate_uintarray(&buffer, N);

copy_uintarray(array, buffer, N);

operations = N + split_merge_sorted(buffer, array, 0, N-1);

free(buffer);
return(operations);
}



unsigned int split_merge_sorted(unsigned int *src, unsigned int *dst,\
                                unsigned int firstindex, unsigned int lastindex)
{
unsigned int middleindex;
unsigned int returnvalue = 0;

if(lastindex - firstindex < 1)
  {
  return(0);
  }

middleindex = (firstindex + lastindex) / 2;

returnvalue += split_merge_sorted(dst, src, firstindex, middleindex);
returnvalue += split_merge_sorted(dst, src, middleindex+1, lastindex);

returnvalue += merge_sorted(src, dst, firstindex, middleindex, lastindex);

return(returnvalue);
}



unsigned int merge_sorted(unsigned int *src, unsigned int *dst,\
                          unsigned int firstindex,\
                          unsigned int middleindex,\
                          unsigned int lastindex)
{
unsigned int sorted_numbers = 0;
unsigned int lo_srcindex, hi_srcindex, dstindex;

lo_srcindex = firstindex;
hi_srcindex = middleindex + 1;

for(dstindex = firstindex; dstindex <= lastindex; dstindex++)
  {
  if(lo_srcindex <= middleindex) /* Numbers remain in the lower array part */
    {
    if(hi_srcindex > lastindex) /* No numbers reamin in the higher array part */
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
  sorted_numbers++;
  }

return(sorted_numbers);
}

