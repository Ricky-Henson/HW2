#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"header.h"
#define size 1000000

struct Hash{
    int num;
};

struct Hash *arrhash[size];
int numF[1000000];

int hashCode(int num){
    return num % size;
}

void h_insert(int num, int idx){
    struct Hash *item = (struct Hash *) malloc (sizeof(struct Hash));
    item->num = num;
    while(arrhash[idx]!=NULL){
        ++idx;
        idx %= size;
    }
    arrhash[idx] = item;
}

void hash_insert(int num[], float numD){
    int i;
    for(i=0; i<numD; i++){
        int hashIdx = hashCode(num[i]);
        h_insert(num[i], hashIdx);
    }
}

void hash_query(int numF[], float numQ){
    int i, flag=0;
    for(i=0; i<numQ; i++){
	// printf("%f\n", numQ);
	// 	printf("%d\n", numF[i]);
        flag = 0;
        int hashIdx = hashCode(numF[i]);    
        while(arrhash[hashIdx] != NULL){
            if(arrhash[hashIdx]->num == numF[i]){
                flag = 1;
				// printf(" %d Found\n", numF[i]);
                break;
            }
            ++hashIdx;
            hashIdx %= size;
			if(flag == 0){
				// printf("%d Not Found\n", numF[i]);
				break;
			}
        }
    }
}

void display() {
   int i = 0;
   for(i = 0; i<150; i++) {
	
      if(arrhash[i] != NULL)
         printf("(%d) %d\n",arrhash[i]->num, i);
      else
         printf(" ~~ \n");
   }
	
   printf("\n");
}

void hashOpt(int num[], float numD, float numQ, int query){
	struct timeval start;
	struct timeval end;
	unsigned long diff;
    FILE *fp;
    printf("Hash:\n");
    gettimeofday(&start, NULL);
    hash_insert(num, numD);
    gettimeofday(&end, NULL);
    // display();
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Hash Generation performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
    if(query == ON){
        GenerateToNumF(numF, fp);
        gettimeofday(&start, NULL);
        hash_query(numF, numQ);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Hash Query performance %ld us (equal %f sec)\n\n", diff, diff/1000000.0);
    }
}