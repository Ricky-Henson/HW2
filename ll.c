#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

struct LL{
	int num;
	struct LL *next;
};

struct LL *pushHead(struct LL *head, int num){
	struct LL *newNode = (struct LL*) malloc (sizeof(struct LL));
	newNode->num = num;
	newNode->next = head;
	head = newNode;
	return head;
}
/*
void printLL(struct LL *head){
	while(head){
		printf("%d\n", head->num);
		head = head->next;
	}
}
*/

struct LL *ll_insert(int num[], float numD){
	struct LL *head = NULL;
	int i;
	for(i=0; i<numD; i++){
		head = pushHead(head, num[i]);
	}
	//printLL(head);
	return head;
}

void check(struct LL *head, int num){
	struct LL *temp = head;
	while(temp){
		if(num == temp->num){
//			printf("Found\n");
			return; // Found
		}
		temp = temp->next;
	}
//	printf("Not Found\n");
	return; // Not Found
}

void ll_query(struct LL *head, int numF[], float numQ){
	int i;
	for(i=0; i<numQ; i++){
		check(head, numF[i]);
	}
//	printLL(head);
}
