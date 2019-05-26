#include<stdio.h>
#include<malloc.h>

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

N* arrayToBst(int a[], int start, int end){
	if(start > end)
		return NULL;
	
	int mid = (start + end)/2;
	N* root = newNode(a[mid]);
	
	root->left = arrayToBst(a, start, mid - 1);
	
	root->right = arrayToBst(a, mid + 1, end);
	
	return root;
}

void displayInOrder(N* root){
	if(root == NULL)
		return;
	displayInOrder(root->left);
	printf(" %d ",root->data);
	displayInOrder(root->right);
}

int numNodes(N* root){
	if(root == NULL)
		return 0;
	return numNodes(root->left) + numNodes(root->right) + 1;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	
	N* root = arrayToBst(a, 0, 7);
	
	displayInOrder(root);
	
	printf("\nElements in left sub tree: %d\n",numNodes(root->left));
	displayInOrder(root->left);
	
	printf("\nElements in right sub tree: %d\n",numNodes(root->right));
	displayInOrder(root->right);
	
	return 0;
}
	
	