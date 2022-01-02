//
// Created by PJ Samuels on 4/22/21.
//
#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum{op,num} TYPE;
typedef struct node {
    union{
        double value;
        char operator;
    }contents;
    TYPE type;
    int precedence;
    node *next;
} node;

void push(node* node_p) {
    if (head == NULL) {
        head = node_p;
    } else {
        node_p->next = head;
        head = node_p;
    }
}
node* pop(void){
    if(!head){
//        printf("Stack Underflow");
//        createNode(-1,1,NULL);
//        return head;
//        exit(1);
    }
    else {
        node *top = head;
        head = top->next;
        return top;
    }
}
node* peek(void){
    return head;
}
void printStack(void)
{
    node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("elements of list are : ");
    temp = head;

    while (temp != NULL) {
        printf("%.3lf ", temp->contents.value);
        temp = temp->next;
    }
    printf("\n");
}
void clearStack(void){
    node *remove = NULL;
    while (head != NULL) {
        remove = pop();
        free(head);
        remove = NULL;
    }
}
bool stackEmpty(void){
    if(head == NULL)
        return true;
}
