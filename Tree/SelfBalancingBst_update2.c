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

N* checkRotate(N* root){
	if(balance(root) >= 2)
		return rightRotate(root);
	if(balance(root) <= -2)
		return leftRotate(root);
	
	return root;
}

N* rebalance(N* root){
	if(root == NULL)
		return NULL;
	
	rebalance(root->left);
	rebalance(root->right);
	
	return checkRotate(root);
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
	
	return rebalance(root);
}

N* findMin(N* root){
	if(root == NULL)
		return NULL;
	
	while(root->left != NULL)
		root = root->left;
	return root;
}

N* delete(N* root, int data){
	if(root == NULL)
		return NULL;
	
	else if(root->data > data)
		root->left = delete(root->left, data);
	
	else if(root->data < data)
		root->right = delete(root->right, data);
	
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		else if(root->left == NULL){
			N* temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL){
			N* temp = root;
			root = root->left;
			free(temp);
		}
		else{
			N* temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	
	return rebalance(root);
}
	



bool search(N* root, int data){
	if(root->data == data)
		return true;
	if(data > root->data)
		return search(root->right, data);
	else
		return search(root->left, data);
	
	return false;
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
	
	int n = 1;
	int data = 0;
	int i = 1;
	while(n != 0 && i <= 100){
		printf("\nEnter the data: ");
		//scanf("%d",&data);
		root = insert(root, i);
		printf("\nleft to right height difference: %d \n",balance(root));
		//printf("\nEnter 0 to exit: ",&n);
		//scanf("%d",&n);
		printf("\nDisplaying the elements: ");
		display(root);
		i++;
	}
	
	printf("\n\nroot: %d\n",root->data);
	
	display(root);
	
	root = delete(root, 25);
	root = delete(root, 13);
	
	//root = rebalance(root);
	
	printf("\nleft to right height difference: %d \n",height(root->left)-height(root->right));
	
	
	return 0;
}
	
	
	