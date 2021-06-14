#include "lists.h"

List* head = NULL;
/*
        OPERATIONS
        ---------

        ->Insert node at the beginning of the list
        ->Inser node at the end of the list
        ->Insert node before a given node
        ->Insert node after the given node
        ->Delete any node
        ->Sort list in Ascending order
        ->Sort list in Descending order
        ->Size of the list
        ->find the biggest node in the list
        ->Find the smallest node in the list
        ->Find node in the list
        ->clear list/delete entire list
*/
//display list nodes
void display(List* list){
    if(list == NULL){
        puts("Empty List");
    }
    else{
        while(list!= NULL){
            printf("%d->",list->node);
            list = list->next;
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
    List *element,*prevP,*nextP;

    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL){
        list = element;
        element ->next = NULL;
    }

    else
    {
        prevP = list;
        nextP = prevP->next;

        //check if the insertion point is the first node in the list
        if(prevP ->node == pos){
            element ->next = prevP;//element points to the first node of the list
            prevP = element;//prevP points to the newly inserted element/node
            nextP = prevP->next;//nextP points to the second node in the list after insertion
            list = prevP;//make list point back to the beginning of the list
        }
        while(nextP!= NULL && nextP ->node != pos){
            prevP = nextP;
            nextP = nextP->next;
        }
        prevP ->next  = element;
        element->next = nextP;
        prevP = element;
        //    //debuging reasons only
        // printf(("\
        // prevP[%p][%d]  \
        // prevP->next[%p] \
        // element[%p][%d]  \
        // element->next[%p] \
        // nextP[%p][%d] \
        // nextP->next[%p] \n\
        // "),prevP,
        // prevP->node,
        // prevP->next,
        // element,element->node
        // ,element->next,nextP,nextP->node,nextP->next);
    }
    return list;
}

//insert node after a given node
List* insert_aft(List* list,int val,unsigned int pos){
    List *element,*prevP,*nextP;

    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL)
    {
        list = element;
        element->next = NULL;
    }
    else
    {
        prevP = list;
        nextP = prevP ->next;

        while(prevP != NULL && prevP ->node != pos){
            prevP = nextP;
            nextP = nextP->next;
        }
        prevP ->next = element;
        element ->next = nextP;
        prevP = element;
    }
    return list;
}

//delete an entire list
List *clear(List* list){
    List *tmp;
    if(list != NULL)
    {
        while(list != NULL) list = list->next;

        tmp = list;
        free(tmp);//remove node from the heap
    }
    else puts("The list is alread Empty: ");
    return list;
}

//delete a single given node from the list (bug on deleting first or last node)
List* delete_node(List* list,int val){
    List *ptr,*temp,*prevP;
    if(list == NULL){
        puts("Empty list,nothing to delete");
        return NULL;
    }
    else{
        prevP = list;
        ptr = list->next;

        //if the node is the first node in the list
        if(prevP->node == val){
            temp = prevP;
            prevP = prevP->next;
            free(temp);
        }
        else{
            while(ptr->node != val && ptr->next != NULL) 
            {
                prevP = ptr;
                ptr = ptr->next;
            }
            //is our node the last node ..?
            if(ptr->next == NULL){
                temp = ptr;
                prevP ->next = NULL; //prevP now point to the last node
                free(temp);
            }
            temp = ptr;
            ptr = ptr->next;
            prevP ->next = ptr;
            free(temp);
        }
        return list;
    }
}
 int main (void){
     unsigned short opt;
     unsigned int pos;
    int val;

    do{
        fputs(("\
        0: Display \n\
        1: Insert Beginning \n\
        2: Insert End \n\
        3: Insert Before a given node\n\
        4: Insert After a given node\n\
        5: Clear \n\
        6: Delete node\n\
        "),stdout);
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

            case 4:
            puts("Enter Insertion point(node to be inserted after)");
            scanf("%u",&pos);
            puts("Enter value");
            scanf("%d",&val);
            head = insert_aft(head,val,pos);
            break;

            case 5:
            head = clear(head);
            break;

            case 6:
            puts("Enter node to delete");
            scanf("%d",&val);
            head = delete_node(head,val);
            break;
        }
    }while(opt >=0 && opt <7);
}