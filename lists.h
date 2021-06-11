/*
    The Header for all the lists data structures
    ---------------------------------------------
*/

#ifndef _LISTS_H
#define _LISTS_H
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct LinkedList
{
    int node;
    struct LinkedList *next;
    struct LinkedList *prev;
}List;
#endif
