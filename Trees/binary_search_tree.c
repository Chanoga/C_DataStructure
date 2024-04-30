/**
 * 				BINARY SEARCH TREE/ORDERED BINARY TREE
 * 				-------------------------------------
 *
 * 			def:
 * 				Is a variant of binary trees in which nodes are arranged in orders.
 *
 * 			In binary search tree, all nodes in the left subtree are less than a root node.
 * 			Correspondingly all nodes in the right subtree are either equal or greater than
 * 			root node. The same rule is applied to every subtree in the tree.
 *
 *
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
 * -->Search node in the tree
 * -->Delete an entire tree
 * -->Delete leaf node
 * -->Delete a node with only one child
 * -->Delete a Node with children
 */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct btree{
	int node;
	struct btree *left,*right;
};

struct btree* root = NULL;/* tree is initially empty */

/* pre-order traversing*/
void pre_order(struct btree *tree){

	if(tree == NULL) return;

	else if(tree != NULL){
		fprintf(stdout,"%d -> ",tree -> node);
		pre_order(tree -> left);
		pre_order(tree -> right);
	}
}

/*in-order */
void in_order(struct btree* tree){

	if(tree != NULL){
		in_order(tree -> left);
		fprintf(stdout,"%d ->",tree -> node);
		in_order(tree -> right);
	}
}


/*post-order */
void post_order(struct btree* tree){

	if(tree != NULL){
		post_order(tree -> left);
		post_order(tree -> right);
		fprintf(stdout,"%d ->",tree -> node);
	}
}
/*insert node*/
struct btree *ins_node(struct btree *tree,int val){
	struct btree *ptr,*nptr,*prvptr;

	ptr = (struct btree*)malloc(sizeof(struct btree));

	ptr -> node = val;

	/*if tree is empty, our node is the root node*/
	if(tree == NULL){
		tree = ptr;
		tree -> left = tree->right = NULL;
	}

	/*tree is not empty*/
	else{
		nptr = tree;

		while(nptr != NULL){
			prvptr = nptr;

			nptr = (nptr -> node > val)? nptr -> left : nptr -> right;

		}

		if(prvptr -> node > val) prvptr -> left = ptr;

		else if( prvptr -> node <= val) prvptr -> right = ptr;

	}

	return tree;
}

/*find smallest node*/
struct btree *sm_node(struct btree *tree){

	if((tree == NULL) || (tree -> left == NULL)) return tree;

	else return sm_node(tree -> left);
}

/*find largest node */
struct btree* ls_node(struct btree *tree){

	if((tree == NULL) || tree -> right == NULL) return tree;

	else return ls_node(tree -> right);

}

/*search node */
int  s_node(struct btree *tree,int val){

	struct btree* ptr,*nptr;

	if(tree == NULL) return -1;

	else{
		ptr = tree;
		nptr = ((ptr -> node > val) && (ptr -> node != val))? sm_node(ptr) : ls_node(ptr);

		/*value equal root node*/
		if(ptr -> node == val)
			return ptr -> node;

		if(nptr -> node == val)
			return nptr -> node;

		else{
			return -1;
		}
	}
}

/*mirror tree*/
struct btree* mirror(struct btree *tree){
	struct btree *ptr;

	if(tree!=NULL){
		mirror(tree ->left);
		mirror(tree ->right);
		ptr=tree ->left;
		ptr ->left = ptr ->right;
		tree ->right = ptr;

		return tree;
	}
}

/*delete entire tree*/
struct btree* del_tree(struct btree *tree){
	if(tree != NULL){
		del_tree(tree -> left);
		del_tree(tree -> right);
		free(tree);
	}

	return NULL;
}
int main(void)
{
    unsigned short opt;
    int val;
    char *instructions ="1: pre-order \n"
	    		"2: in-order \n"
			"3: post-order \n"
			"4: insert node \n"
			"5: smallest node\n"
			"6: Largest node\n"
			"7: Search node\n"
			"8: Mirror \n"
			"9: Delete tree\n"
			"0: quit\n";

    do
    {
	printf("\n%s\n",instructions);
        scanf("%hu",&opt);

        switch(opt)
        {
		case 0:
			break;
            case 1:
             pre_order(root);
            break;

            case 2:
	    in_order(root);
	    break;
            case 3:
	    post_order(root);
            break;

            case 4:
            puts("Enter Value");
            scanf("%d",&val);
            root = ins_node(root,val);
            break;

	    case 5:
	    printf("Smallest Node: %d\n",sm_node(root)->node);
	    break;

	    case 6:
	    printf("Largest Node: %d\n",ls_node(root) -> node);
	    break;

	    case 7:
	    puts("Enter search value");
	    scanf("%d",&val);
	    val = s_node(root,val);
	    if(val == -1) printf("Not Found: %d\n",val);

	    else printf("Found: %d\n",val);
	    break;

	    case 8:
	    root = mirror(root);
	    break;

	    case 9:
	    root = del_tree(root);
	    break;
        }
    } while (opt > 0 && opt < 10);
    
    return 0;
}
