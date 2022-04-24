#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *p = NULL;
node *delnum(int digit, node *root);
node *delte_node(int digit, node *root);
node *insert(node *tree, long num);
void search(node *p, int num);
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);
void main()
{
    int digit, dig;
    int s, n, i;
    do
    {
        printf("\n1: Insert a node in the Binary search Tree");
        printf("\n2: Search an element in Binary search Tree");
        printf("\n3: Display preorder traversal of Binary search Tree");
        printf("\n4: Display inorder traversal of Binary search Tree");
        printf("\n5: Display postorder traversal of Binary search Tree");
        printf("\n6: Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &digit);
                p = insert(p, digit);
            }
            continue;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &dig);
            search(p, dig);
            continue;
        case 3:
            printf("\n Preorder traversing TREE: \n");
            preorder(p);
            continue;
        case 4:
            printf("\n Inorder traversing TREE:\n");
            inorder(p);
            continue;
            printf("\n Inorder traversing TREE");
            inorder(p);
            continue;
        case 5:
            printf("\n Postorder traversing TREE:\n");
            postorder(p);
            continue;
        case 6:
            printf("END");
            exit(0);
        }
    } while (s != 6);
}
node *insert(node *p, long digit)
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->left = p->right = NULL;
        p->num = digit;
    }
    else if (digit < p->num)
        p->left = insert(p->left, digit);
    else if (digit > p->num)
        p->right = insert(p->right, digit);
    else if (digit == p->num)
    {
        printf("duplicate key");
    }
    return (p);
}
void search(node *p, int digit)
{
    if (p == NULL)
        printf("Element does not exist");
    else if (digit == p->num)
        printf("Element present\n");
    else if (digit < p->num)
        search(p->left, digit);
    else
        search(p->right, digit);
}
void preorder(node *p)
{
    if (p != NULL)
    {
        printf("%d\n", p->num);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\n", p->num);
        inorder(p->right);
    }
}
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\n", p->num);
    }
}