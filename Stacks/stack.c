//The following is an implementation of the stack data structure in C
//language using both array and linked list
/**
 *  OPERATIONS
 * ----------
 * 
 * ->Insert node(node always are inserted at the top of the stack)
 * ->Pop node (remove the last node from stack,the last node is always removed first)
 * ->Peek node (return the last node in the stack)
 */
#include<stdio.h>
extern void linked_list_implementation(void);

int main(int argc, char const *argv[])
{
    unsigned short opt;

    do{
        puts(("\
        1: Array Impelementation\n\
        2: Linked list implementation\n\
        "));
        scanf("%hu",&opt);

        switch(opt){

            case 1:
            //array_implementation();
            break;

            case 2:
            linked_list_implementation();
            break;
        }
    }while(opt > 0 && opt < 3);

    return 0;
}

