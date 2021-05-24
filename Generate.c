#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void GenerateData(float numD){
	FILE *fp;
	int i;

	fp = fopen("datasetI.txt", "w+");
	for(i=0; i<numD; i++){
		fprintf(fp, "%d\n", rand());
	}
	fclose(fp);
}

void GenerateDataF(float numQ){
	FILE *fp;
	int i;

	fp = fopen("datasetF.txt", "w+");
	for(i=0; i<numQ; i++){
		fprintf(fp, "%d\n", rand());
	}
	fclose(fp);

}

void GenerateToNum(int num[], FILE *fp){
	char temp[2048];
	int i;
	fp = fopen("datasetI.txt", "r");
	i=0;
	while(fgets(temp, 2048, fp)){
		num[i] = atoi(temp);
		i++;
	}
	fclose(fp);
}

void GenerateToNumF(int numF[], FILE *fp){
	char temp[2048];
	int i;
	fp = fopen("datasetF.txt", "r");
	i=0;
	while(fgets(temp, 2048, fp)){
		numF[i] = atoi(temp);
		i++;
	}
	fclose(fp);
}
