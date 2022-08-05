#include <stdio.h>
#include <stdlib.h>

struct Node
{
	Node* next;
	Node* prev;
	int data;
};

struct Stack
{
	Node* head; 
	Node* tail;
	int length = 0;
};

Node* khoiTaoMotNodeMoi(int value)
{
	Node *newNode;
	newNode = new Node();
	newNode -> data = value;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	
	return newNode;
}

Stack* khoiTaoMotStack()
{
	Stack* stack = new Stack();
	stack -> head = NULL;
	stack -> tail = NULL;
	return stack;
}

void push(Stack* stack, int value)
{
	Node* newNode = khoiTaoMotNodeMoi(value);
	if(stack -> head == NULL)
	{
		stack -> head = newNode;
		stack -> tail = newNode;
		stack -> length++;
	}
	else
	{
		stack -> tail -> next = newNode;
		newNode -> prev = stack -> tail;
		stack -> tail = newNode;
		stack -> length++;	
	}
}

int pop(Stack* stack)
{
	Node* result = stack -> tail;
	if(stack -> head == NULL)
	{
		return 0;
	}
	else
	{
		stack -> tail = stack -> tail -> prev;
		stack -> tail -> next = NULL;
		stack -> length--;	
	}
	return result -> data;
}

int peak(Stack* stack)
{
	return stack -> tail -> data;
}

void duyetStack(Stack* const stack) 
{
    for(Node* p = stack -> head; p != NULL; p = p->next)
	{
        printf("%d ", p->data);
    }
}

int main()
{
	Stack* stack = khoiTaoMotStack();
	push(stack,9);
	push(stack,10);
	push(stack,8);
	push(stack,100);
	duyetStack(stack);
	printf("\n");
	printf("%d", peak(stack));
	printf("\n");
	pop(stack);
	duyetStack(stack);
	printf("\n");
	printf("%d", pop(stack));
	printf("\n");
	printf("%d", stack -> length);

	return 0;
}