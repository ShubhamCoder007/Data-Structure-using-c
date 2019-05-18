#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* next;
}N;

N* front = NULL;
N* rear = NULL;
int total = 0;

void enque(int data)
{
	N* n = (N*)malloc(sizeof(N));
	n->data = data;
	n->next = NULL;
	
	//printf("\n Enqueing %d \n",data);
	
	if(front == NULL)
		front = rear = n;
	else{
		rear->next = n;
		rear = n;
	}
	total++;
}

int deque(){
	if(front == NULL){
		printf("\nCannot Dequeue! Queue is empty!\n");
		return NULL;
	}
	
	int d;
	total--;
	
	if(front == rear){
		d = front->data;
		free(front);
		free(rear);
		front = rear = NULL;
		return d;
	}
	
	N* t = front;
	front = front->next;
	d = t->data;
	free(t);
	
	//printf("\nDequeing %d \n",d);
	
	return d;
}

bool isEmpty(){
	return front == NULL;
}

void reverse(N* n){
	if(n->next == NULL){
		front = n;
		return;
	}
	reverse(n->next);
	rear->next = n;											//f -> n -> n -> r -> Null
	rear = n;
	rear->next = NULL;
}

//reversing using stack 
//stack routines for pushing and popping
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

void freeStack(){
	free(top);
}

void reverse_stack()
{
	while(!isEmpty())
		push(deque());
	
	while(top != NULL)
		enque(pop());
}
		

void reverseFirstN(int n)
{
	//stacking first K elements to reverse 
	//To handle the limit exception
	bool flag = false;
	if(n >= total){
		flag = true;
		n = total;
	}
	
	while(n > 0){
		push(deque());
		n--;
	}
	
	//
	N* t = NULL;
	N* start = NULL;
	while(top != NULL){
		N* n = (N*)malloc(sizeof(N));
		n->data = pop();
		n->next = NULL;
		if(t == NULL){
			t = start = n;
			continue;
		}
		t->next = n;
		t = n;
	}
	if(flag){
		rear = t;
		front = start;
		return;
	}
	t->next = front;
	front = start;
	//N* temp = front
}
	
/* for the next update	
void sort(){
	freeStack();
	int sorts = total;
	while(sorts > 0){
	N* temp = front;
	if(top == NULL or peek() > front->data)
		push(deque());
}*/
		
void display(){
	N* n = front;
	printf("\n-------------------------------------------------------------\n");
	for(; n != NULL; n = n->next)
		printf("| %d |",n->data);
	printf("\n-------------------------------------------------------------\n");
}

int main()
{
	enque(1);
	enque(2);
	enque(3);
	
	display();
	
	enque(4);
	enque(5);
	
	display();
	printf("\nReversing the Queue:\n");
	reverse(front);
	display();
	
	//reversing with stack
	printf("\nReversing the Queue using stack:\n");
	reverse_stack();
	
	display();
	
	deque();
	
	display();
	
	//dequeue all 
	/*while(!isEmpty()){
		display();
		deque();
	}*/
	
	printf("\nTotal elements: %d\n",total);
	printf("\nReversing first K elements:\n");
	reverseFirstN(3);
	display();
	
	enque(6);
	display();
	
	return 0;
}