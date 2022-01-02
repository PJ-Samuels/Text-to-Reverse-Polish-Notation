//
// Created by PJ Samuels on 4/22/21.
//
#include "node.h"
#include "stack.h"
#include <stdio.h>
#ifndef PS5_RPN_H
#define PS5_RPN_H
double evaluate (char* input, int* status);
double pow(double num1, double num2);
void converter(char* input, char* output);
void buffer(char *buf, int count);
int getPriority(char ch);
#endif //PS5_RPN_H
