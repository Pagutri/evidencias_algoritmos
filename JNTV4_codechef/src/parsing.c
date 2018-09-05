#include "libraries.h"


int parse_commandline(unsigned int *N, unsigned int *repeats,\
                      int argc, char **argv)
{
if(argc!=3)
  {
  explain_useage_exit(argv[0]);
  }

if(1 != sscanf(argv[1], "%u", N))
  {
  explain_useage_exit(argv[0]);
  }

if(1 != sscanf(argv[2], "%u", repeats))
  {
  explain_useage_exit(argv[0]);
  }

if(*N < 1 || *repeats < 1)
  {
  explain_useage_exit(argv[0]);
  }

return(1);
}
  


void explain_useage_exit(char *myname)
{
printf("\n\nUseage:\n\n%s  N  Repeats\n\n"\
       "Will generate an array of N random integers\n"\
       "from the interval [0, N), and then sort the\n"\
       "array with the Merge Sort algorithm.\n\n"\
       "The procedure will be repeated 'Repeats' times.\n\n"\
       "Both arguments must be positive integers.\n\n\n",\
       myname);
exit(0); 
}
