/* Implementation of the binary search tree in C */
#include<stdio.h>
#include<malloc.h>

/*
  Operations
  ----------
  -->Insert node
  -->Post Iterating
  -->Pre order Iterating
  -->In Order iterating
  -->deleting leaf node
  -->deleting node with Two children
  -->deleting node with only one child
  -->deleting root node
*/

//structure for holding up data/nodes
typedef struct BinarySearchTree
{
    int node;
    struct BinarySearchTree *left,*right;//pointers to the left and right of the tree
}Tree;

Tree *root = NULL;//assuming the tree is empty at the time of it's creation

//traversing the tree
void pre_order_traversing(Tree *tree)
{
    if(tree == NULL) return;

    else
    {
        printf("%d->",tree->node);
        pre_order_traversing(tree->left);
        pre_order_traversing(tree->right);
    }
}
//insert node to the tree
Tree *insert_node(Tree* tree,int val){
    Tree *element,*ptr,*tick;

    element = (Tree*)malloc(sizeof(Tree));
    element ->node = val;
    element->left = NULL;
    element->right = NULL;

    //is tree empty...?
    if(tree == NULL){
        tree = element;
        tree->left = tree->right = NULL;
    }
    else
    {
     ptr = tree;
     tick = NULL;

     while(ptr != NULL){
         tick = ptr;

         if(ptr ->node > val) ptr = ptr->left;

         else ptr = ptr->right;
     }

     if(tick->node > val) tick->left = element;
     else tick->right = element;   
    }
    return tree;
}

int main(void)
{
    unsigned short opt;
    int val;

    do
    {
        puts(("\n\
        1: Pre Order traversing \n\
        2: InOrder traversing \n\
        3: Post Order traversing \n\
        4: Insert Node \n\
        "));

        scanf("%hu",&opt);

        switch(opt)
        {
            case 1:
            pre_order_traversing(root);
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            puts("Enter value");
            scanf("%d",&val);
            root = insert_node(root,val);
            break;
        }
    } while (opt > 0 && opt < 5);
    
}