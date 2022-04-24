#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *root = NULL;
node *insert(node *tree, long num);
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);
int count = 1;
void main()
{
    long digit;
    int s;
    do
    {
        printf("\n1:Insert a node in the Binary Tree");
        printf("\n2: Display the preorder of the Binary Tree");
        printf("\n3: Display the inorder of the Binary Tree");
        printf("\n4: Display the postorder of the Binary Tree");
        printf("\n5: Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            printf("Enter integers- To quit enter 0 : ");
            scanf("%ld", &digit);
            while (digit != 0)
            {
                root = insert(root, digit);
                scanf("%ld", &digit);
            }
            continue;
        case 2:
            printf("\n Preorder traversing TREE :");
            preorder(root);
            continue;
        case 3:
            printf("\n Inorder traversing TREE : ");
            inorder(root);
            continue;
            printf("\n Inorder traversing TREE : ");
            inorder(root);
            continue;
        case 4:
            printf("\n Postorder traversing TREE : ");
            postorder(root);
            continue;
        case 5:
            printf("END");
            exit(0);
        }
    } while (s != 5);
}
node *insert(node *p, long digit)
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->left = p->right = NULL;
        p->num = digit;
        count++;
    }
    else if (count % 2 == 0)
        p->left = insert(p->left, digit);
    else
        p->right = insert(p->right, digit);
    return (p);
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