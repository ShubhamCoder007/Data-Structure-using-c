#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* link;
}N;

N* top = NULL;

void push(int data)
{
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->link = top;
	top = n;
}

int pop()
{
	if(top == NULL)
		return NULL;
	int data = top->data;
	N* t = top;
	top = top->link;
	free(t);
	return data;
}

int peek(){
	return top->data;
}

bool isEmpty(){
	return top == NULL;
}

void reverseStack(){
	N* r = top;
	while(!isEmpty())
	{
		 push(peek());
		r = top->link;
	}
	r->link = NULL;
}

void show()
{
	N* n = top;
	for(;n != NULL; n = n->link)
		printf("%d ",n->data);
}

int main()
{
	push(1);
	push(2);
	push(3);
	show();
	
	//while(top != NULL)
	//	printf("%d ",pop());

	printf("peek : %d\n",peek());
	if(!isEmpty())
	printf("not empty ");
	
	return 0;
}