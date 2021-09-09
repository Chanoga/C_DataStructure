/**
 *      STACK
 *      -----
 * Definition:
 * A stack is a linear data structure which stores elements in an ordered manner,with the
 * first element to be inserted will be the last one to be removed from the stack.
 */
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
extern void array_implementation(void);

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
            array_implementation();
            break;

            case 2:
           linked_list_implementation();
            break;
        }
    }while(opt > 0 && opt < 3);

    return 0;
}

