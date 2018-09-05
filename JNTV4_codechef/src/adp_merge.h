#ifndef __3k9_MERGESORT_H
#define __3k9_MERGESORT_H


unsigned int allocate_uintarray(unsigned int **array, unsigned int N);

unsigned int randomize_uintarray(unsigned int *array,\
                                 unsigned int arraylen,\
                                 unsigned int randmax);
				 
int copy_uintarray(unsigned int *src, unsigned int *dst, unsigned int N);

unsigned int merge_sort(unsigned int *array, unsigned int N);

unsigned int split_merge_sorted(unsigned int *src, unsigned int *dst,\
                                unsigned int firstindex, unsigned int lastindex);

unsigned int merge_sorted(unsigned int *src, unsigned int *dst,\
                          unsigned int firstindex,\
                          unsigned int middleindex,\
                          unsigned int lastindex);


#endif
