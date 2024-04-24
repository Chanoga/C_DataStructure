#include<stdio.h>
#include<malloc.h>

//structure to hold our nodes
typedef struct Linked_list{
    int node;
    struct Linked_list *next;
}List;

List *head = NULL;

void display2(List* list){
    if(list == NULL){
        puts("Empty List");
        return;
    }
    else{
        while(list != NULL){
            printf("%d->",list->node);
            list = list->next;
        }
    }
}
//push
List* push2(List* list,int val){
    List *element;

    element = (List*)calloc(1,sizeof(List));
    element ->node = val;

    if(list == NULL){
        list = element;
        list->next = NULL;
    }
    else{
        element->next = list;
        list = element;
    }

    return list;
}

int pop2()
{
    if(head == NULL)
    {
        puts("StackUnderFlowError");
        return -1;
    }
    else
    {
       List* temp;
       temp = head;
       int val = temp->node;
       head = head->next;
       free(temp); 
       return val;
    }    
}

int peek2(void)
{
	int val;
    return val = (head == NULL) ? 0 : head->node;
}
void linked_list_implementation(void){

    unsigned short opt;
    int val;

    do{
    puts(("\n\
    1: Push\n\
    2: Pop \n\
    3: Display \n\
    4: Peek \n\
    "));
    scanf("%hu",&opt);

    switch(opt){

	    case 1:
        puts("Enter value");
        scanf("%d",&val);
       head = push2(head,val);
       break;
	    case 2:
        printf("%d ", pop2());
	break;
	    case 3:
       display2(head);
       break;

	    case 4:
    printf("%d\n",peek2());
    break;
    }

    }while(opt > 0 && opt < 5);
}
