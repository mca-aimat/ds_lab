#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int data;
    struct linklist *next;
} node;

int n;
node *ptr, *t, *ptr1;

void traverse();
void insert_speci();
void delete_speci();

void main()
{
    int choice, i;
    printf("\n\n\t\tSINGLY LINKLIST OPERATIONS\n");
    printf("\t\t=============================\n");
    printf("Enter number of node to be created : ");
    scanf("%d", &n);
    ptr = (node *)malloc(sizeof(node));
    t = ptr;
    printf("Enter the data to linklist:");
    scanf("%d", &ptr->data);
    for (i = 1; i < n; i++)
    {
        ptr->next = (node *)malloc(sizeof(node));
        ptr = ptr->next;
        scanf("%d", &ptr->data);
    }
    ptr->next = NULL;
    printf("INSERTED !\n\n");
    do
    {
        printf("\n\n1.Insert after specified node\n");
        printf("2.Delete specified node\n");
        printf("3.Traverse\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_speci();
            break;
        case 2:
            delete_speci();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 7 || choice == 0);
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
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insert_speci()
{
    int speci_pos, i;
    ptr1 = (node *)malloc(sizeof(node));
    printf("Enter the data to new node:");
    scanf("%d", &ptr1->data);
    printf("Enter the position after which the new node to be inserted: ");
    scanf("%d", &speci_pos);
    ptr = t;
    if (speci_pos <= n)
    {
        for (i = 1; i < speci_pos; i++)
        {
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        ptr->next = ptr1;
        printf("INSERTED !");
    }
}
void delete_speci()
{
    int dele_node, i;
    printf("Enter the position after which the node to be deleted :");
    scanf("%d", &dele_node);
    if (dele_node <= n)
    {
        ptr = t;
        for (i = 1; i <= dele_node; i++)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        printf("No deleted is = %d !", ptr->data);
        ptr1->next = ptr->next;
        free(ptr);
    }
    else
    {
        printf("key not found");
    }
}
