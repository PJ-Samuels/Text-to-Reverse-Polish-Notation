////
//// Created by PJ Samuels on 3/29/21.
////
#include "node.h"
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
node* createNode(double value, int t, node* n){
    node *newNode = (struct node*)malloc(sizeof(node));
    newNode->contents.value = value;
    newNode->type = t;
    newNode->next = n;
    return newNode;
}
node* createOp(char operator, int t, node* n){
    node *newNode = (struct node*)malloc(sizeof(node));
    newNode->contents.operator = operator;
    newNode->type = t;
    newNode->next = n;
    return newNode;
}