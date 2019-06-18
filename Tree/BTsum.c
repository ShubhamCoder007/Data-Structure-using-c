/*Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15*/



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
 
 N* insert(N* root, int data){
	 if(root == NULL){
		 root = newNode(data);
		 return root;
	 }
	 
	 if(root->data > data)
		 root->left = insert(root->left, data);
	 else
		 root->right = insert(root->right, data);
	 
	 return root;
 }
 
 void inorderDisplay(N* root){
	 if(root == NULL)
		 return;
	 inorderDisplay(root->left);
	 printf("%d ",root->data);
	 inorderDisplay(root->right);
 }
 
 int getNumNodes(N* root){
	 if(root == NULL)
		 return 0;
	 return getNumNodes(root->left) + getNumNodes(root->right) + 1;
 }
 
 
 
 int* getArrayUtil(N* root, int* a, int* i){
	 if(root == NULL)
		 return a;
	 getArrayUtil(root->left, a, i);
	 a[*i] = root->data;
	 *i = *i + 1;
	 getArrayUtil(root->right, a, i);
	 
	 return a;
 }
 
 int* getArray(N* root){
	 int n = 0;
	 int* a = (int*)malloc(sizeof(int));
	 getArrayUtil(root, a, &n);
	 //a = (root, a, &n);
	 
	 return a;
 }
 
 
 
 void displayArr(int* a, int n){
	 int i = 0;
	 printf("\n");
	 for(; i < n; i++)
		 printf("%d ",a[i]);
 }
 
 
 void sumNodesArrUtil(int* a, int i, int j, int end, int k, int res[]){
	 if(k == 0)
		 return;
	 
	 if(i == end || j == end)
		 return;
	 
	 if(i == j)
		 return;
	 
	 if(a[i] + a[j] == k){
		 res[0] = a[i];
		 res[1] = a[j];
		 return;
	 }
	 
	 sumNodesArrUtil(a, i + 1, j, end, k, res);
	 sumNodesArrUtil(a, i, j + 1, end, k, res);
	 
 }
	 
	 
 int* sumNodes(N* root, int k){
	 int n = getNumNodes(root);
	 int* a = getArray(root);
	 int* res = (int*)malloc(sizeof(int));
	 res[0] = res[1] = -1;
	 sumNodesArrUtil(a, 0, 1, n, k, res);
	 
	 return res;
 }
 
 
 int main()
 {
	 N* root = NULL;
	 root = insert(root, 10);
	 root = insert(root, 5);
	 root = insert(root, 15);
	 root = insert(root, 11);
	 root = insert(root, 15);
	 
	 inorderDisplay(root);
	 
	 int k = 0;
	 printf("\nEnter the value: ");
	 scanf("%d",&k);
	 
	 
	 printf("\n");
	 displayArr(sumNodes(root, k), 2);
	 
	 return 0;
 }
	 
	 
	 