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

N* swapN(N* head, int num){
	if(num <= 1)
		return head;
	
	int i = 1;
	N* temp = head;
	N* current = NULL;
	
	for(; temp->next != NULL; temp = temp->next){
		printf("\ni:%d node:%d\n",i,temp->data);
		if(i == num){
			N* link = temp->next;
			temp->next = NULL;	
			//display(head);
			reverse(&head, head);
			N* temp1 = head;
			
			while(temp1->next != NULL)
				temp1 = temp1->next;
			
			temp1->next = link;
			current = link;
		}
			
			
		if(i % num == 0){
			N* link = temp->next;
			temp->next = NULL;
			reverse(&current, current);
			N* temp1 = current;
			
			while(temp1->next != NULL)
				temp1 = temp1->next;
			
			temp1->next = link;
			current = link;
		}
		
		i++;
	}
	
	return head;
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
	head = insert(head, 6);
	
	display(head);
	
	head = swapN(head, 3);
	//reverse(head, head);
	display(head);
	
	return 0;
}