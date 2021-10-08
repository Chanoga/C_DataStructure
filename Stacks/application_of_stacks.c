/**
 * Stack data structure is applied in the following applications
 * 
 * -->Reversing a list
 * -->Parentheses checker
 * -->Conversion of an infix expression into a profix expression
 * -->Evaluation of a postfix
 * -->Conversion of an infix expression into a prefix expression
 * -->Evaluation of a prefix expression
 * -->Tower of Hanoi
 */

//let's see how
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   #define MAX 10
   int top = -1;
   int stk[MAX];
//our list
typedef struct LinkedList
{
    int node;
    struct LinkedList *next;
}List;

List *head = NULL;

List* insert_beg(List* list,int val)
{
    List *element;
    element = (List*)malloc(sizeof(List));
    element ->node = val;

    if(list == NULL)
    {
        list = element;
        list->next = NULL;
    }
    else
    {
        element->next = list;
        list = element;
    }
    return list;
}

//display
void display(List* list)
{
    if(list == NULL){
        puts("Empty List");
        return;
    }
    else
    {
        while(list != NULL)
        {
            printf("%d->",list->node);

            list = list->next;
        }
    }
}
//get the size of the list
unsigned int size(List* list)
{
    unsigned int count  = 0;

    if(list == NULL) return 0;

    else
    {
        while(list != NULL)
        {
            count++;
            list = list->next;
        }
        return count;
    }
}

//reversing the list
List *reverse(List* list)
{
    return list;
}

//this function checks for the correctiness of the parenthes
void push(char c)
{
    if(top == MAX-1)puts("StackOverFlow");

    else
    {
        stk[++top] = c;
    }
}
char pop()
{
    if(top == -1)puts("StackUnderFlow");
    else return stk[top--];
}

int main(void)
{
    unsigned short opt;
    int val;
    do
    {
        puts(("\n\
        1: Insert node \n\
        2: Display \n\
        3: Reverse List \n\
        4: Size \n\
        5: Parenthes checker\n\
        "));

        scanf("%hu",&opt);

        switch (opt)
        {
        case 1:
        puts("Enter value");
        scanf("%d",&val);
            head = insert_beg(head,val);
            break;

            case 2:
            display(head);
            break;

            case 3:
            head = reverse(head);
            break;

            case 4:
            printf("Size: %d\n",size(head));
            break;
        default:
            break;
        }
    } while (opt > 0 && opt < 5);
    
    return 0;
}