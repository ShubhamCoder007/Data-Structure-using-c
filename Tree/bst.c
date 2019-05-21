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

N* insert(N* root, int data){
	if(root == NULL){
		root = newNode(data);
		return root;
	}
	if(root->data < data)
		root->right = insert(root->right, data);
	else
		root->left = insert(root->left, data);
	
	return root;
}

bool search(N* root, int data){
	if(root == NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(root->data > data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

int main()
{
	N* root = NULL;
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 12);
	
	printf("Enter the number: \n");
	int n;
	scanf("%d",&n);
	if(search(root, n))
		printf("Present");
	else
		printf("Not Present");
	
	return 0;
}