#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

int comparator(const void *p1, const void *p2){
	return (*(int*)p1 - *(int*)p2);
}

int *bs_insert(int num[], float numD){
	int i;
	int size = (int) (numD);
	int *numBS = (int *) malloc (sizeof(int)*size);
	for(i=0; i<numD; i++){
		numBS[i] = num[i];
	}
	qsort(numBS, i, sizeof(int), comparator);
	return numBS;
}

void bs_query(int numBS[], int low, int high, int numF[], int total){
	int l = low;
	int h = high;
	int i;
	int middle;

	for(i=0; i<total; i++){
		low = l;
		high = h;
		while(low<=high){
			middle = (low + high) / 2;
			if(numF[i] == numBS[middle]){
				break;
			}
			else if(numF[i] < numBS[middle]) high = middle - 1;
			else if(numF[i] > numBS[middle]) low = middle + 1;
		}
		// if no break, doesn't exist
	}
}
