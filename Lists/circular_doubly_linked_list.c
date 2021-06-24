 #include "lists.h"

 /**    OPERATIONS:
  * Same as that of all lists
  */

 List *head = NULL;

 //insert node at the beginning of the list
 List* insert_beg(List* list,int val){

     List* element = (List*)malloc(sizeof(List));
     element->node = val;

     if(list==NULL){
         list = element;
         element->next = list;
         list->prev = element;
     }
     else{
         element->next = list;
         list->prev = element;
         list = element;
     }

     return list;
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
            // display(head);
            break;

            case 1:
            puts("Enter value");
            scanf("%d",&val);
            head = insert_beg(head,val);
            break;

            case 2:
            // puts("Enter value");
            // scanf("%d",&val);
            // head = insert_end(head,val);
            break;

            case 3:
            // puts("Enter Insertion point(node to be inserted before)");
            // scanf("%u",&pos);
            // puts("Enter value");
            // scanf("%d",&val);
            // head = insert_bef(head,val,pos);
            break;

            case 4:
            // puts("Enter Insertion point(node to be inserted after)");
            // scanf("%u",&pos);
            // puts("Enter value");
            // scanf("%d",&val);
            // head = insert_aft(head,val,pos);
            break;

            case 5:
             //head = clear(head);
            break;

            case 6:
            // puts("Enter node to delete");
            // scanf("%d",&val);
            // head = delete_node(head,val);
            break;

            case 7:
            //printf("Size of List: %d",size(head));
            break;

            case 8:
            // puts("Enter value");
            // scanf("%d",&val);
            // (find(head,val) == 1)? puts("True"):puts("false");
            break;
        }
    }while(opt >=0 && opt < 9);
}