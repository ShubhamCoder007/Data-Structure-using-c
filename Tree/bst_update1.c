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

int min(N* root){
	if(root->left == NULL)
		return root->data;
	return min(root->left);
}

int max(N* root){
	if(root->right == NULL)
		return root->data;
	return max(root->right);
}

int maxim(int a, int b){
	return a > b ? a : b;
}

int height(N* root){
	if(root == NULL)
		return -1;
	int l = height(root->left);
	int r = height(root->right);
	return maxim(l,r) + 1;
}

void display(N* root){
	if(root == NULL)
		return;
	printf("%d ",root->data);
	display(root->left);
	display(root->right);
}

//using queue implementation
void displayLevel(N* root){
	if(root == NULL)
		return;
	enqueue(root);
	while(!isEmpty()){
		N* n = dequeue();
		printf(" %d",n->data);
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
	
	printf("Min: %d Max: %d \n",min(root), max(root));
	
	printf("\nDisplaying elements:\n");
	display(root);
	
	printf("\nheight: %d\n",height(root));
	
	printf("\n\nBreadth wise display: \n");
	displayLevel(root);
	
	//printf("Enter the number: \n");
	//int n;
	//scanf("%d",&n);
	if(search(root, 8))
		printf("Present");
	else
		printf("Not Present");
	
	return 0;
}