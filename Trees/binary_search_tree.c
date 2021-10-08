/**
 * Implementation of the Binary Search Tree:
 * 
 * Operations:
 * 
 * -->Insert node 
 * -->Pre-Order Traversing
 * -->In-Order Traversing
 * -->Post-Order Traversing
 * -->Mirror Tree
 * -->Find the largest Node
 * -->Find the smallest Node
 * -->Find if a given node is in the tree
 * -->Delete an entire tree
 * -->Delete leaf node
 * -->Delete a node with only one child
 * -->Delete a Node with children
 */

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinarySearchTree{
    
    struct Node
    {
        int age;
        char fname[30];
        char lname[30];
    }node;

    struct BinarySearchTree *left,*right;

}Tree;

Tree *root = NULL;

void pre_order(Tree *tree)
{
    if(tree == NULL) return;

    else{
        printf(("\t \
        %s \t |\
        %s \t |\
        %d \t |\n\
        "),tree->node.fname,tree->node.lname,tree->node.age);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

Tree *insert(Tree *tree,char* fname,char* lname,int age)
{
    Tree* elem,*ptr,*node_ptr;

    elem = (Tree*)malloc(sizeof(Tree));
    strcpy(elem->node.fname,fname);
    strcpy(elem->node.lname,lname);
    elem->node.age = age;
    elem->left = NULL;
    elem->right = NULL;

    if(tree == NULL)
    {
        tree = elem;
        tree->left = NULL;
        tree->right = NULL;
    }

    else
    {
        node_ptr = NULL;
        ptr = tree;

        while(ptr != NULL)
        {
            node_ptr = ptr;

            ptr = (ptr->node.age > age)? ptr->left:ptr->right;
        }
        if(node_ptr->node.age > age) node_ptr->left = elem;

        else node_ptr->right = elem;
    }

    return tree;
}
int main(void)
{
    unsigned short opt;
    struct Node *n;
    char fname[30],lname[30];
    int age;
    do
    {
        puts(("\n \
        1: Pre-Order Traverse \n\
        2: In-Order Traverse \n\
        3: Post-Order Traverse \n\
        4: Insert Node \n\
        "));

        scanf("%hu",&opt);

        switch(opt)
        {
            case 1:
             pre_order(root);
            break;

            case 2:
            case 3:
            break;

            case 4:
            puts("Enter first name");
            scanf("%s",fname);
            puts("Enter last name");
            scanf("%s",lname);
            puts("Enter age");
            scanf("%d",&age);
            root = insert(root,fname,lname,age);
            break;
        }
    } while (opt > 0 && opt < 5);
    
    return 0;
}