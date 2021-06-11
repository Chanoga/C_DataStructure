//the main function
#include "lists.h"

extern void singly_linked_list_option(List *);

List *head = NULL;

int main(void){

    unsigned short opt;

    do{
        puts("\n0: Singly Linked \n1: Circular Singly Linked\n2: Doubly Linked\n3: Doubly Circular Linked\n");
        scanf("%hu",&opt);

        if(opt == 0){
            singly_linked_list_option(head);
        }
    }while(opt >= 0 && opt < 4);

    return 0;
}