#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

int *arr_insert(int num[], float numD){
	int i;
	int size = (int) (numD);
	int *numarr = (int *) malloc (sizeof(int)*size);
	for(i=0; i<numD; i++){
		numarr[i] = num[i];
	}
	return numarr;
}

void arr_query(int numarr[], int numF[], float numQ, float numD){
	int i, j;
	for(i=0; i<numQ; i++){
		for(j=0; j<numD; j++){
			// printf("IN %d %d\n", numF[i], numarr[j]);
			if(numF[i] == numarr[j]){
			       	// printf("Found\n"); (flag=1)
				break;
			}
		}
		// if flag = 0 not found
	}
}
