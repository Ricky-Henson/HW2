#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"header.h"
#define size 1000000

struct BST{
	int num;
	struct BST *left, *right;
};

struct LL{
	int num;
	struct LL *next;
};

int num[1000000];

int numF[100000];
int *numarr;
int *numBS;
struct BST *root = NULL;
struct LL *head = NULL;


int main(int argc, char *argv[]){
	// numarr = (int*) malloc (1000000);
	int i;
	//int *array;
	for(i=0; i<1000000; i++){
		num[i] = 0;
	}
	FILE *fp;
	int bst = OFF, bs = OFF, arr = OFF, ll = OFF, hash = OFF, insert = OFF, query = OFF;
	float numD = 0;
	float numQ = 0;
	if(argc>1){
		for(i=0; i<argc; i++){
			if(strcmp(argv[i], "-bst") == 0){
				bst = ON;
			}
			else if(strcmp(argv[i], "-bs") == 0){
				bs = ON;
			}
			else if(strcmp(argv[i], "-arr") == 0){
				arr = ON;
			}
			else if(strcmp(argv[i], "-ll") == 0){
				ll = ON;
			}
			else if(strcmp(argv[i], "-hash") == 0){
				hash = ON;
			}
			else if(strcmp(argv[i], "-d") == 0){
				insert = ON;
				numD = atof(argv[i+1]);
				// printf("numD %f\n", numD);
			}
			else if(strcmp(argv[i], "-q") == 0){
				query = ON;
				numQ = atof(argv[i+1]);
				// printf("numQ %f\n", numQ);
			}
		}
	}
	// char temp[2048];
	struct timeval start;
	struct timeval end;
	unsigned long diff;

	if(query == ON) GenerateDataF(numQ);
	if(insert == ON){
		GenerateData(numD);
		if(bst == ON){
			printf("BST:\n");
			GenerateToNum(num, fp);
			// fp = fopen("datasetI.txt", "r");
			// i=0;
			// while(fgets(temp, 2048, fp)){
			// 	num[i] = atoi(temp);
			// 	i++;
			// }
			// fclose(fp);
			gettimeofday(&start, NULL);
			root = bst_insert(num, numD);
			//for(i=0; i<5; i++){
			//	printf("%d\n", num[i]);
			//}
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("BST Generation performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
			if(query == ON){
				GenerateToNumF(numF, fp);
				// fp = fopen("datasetF.txt", "r");
				// i=0;
				// while(fgets(temp, 2048, fp)){
				// 	numF[i] = atoi(temp);
				// 	i++;
				// }
				// fclose(fp);
				gettimeofday(&start, NULL);
				bst_query(root, numF, numQ);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				printf("BST Query performance %ld us (equal %f sec)\n\n", diff, diff/1000000.0);
			}
		}
		if(bs == ON){
			printf("Binary Search:\n");
			GenerateToNum(num, fp);
			gettimeofday(&start, NULL);
			numBS = bs_insert(num, numD);
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("Binary Search Generation performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
			if(query == ON){
				GenerateToNumF(numF, fp);
				int high = (int) numQ;
				int total = (int) numQ;
				gettimeofday(&start, NULL);
				bs_query(numBS, 0, high, numF, total);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				printf("Binary Search Query performance %ld us (equal %f sec)\n\n", diff, diff/1000000.0);
			}
		}
		if(arr == ON){
			printf("Array:\n");
			GenerateToNum(num, fp);
			gettimeofday(&start, NULL);
			numarr = arr_insert(num, numD);
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("Array Generation performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
			if(query == ON){
				GenerateToNumF(numF, fp);
				gettimeofday(&start, NULL);
				arr_query(numarr, numF, numQ, numD);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				printf("Array Query performance %ld us (equal %f sec)\n\n", diff, diff/1000000.0); 
			}
		}
		if(ll == ON){
			printf("Linked List:\n");
			GenerateToNum(num, fp);
			gettimeofday(&start, NULL);
			head = ll_insert(num, numD);
			gettimeofday(&end, NULL);
			diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("Linked List Generation performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
			if(query == ON){
				GenerateToNumF(numF, fp);
				gettimeofday(&start, NULL);
				ll_query(head, numF, numQ);
				gettimeofday(&end, NULL);
				diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
				printf("Linked List Query performance %ld us (equal %f sec)\n\n", diff, diff/1000000.0);
			}
		}
		if(hash == ON){
			GenerateToNum(num, fp);
			hashOpt(num, numD, numQ, query);
		}
	}

	return 0;
}
