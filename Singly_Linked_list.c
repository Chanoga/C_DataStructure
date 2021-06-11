#include "lists.h"

/*
        OPERATIONS
        ---------

        ->Insert node at the beginning of the list
        ->Inser node at the end of the list
        ->Insert node before a given node
        ->Insert node after the given node
        ->Delete first node
        ->Delete any node
        ->Sort list in Ascending order
        ->Sort list in Descending order
        ->Size of the list
        ->find the biggest node in the list
        ->Find the smallest node in the list
        ->Find node in the list
*/
//display list nodes
void display(List* list){
    if(list == NULL){
        puts("Empty List");
    }
    else{
        printf("%d->",list->node);//print the first node in the list
        while((list = list->next) != NULL){
            printf("%d->",list->node);
        }
    }
}
//insert node at the begginind of the list
List *insert_beg(List* list,int val){
    List *elem;

    elem = (List*)malloc(sizeof(List));

    elem ->node = val;

    if(list == NULL){
        list = elem;
        list->next = NULL;//don't point to any other node
    }
    else{
        elem -> next = list;//new node point to the first node in the list
        list = elem;//move list to point to the new inserted node
    }
    return list;
}

//insert node at the end of the list
List* insert_end(List *list,int val){
     List *elem,*ptr;

    elem = (List*)malloc(sizeof(List));

    elem ->node = val;

    if(list == NULL){
        list = elem;
        list->next = NULL;//don't point to any other node
    }
    else{
        ptr = list;
        while(ptr->next != NULL)ptr = ptr->next;

        ptr->next = elem;
        ptr = elem;
        elem -> next = NULL;
    }
    return list;
}

//insert node before a given node
List* insert_bef(List *list,int val,unsigned int pos){
    List *element,*prevP,*nextP,*temp;

    if(list == NULL){
        list = element;
        list ->next = NULL;
    }

    else
    {
        prevP = list;
        nextP = prevP->next;

        while(nextP ->next != NULL && nextP->node != pos){
            prevP = nextP;
            nextP = nextP->next;
        }

        prevP ->next = element;
        element ->next = nextP;
        prevP = element;
        nextP = nextP ->next;
    }
    return list;
}
 void singly_linked_list_option(List* head){
     unsigned short opt;
     unsigned int pos;
    int val;

    do{
        puts("\n0: Display\n1: Insert_bed\n2: Insert_end\n3: Insert Before\n");
        scanf("%hu",&opt);

        switch(opt){
            
            case 0:
            display(head);
            break;

            case 1:
            puts("Enter value");
            scanf("%d",&val);
            head = insert_beg(head,val);
            break;

            case 2:
            puts("Enter value");
            scanf("%d",&val);
            head = insert_end(head,val);
            break;

            case 3:
            puts("Enter Insertion point(node to be inserted before)");
            scanf("%u",&pos);
            puts("Enter value");
            scanf("%d",&val);
            head = insert_bef(head,val,pos);
            break;
        }
    }while(opt >=0 && opt <4);
}