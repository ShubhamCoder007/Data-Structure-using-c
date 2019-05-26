#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}N;


N* newNode(int data){
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void displayInOrder(N* root){
	if(root == NULL)
		return;
	displayInOrder(root->left);
	printf(" %d ",root->data);
	displayInOrder(root->right);
}


int getNumNodes(N* root){
	if(root == NULL)
		return 0;
	return getNumNodes(root->left) + getNumNodes(root->right) + 1;
}


N* insert(N* root, int data){
	if(root == NULL){
		root = newNode(data);
		return root;
	}
	if(data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
}

int* getTreeData(N* root, int a[], int* N){
	if(root == NULL || N < 0)
		return a;
	getTreeData(root->left, a, N);
	a[*N - 1] = root->data;
	*N = *N - 1;
	getTreeData(root->right, a, N);
}

	
N* treeFromArray(int a[], int N){
	struct node* root = NULL;	//N* root = NULL;
	int i = 0;
	for(; i < N; i++)
		root = insert(root, a[i]);
	return root;
}
	

int main()
{
	N* root = newNode(8);
	root->left = newNode(20);
	root->right = newNode(1);
	root->right->left = newNode(4);
	root->left->right = newNode(12);
	root->left->left = newNode(45);
	root->left->left->right = newNode(5);
	
	displayInOrder(root);
	
	int count = getNumNodes(root);
	int n = count;
	printf("\nNumber of nodes: %d \n",count);
	
	int* a = (int*)malloc(sizeof(int)*count);
	
	a = getTreeData(root, a, &count);
	int i = 0;
	printf("\nArray Data:\n");
	for(; i < n; i++)
		printf(" %d ",a[i]);
	
	
	free(root);
	
	root = treeFromArray(a, n);
	
	printf("\n");
	printf("\nConstructing tree from array data:\n");
	
	displayInOrder(root);
	
	return 0;
}