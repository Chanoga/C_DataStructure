#include "lists.h"

List* head = NULL;

//display list
void display(List* list){
    if(list == NULL)return;

    else{
        while(list != NULL){
            printf("%d->",list->node);
            list = list->next;
        }
    }
}
//insert node at the beginning of the list
List* insert_beg(List* list,int val){

    List *element;

    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL){
        list = element;
        list ->next = list ->prev = NULL;
    }

    else{
        element ->next = list;//new node points to the first node in the list
        list ->prev = element;//the first node in the list point back to the newly node
        list = element;//update list to point to the newly node
    }
    return list;
}

//insert nodes at the end of the list
List* insert_end(List* list,int val){
    List *element,*ptr;

    element = (List*)malloc(sizeof(List));
    element->node = val;

    if(list == NULL){
        list = element;
        list->next = list->prev = NULL;
    }
    else{
        ptr = list;//now ptr point to the list(first node in the list)
        
        //keep going until you reach the end of the list
        while(ptr->next!= NULL) ptr = ptr->next;

        ptr ->next = element;
        element->prev = ptr;
        ptr = element;
        element->next = NULL;
    }
    return list;
}

//has a bug when trying to insert node before the last node for the second time
//insert node before a given node
List* insert_bef(List* list,int val,unsigned int pos){
    List *element,*prevP,*nextP;

    element = (List*)malloc(sizeof(list));
    element ->node = val;

    //list empty..? yes make this the first element
    if(list == NULL){
        list = element;
        element->next = list->prev = NULL;
    }
    else
    {
          prevP = list;

        if(prevP ->node == pos){
            element ->next = prevP;
            prevP ->prev = element;
            prevP = element;

            list  = prevP;
        }
        else
        {
             prevP = list;
            nextP = prevP->next;

            while(nextP != NULL && nextP->node != pos){
                prevP = nextP;
                nextP = nextP->next;
            }

            prevP->next = element;
            element ->prev = prevP;
            element->next = nextP;
            nextP ->prev = element;
            prevP = element;

            //debugin
            printf(("\
            prevP[%p][%d]\
            element[%p][%d]\
            nextP[%p][%d]\
            prevP->next[%p]\
            element->next[%p]\
            nextP->prev[%p]\
            element->prev[%p]\n\
            "),prevP,prevP->node,
            element,element->node,
            nextP,nextP->node,
            prevP->next,element->next,nextP->prev,element->prev,prevP);
        }

    }
        return list;
}
//the main function
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
            // puts("Enter Insertion point(node to be inserted after)");
            // scanf("%u",&pos);
            // puts("Enter value");
            // scanf("%d",&val);
            // head = insert_aft(head,val,pos);
            break;

            case 5:
            // head = clear(head);
            break;

            case 6:
            // puts("Enter node to delete");
            // scanf("%d",&val);
            // head = delete_node(head,val);
            break;

            case 7:
            // printf("Size of List: %d",size(head));
            break;

            case 8:
            // puts("Enter value");
            // scanf("%d",&val);
            // (find(head,val) == 1)? puts("True"):puts("false");
            break;
        }
    }while(opt >=0 && opt < 4);
}