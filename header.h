#ifndef HEADER_FILE
#define HEADER_FILE

#define ON 1
#define OFF 0

void GenerateData(float numD);
void GenerateDataF(float numQ);
void GenerateToNum(int num[], FILE *fp);
void GenerateToNumF(int numF[], FILE *fp);
struct BST *bst_insert(int num[], float numD);
void bst_query(struct BST *root, int numF[], float numQ);
int *arr_insert(int num[], float numD);
void arr_query(int numarr[], int numF[], float numQ, float numD);
int *bs_insert(int num[], float numD);
void bs_query(int numBS[], int low, int high, int numF[], int total);
struct LL *ll_insert(int num[], float numD);
void ll_query(struct LL *head, int numF[], float numQ);
void hashOpt(int num[], float numD, float numQ, int query);

#endif
