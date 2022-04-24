#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;
void insert(int item);
int del();
int peek();
int isEmpty();
void display();
int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display the element at the front");
        printf("\n4.Display queue elements");
        printf("\n5.Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("\nDeleted element = %d\n", del());
            break;
        case 3:
            printf("\nElement at the front of the queue = %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
    }
}

void insert(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("\nMemory not available\n");
        return;
    }
    tmp->info = item;
    tmp->link = NULL;
    if (front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

int del()
{
    struct node *tmp;
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    tmp = front;
    item = tmp->info;
    front = front->link;
    free(tmp);
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return front->info;
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements :\n\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n\n");
}