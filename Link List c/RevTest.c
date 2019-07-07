#include<stdio.h>
#include<malloc.h>


typedef struct node
{
	int data;
	struct node* next;
}N;

void display(N* head){
	printf("\nDisplaying:\n");
	for(; head != NULL; head = head->next)
		printf("%d ",head->data);
}

N* newNode(int data){
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->next = NULL;
	return n;
}

N* insert(N* head, int data){
	if(head == NULL){
		head = newNode(data);
		return head;
	}
	head->next = insert(head->next, data);
}

void reverse(N** head, N* n){
	if(n->next == NULL){
		*head = n;
		return;
	}
	reverse(head, n->next);
	N* temp = n->next;
	temp->next = n;
	n->next = NULL;
}
		

int main()
{
	N* head = NULL;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	
	display(head);
	
	head = insert(head, 5);
	head = insert(head, 67);
	
	display(head);
	
	//head = swapN(head, 3);
	reverse(&head, head);
	display(head);
	
	return 0;
}