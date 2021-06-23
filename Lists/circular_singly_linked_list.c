#include "lists.h"
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
List *head = NULL;

//display list nodes
void display(List* list){
    List *ptr;

    if(list == NULL)return;
    else
    {
        ptr = list;
        while(ptr->next != list){
            printf("%d->",ptr->node);
            ptr = ptr->next;
        }
         printf("%d->",ptr->node);//print the last node as ptr->next will breack when it equal list
    }
}
//insert node at the beginning of the list
List *insert_beg(List* list,int val){
    List *element,*ptr;

    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL){
        list = element;
        list->next = element;//point back to the list head(that is why it is called circular)
    }
    else
    {
        ptr = list; //now ptr point to the first node in the list
        
        while(ptr->next != list){
            ptr = ptr->next;
        }
        element ->next = list;
        list = element;
        ptr->next = list;

        //for debugin uncoment printf to see the what is going on for better understanding
        // printf(("\
        // ptr[%p][%d] \
        // element->next[%p] \
        // element[%p][%d] \
        // list->next[%p] \
        // list[%p][%d] \
        // ptr->next[%p] \n\
        // "),ptr,ptr->node,element->next,element,element->node,list->next,list,list->node,ptr->next);
    }
    return list;
}

//insert node at the end of the list
List* insert_end(List* list,int val){
    List *element;

    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL){
        list = element;
        element->next = list;
    }
    else
    {
        List* ptr;
        ptr = list;
        while(ptr -> next != list){
            ptr = ptr->next;
        }
        ptr->next = element;
        element->next = list;//always point back to the list head
        ptr = element;
        
        //debuging reasons
        // printf(("\
        // list[%p][%d] \
        // ptr[%p][%d] \
        // element[%p][%d] \
        // ptr->next[%p] \
        // element->next[%p] \
        // ptr=element[%p] \n\
        // "),list,list->node,ptr,ptr->node,element,element->node,ptr->next,element->next,ptr);
    }
    return list;
}
//insert node before a given node
List* insert_bef(List* list,int val,unsigned int pos){

    List *element,*prevP,*nextP;

    element = (List*)calloc(1,sizeof(List));
    element->node = val;
    //dont allow the node to be inserted if the list is empty
    if(list == NULL){
        puts("Empty List exiting...");
        return NULL;
    }
    else
    {
        prevP = list;
        //do we want to insert at the beginning of the list..?
        if(prevP -> node == pos){
            list = insert_beg(list,element->node);
        }
        else
        {
            nextP = prevP->next;
            while(nextP != list && nextP->node != pos){
                prevP = nextP;
                nextP = nextP->next;
            }
            prevP ->next = element;
            element->next = nextP;
            prevP = element;
        }
        return list;
    }   
}
//insert node after a given node
List* insert_aft(List* list,int val,unsigned int pos){
    List *element,*prevP,*nextP;

    element = (List*)malloc(sizeof(List));
    element->node = val;

    if(list == NULL){
        puts("Empty list");
        return list;
    }
    else
    {
        prevP = list;
        nextP = prevP->next;

        while(prevP -> next != list && prevP ->node != pos){
            prevP = nextP;
            nextP = nextP->next;
        }

        prevP->next = element;
        element->next = nextP;
        prevP = element;

        return list;
    }
}

//error it return garbage values
//clear list/delete all the elements/node in the list
List *clear(List* list){

    List *temp,*p;
    if(list == NULL)return list;

    else{
        p = list;
        while(p->next != list){
            temp = p;
            free(temp);
            p = p->next;
        }
        free(p);
        return list;
    }
}
//failing to delete the first node from the list
//delete a given node from the list
List *delete_node(List* list,int val){
    List *ptr,*prevP,*temp;

    if(list == NULL) return list;

    else{

        ptr = list;
        prevP = ptr;
        while(ptr->node != val && ptr->next != list){
            prevP = ptr;
            ptr = ptr->next;
        }
        //we reached at the end of the list without finding out value
        if(ptr->next == list && ptr->node != val)puts("No value found");
        //value found
        else{
            temp = ptr;
            ptr = ptr->next;
            prevP->next = ptr;
            free(temp);
        }
        return list;
    }
}

//return the size of the list
unsigned int size(List* list){

    if(list == NULL)return 0;
    else{
        List *p = list;
        unsigned int counter = 1;//there is always a value
        while(p->next != list){
            counter++;
            p = p->next;
        }
        return counter;
    }
}
 int main (void){
     unsigned short opt;
     unsigned int pos;
    int val;
    bool b;

    do{
        fputs(("\n\
        0: Display \n\
        1: Insert Beginning \n\
        2: Insert End \n\
        3: Insert Before a given node\n\
        4: Insert After a given node\n\
        5: Clear \n\
        6: Delete node\n\
        7: size \n\
        8: find node \n\
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

            case 7:
            printf("Size of List: %d",size(head));
            break;

            case 8:
            // puts("Enter value");
            // scanf("%d",&val);
            // (find(head,val) == 1)? puts("True"):puts("false");
            break;
        }
    }while(opt >=0 && opt < 9);
}