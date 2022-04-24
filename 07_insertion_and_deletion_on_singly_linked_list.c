#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int data;
    struct linklist *next;
} node;

void create_node();
void traverse();
void insert_begi();
void insert_end();
void dele_begi();
void dele_end();
node *ptr, *t, *ptr1;

void main()
{
    int choice;
    printf("\nSINGLY LINKLIST OPERATIONS\n");
    printf("\n=============================\n");
    printf("Create first node\n");
    printf("-----------------\n");
    create_node();
    do
    {
        printf("\n=============================\n");
        printf("\n\n1.Insert at beginning\n");
        printf("2.Insert at end \n");
        printf("3.Deletion at beginning\n");
        printf("4.Deletion at end\n");
        printf("5.Traverse\n");
        printf("6.Exit\n");
        printf("\n=============================\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_begi();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            dele_begi();
            break;
        case 4:
            dele_end();
            break;
        case 5:
            traverse();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 7 || choice == 0);
}
void create_node()
{
    ptr = (node *)malloc(sizeof(node));
    t = ptr;
    printf("Enter the data to new node:");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
}
void traverse()
{
    ptr = t;
    if (ptr == NULL)
    {
        printf("\nList is empty !\n");
    }
    else
    {
        printf("\nList is :!\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insert_begi()
{
    ptr1 = (node *)malloc(sizeof(node));
    printf("Enter the data to new node:");
    scanf("%d", &ptr1->data);
    ptr1->next = t;
    t = ptr1;
    printf("INSERTED !");
}
void insert_end()
{
    ptr1 = (node *)malloc(sizeof(node));
    printf("Enter the data to new node:");
    scanf("%d", &ptr1->data);
    ptr = t;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr1;
    ptr1->next = NULL;
    printf("INSERTED !");
}
void dele_begi()
{
    ptr = t;
    if (ptr == NULL)
    {
        printf("\nList is empty !\n");
    }
    else
    {
        t = ptr->next;
        free(ptr);
    }
    printf("DELETED !");
}
void dele_end()
{
    ptr = t;
    if (ptr == NULL)
    {
        printf("\nList is empty !\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        ptr1->next = NULL;
    }
    printf("DELETED !");
}
