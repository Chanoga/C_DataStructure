#include "lists.h"

List* head = NULL;
/*
        OPERATIONS
        ---------

        ->Insert node at the beginning of the list(done)
        ->Inser node at the end of the list(node)
        ->Insert node before a given node(done)
        ->Insert node after the given node(done)
        ->Delete any node
        ->Sort list in Ascending order(done)
        ->Sort list in Descending order(done)
        ->Size of the list(done)
        ->find the biggest node in the list(done)
        ->Find the smallest node in the list(done)
        ->Find node in the list(done)
        ->clear list/delete entire list(done)
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
//find the biggest/largest node int he list
int largest_node(List* list)
{
    if(list == NULL) return 0;

    else
    {
        int big_node;
        List *ptr;

        ptr = list;

        big_node = ptr->node;//assuming the first node in the list is the biggest

        while(ptr != NULL)
        {
            big_node = (ptr->node >= big_node) ? ptr->node : big_node;
            ptr = ptr->next;   
        }
        return big_node;
    }
}
//find the smallest node in the list
int smallest_node(List* list)
{
    if(list == NULL) return 0;

    else
    {
        int small_node;
        List *ptr;

        ptr = list;

        small_node = ptr->node;//assuming the first node in the list is the biggest

        while(ptr != NULL)
        {
            small_node = (ptr->node <= small_node) ? ptr->node : small_node;
            ptr = ptr->next;   
        }
        return small_node;
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
//size of the list
unsigned int size(List* list){

    if(list == NULL){
        return 0;
    }
    else{
        unsigned int count = 0;

        while(list != NULL){
            count++;
            list = list ->next;
        }
        return count;
    }
}
//find node in the list
bool find(List* list,int val){
    List *ptr;
    bool b;

    if(list == NULL){
        b = false;
        return b;
    }
    else{
        while(list != NULL && list->next != NULL && list->node != val) list = list->next;
        //we reach the end of the list without findind the node we are looking fore
        if(list ->next == NULL && list->node != val) b = false;
        //the node found
        else b = true;
        return b;
    }

}
//sort list in Ascending order /selection sort Algorithms
void swap(int* i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
List *sort_asc(List* list){

    if(list == NULL)return NULL;

    else
    {
        int *smallestIndex;//pointer to the smallest value in the list

        for(List* ptr = list; ptr != NULL; ptr = ptr->next)
        {
            smallestIndex = &ptr->node;

            for(List* next_ptr = ptr->next;next_ptr != NULL;next_ptr = next_ptr->next)
                if(next_ptr->node <= *smallestIndex)
                    smallestIndex = &next_ptr->node;
                
            
            swap(&ptr->node,smallestIndex);
        }
        return list;
    }
}

//sort list in descending order
List* sort_desc(List* list)
{
     if(list == NULL)return NULL;

    else
    {
        int *smallestIndex;//pointer to the smallest value in the list

        for(List* ptr = list; ptr != NULL; ptr = ptr->next)
        {
            smallestIndex = &ptr->node;

            for(List* next_ptr = ptr->next;next_ptr != NULL;next_ptr = next_ptr->next)
                if(next_ptr->node >= *smallestIndex)
                    smallestIndex = &next_ptr->node;
                
            
            swap(&ptr->node,smallestIndex);
        }
        return list;
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
        9: Sort Ascending Order \n\
        10: Sort Descending Order \n\
        11: Find Largest Node \n\
        12: Find Smallest Node \n\
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
            puts("Enter value");
            scanf("%d",&val);
            (find(head,val) == 1)? puts("True"):puts("false");
            break;

            case 9:
            head = sort_asc(head);
            break;

            case 10:
            head = sort_desc(head);
            break;

            case 11:
            printf("Largest Node: %d\n",largest_node(head));
            break;

            case 12:
            printf("Smallest Node: %d\n",smallest_node(head));
            break;
        }
    }while(opt >=0 && opt < 13);
}