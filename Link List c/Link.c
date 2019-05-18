#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}N;

N* head = NULL;

void insert(int data)
{
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->next = NULL;
	
	if(head == NULL)
		head = n;
	
	N* temp = head;
	for(;temp->next != NULL; temp = temp->next);
	temp->next = n;
}

void display()
{
	N* temp = head;
	for(; temp != NULL; temp = temp->next)
		printf(" %d ",temp->data);
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	
	display();
	
	return 0;
}