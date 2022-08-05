#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct Node{
	Node* next;
	int data;
};

struct Queue{
	Node* head;
	int length;
};

Node* khoiTaoMotNodeMoi(int value)
{
	Node *temp;  // khoi tao 1 Node
	temp = new Node(); // cap phat du lieu cho Node
	temp -> next = NULL; // Gan con tro next = NULL
	temp -> data = value; // Gan gia tri cho Node
	
	return temp; // Tra ve gia tri cua Node vua tao
}

Queue* khoiTaoQueue()
{
	Queue* queue = new Queue();
	queue -> head = NULL;
	return queue;
}


void duyetQueue(Queue* const queue)
{
    for(Node* p = queue -> head; p != NULL; p = p->next){
        printf("%d  ", p->data);
    }
}

void enqueue(Queue* queue, int value)
{
	Node* temp, *p;
	temp = khoiTaoMotNodeMoi(value); 
	if(queue -> head == NULL)
	{
		queue -> head = temp;	
		queue -> length++;
	}
	else 
	{
		p = queue -> head; 
		while(p -> next != NULL) 
		{
			p = p -> next;
		}	
		p -> next = temp;
		queue -> length++;
	}	
}

int dequeue(Queue* queue)
{
	Node* result = queue -> head;
	if(queue -> head == NULL)
	{
		return 0 ;
	}
	else
	{
		queue -> head = queue -> head -> next;
		queue -> length--;
	}
	return result -> data;
}

int front(Queue* queue)
{
	return queue -> head -> data;
}
int main()
{
	Queue* queue = khoiTaoQueue();
	enqueue(queue,9);
	enqueue(queue,10);
	enqueue(queue,8);
	enqueue(queue,100);
	duyetQueue(queue);
	printf("\n");
	printf("%d", front(queue));
	printf("\n");
	dequeue(queue);
	duyetQueue(queue);
	printf("\n");
	printf("%d", dequeue(queue));
	printf("\n");
	printf("%d", queue -> length);
	
	return 0;
}
