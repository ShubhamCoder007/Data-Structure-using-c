#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

N* top = NULL;

void push(int data)
{
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->next = top;
	top = n;
}

int pop()
{
	if(top == NULL)
		return NULL;
	int data = top->data;
	N* t = top;
	top = top->next;
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
		r = top->next;
	}
	r->next = NULL;
}