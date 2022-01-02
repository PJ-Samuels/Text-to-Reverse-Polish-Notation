//
// Created by PJ Samuels on 3/29/21.
//
#include "node.h"
#include <stdbool.h>
#include <stdio.h>
#ifndef PS5_STACK_H
#define PS5_STACK_H
struct node* head;
void push(node* node);
struct node* pop(void);
struct node* peek(void);
void printStack(void);
void clearStack(void);
bool stackEmpty(void);
#endif //PS5_STACK_H
