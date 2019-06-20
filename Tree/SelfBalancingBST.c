#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}N;

int max(int a, int b){
	return a > b ? a : b;
}

N* newNode(int data){
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}


N* rightRotate(N* root){
	N* temp = root;
	N* left = root->left;
	temp->left = left->right;
	left->right = temp;
	root = left;
	return root;
}

N* leftRotate(N* root){
	N* temp = root;
	N* right = root->right;
	temp->right = right->left;
	right->left = temp;
	root = right;
	return root;
}


int height(N* root){
	if(root == NULL)
		return -1;
	return max(height(root->left), height(root->right)) + 1;
}

int balance(N* root){
	return height(root->left) - height(root->right);
}


N* insert(N* root, int data){
	
	if(root == NULL){
		root = newNode(data);
		return root;
	}
	
	if(balance(root) >= 2)
		return rightRotate(root);
	if(balance(root) <= -2)
		return leftRotate(root);
	
	if(data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	
	return root;
}



void display(N* root){
	if(root == NULL)
		return;
	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}

int main()
{
	N* root = NULL;
	root = insert(root, 10);
	root = insert(root, 13);
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 18);
	root = insert(root, 7);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 25);
	
	display(root);
	printf("\nleft to right height difference: %d ",height(root->left)-height(root->right));
	
	return 0;
}
	
	
	