#include "libraries.h"


unsigned int print_uintarray(unsigned int *array, unsigned int N)
{
char entries_per_line = 0;
unsigned int i = 0;

entries_per_line = (char)OUTPUT_LINELENGTH / (1 + digits(N));

for(i = 0; i < N; i++)
  {
  printf ("%*d ", digits(N), array[i]);
  if(i % entries_per_line == entries_per_line - 1)
    {
    printf("\n");
    }
  }

printf("\n\n");
return(i+1);
}



char digits(unsigned int n)
{
if(0 == n)
  {
  return(1);
  }
return(floor (log((double)abs (n)) / log(10.0)) + 1);
}
