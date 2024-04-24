/**
 * Array implementation of the stack
 * 
 */
#include<stdio.h>

static  int TOP = -1;
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

	switch(opt){

		case 1:
			display();
			break;

		case 2:
			puts("Enter value");
			scanf("%d",&val);

			push(val);
			break;

		case 3:
			val = pop();
			printf("%d\n",val);
			break;

		case 4:
			val = peek();
			printf("%d\n",val);
			break;

	}


    }while(opt > 0 && opt < 5);
}
