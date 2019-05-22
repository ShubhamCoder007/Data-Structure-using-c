#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}N;



//Custom Queue

typedef struct Node
{
	N* data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(N* datanode){
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = datanode;
	n->next = NULL;
	if(front == NULL){
		front = rear = n;
		return;
	}
	rear->next = n;
	rear = n;
}

N* dequeue(){
	if(front == NULL)
		return NULL;
	Node* temp = front;
	front = front->next;
	return temp->data;
}

bool isEmpty(){
	return front == NULL;
}




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


int max(int a, int b){
	return a > b ? a : b;
}

int height(N* root){
	if(root == NULL)
		return -1;
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r) + 1;
}

void display(N* root){
	if(root == NULL)
		return;
	printf("%d ",root->data);
	display(root->left);
	display(root->right);
}

N* findMin(N* root){
	if(root->left == NULL)
		return root;
	return findMin(root->left);
}
N* findMax(N* root){
	if(root->right == NULL)
		return root;
	return findMax(root->right);
}


N* delete(N* root, int data){
	if(root == NULL)
		return NULL;
	else if(root->data < data)
		root->right = delete(root->right, data);
	else if(root->data > data)
		root->left = delete(root->left, data);
	else{
		//leaf node
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
	return root;
}

N* findNode(N* root, int data){
	if(root == NULL)
		return NULL;
	if(root->data > data)
		return findNode(root->left, data);
	else if(root->data < data)
		return findNode(root->right, data);
	else
		return root;
}

N* inorderSucc(N* root, int data){
	if(root == NULL)
		return NULL;
	N* ancestor = root;
	N* successor = NULL;
	N* cur = findNode(root, data);
	while(ancestor != NULL){
		if(ancestor->data > cur->data){
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else 
			ancestor = ancestor->right;
	}
	return successor;
}
			

//using queue implementation
void displayLevel(N* root){
	if(root == NULL)
		return;
	enqueue(root);
	while(!isEmpty()){
		N* n = dequeue();
		printf("%d ",n->data);
		if(n->left != NULL)
			enqueue(n->left);
		if(n->right != NULL)
			enqueue(n->right);
		//free(n);
	}
}


int main()
{
	N* root = NULL;
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 12);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 22);
	
	printf("Min: %d Max: %d \n",findMin(root)->data, findMax(root)->data);
	
	printf("\nDisplaying elements:\n");
	display(root);
	
	printf("\nheight: %d\n",height(root));
	
	printf("\n\nBreadth wise display: \n");
	displayLevel(root);
	
	printf("\n\nin order Succesor of 10 : %d \n",inorderSucc(root, 10)->data);
	printf("\n\nin order Succesor of 2 : %d \n",inorderSucc(root, 2)->data);
	printf("\n\nin order Succesor of 5 : %d \n",inorderSucc(root, 5)->data);
	
	display(root);
	
	printf("\nDeleting 5\n");
	
	//printf("\n\nChecking %d\n",findMin(root)->data);
	//display(root);
	
	root = delete(root, 5);
	display(root);
	
	//printf("Enter the number: \n");
	//int n;
	//scanf("%d",&n);
	if(search(root, 8))
		printf("\nPresent");
	else
		printf("\nNot Present");
	
	return 0;
}