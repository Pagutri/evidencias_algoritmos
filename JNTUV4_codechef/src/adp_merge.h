#ifndef __3k9_MERGESORT_H
#define __3k9_MERGESORT_H


unsigned int allocate_array(int **array, unsigned int N);

void save_array(int *array, unsigned int arraylen);
				 
int copy_array(int *src, int *dst, unsigned int N);

unsigned int merge_sort(int *array, unsigned int N);

unsigned int split_merge_sorted(int *src, int *dst,\
                                unsigned int firstindex, unsigned int lastindex\
                                unsigned int resp);

unsigned int merge_sorted(int *src, int *dst,\
                          unsigned int firstindex,\
                          unsigned int middleindex,\
                          unsigned int lastindex, unsigned int resp);


#endif
