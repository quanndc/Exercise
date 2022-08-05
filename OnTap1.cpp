#include <stdio.h>

struct Node
{
    int data;
    Node *next;
};


struct LinkedList
{
    Node *head;
    Node *tail;
    int length = 0;
};

LinkedList* createList()
{
    LinkedList *list = new LinkedList;
    list->head =  NULL;
    list ->tail = NULL;

    return list;
}

Node *createNode(int data)
{
    Node *newNode = new Node;
    if(newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void AddHead(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if(list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->length++;
}

void addTail(LinkedList *list, int data)
{
    Node* newNode = createNode(data);
    list->tail->next = newNode;
    list->tail = newNode;
    list->length++;
}

void deleteHead(LinkedList *list)
{
    list->head = list->head->next;
}

void deleteNode(LinkedList *list, int data)
{
    Node *p = NULL;
    Node *prev = NULL;
    while(p->next!=NULL)
    {
        if(p->data == data)
        {
            if(prev==NULL)
            {
                list->head = list->head->next;
                delete p;
                return;
            }
            prev->next = p->next;
            delete p;
            return;
        }
        prev=p;
        p=p->next;
    }
    list->length--;
}

int countLengthList(LinkedList *list)
{
    return list->length;
}

void duyetList(LinkedList *list)
{
    for(Node* p=list->head;p!=NULL;p=p->next)
    {
        printf("%d  ", p->data);
    }
}

int main()
{
    LinkedList *list = createList();
    AddHead(list,4);
    addTail(list,1);
    addTail(list,2);
    addTail(list,3);
    duyetList(list);
    printf("%d", countLengthList(list));


}