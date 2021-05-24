#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

struct BST{
	int num;
	struct BST *left, *right;
};

struct BST *getNode(int num){
	struct BST *newNode = (struct BST*) malloc (sizeof(struct BST));
	newNode->num = num;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct BST *insert(struct BST *root, int num){
	if(root == NULL){
		root = getNode(num);
		return root;
	}
	if(num <= root->num) root->left = insert(root->left, num);
	else root->right = insert(root->right, num);
	return root;
}

void print(struct BST *root){
	if(root == NULL) return;
	print(root->left);
	printf("%d\n", root->num);
	print(root->right);
}

struct BST *bst_insert(int num[], float numD){
	struct BST *root = NULL;
	int i;
	for(i=0; i<numD; i++){
		//printf("IN\n");
		root = insert(root, num[i]);
	}
	//print(root);
	return root;
}

void find(struct BST *root, int num){
	if(root == NULL) return; //printf("%d Not Found\n", num);
	else if(num < root->num) find(root->left, num);
	else if(num > root->num) find(root->right, num);
	else if(num == root->num) return; //printf("%d Found\n", num);
}


void bst_query(struct BST *root, int numF[], float numQ){
	int i;
	for(i=0; i<numQ; i++){
		find(root, numF[i]);
	}
}
