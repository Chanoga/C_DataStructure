/**
 * Array implementation of the stack
 * 
 */
#include<stdio.h>

static unsigned int TOP = -1;
#define MAX 5 //maximum number of elements in array

int stack[MAX];

void push(int val)
{
    //is the stack full?
    if(TOP == (MAX - 1))
    {
        puts("StackOverFlowError");
        return;
    }
    else{
        TOP += 1;
        stack[TOP] = val;
    }
}

int pop(void)
{
    //is the stack empty
    if(TOP == -1)puts("StackUnderFlow");

    else
    {
        int val = stack[TOP];
        TOP--;
        return val;
    }
}

int peek()
{
    if(TOP == -1)puts("StackUnderFlow");

    else return stack[TOP];
}

//display the stack nodes
void display(void)
{
    if(TOP == -1) puts("Empty Stack");

    else for(int i = TOP; i >=0;i--) printf("%d->",stack[i]);
}

void array_implementation(void)
{
    unsigned short opt;
    int val;
    do{
        puts("\n1: Display\n2: PUSH\n3: POP\n4: PEEK\n");
        scanf("%d",&opt);

        if(opt == 1) display();

        else if(opt == 2){
            puts("Enter value");
            scanf("%d",&val);
            push(val);
        }
        else if(opt == 3) pop();

        else if (opt == 4) printf("%d\n",peek());

    }while(opt > 0 && opt < 5);
}