//
// Created by PJ Samuels on 4/22/21.
//

#include "rpn.h"
#include "errors.h"
#include "stack.h"
#include "node.h"
#include <string.h>
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

double evaluate (char* input, int* status) {
    double number;
    *status = 0;
    char *token = strtok(input," ");
    if(token){
        if(sscanf(token,"%lf", &number) == 1) {
            //printf("number: %f\n", number);
            node* node = createNode(number,1,NULL);
            push(node);
        }
        else{
            *status = NONUM;
            return(0.0);
        }
    }
    while(token = strtok(NULL, " ")){
        if(sscanf(token,"%lf", &number) == 1) {
            //printf("number: %f\n", number);
            node* node = createNode(number,1,NULL);
            push(node);
        }
        else{
            double num1,num2,val;
            node* answer;
            node* temp;
            switch(*token) {
                case '+':
                    temp = pop();
                    val = temp->contents.value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->contents.value;
                    num2 = val;
                    val = (num2+num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '-':
                    temp = pop();
                    val = temp->contents.value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->contents.value;
                    num2 = val;
                    val = (num2-num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '*':
                    temp = pop();
                    val = temp->contents.value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->contents.value;
                    num2 = val;
                    val= (num2*num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '/':
                    temp = pop();
                    val = temp->contents.value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->contents.value;
                    num2 = val;
                    if(num1 == 0 && num2 == 0) {
                        *status = DZERO;
                        return 0.0;
                    }
                    answer = createNode((num2/num1), 1, NULL);
                    push(answer);
                    break;
                case '^':
                    temp = pop();
                    val = temp->contents.value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->contents.value;
                    num2 = val;
                    answer = createNode(pow(num2,num1), 1, NULL);
                    push(answer);
                    break;
            }
        }
    }
    node* temp = head;
    if(head == NULL || head->next != NULL ) {
        *status = ERRNULLPOINTER;
        return 0.0;
    }
    *status = SUCCESS;
    return head->contents.value;
}
double pow(double num1, double num2){
    double ans = 1;
    for(int i = 0; i < num2;i++){
        ans*=num1;
    }
    return ans;
}

void converter(char* input,char* output){
    double number;
    int i = 0;
    node* tempnode;

    char *token = strtok(input," ");
    if(sscanf(token,"%lf", &number) == 1){
        if(number> 10) {
            int t = (int)number % 10;
            int t2 = (int)number/10;
            output[i] =t2%10+'0';
            output[i+1] = t+'0';
            output[i+2] = ' ';
            i+=2;
        }
        else{
            output[i] = number+'0';
            output[i+1] = ' ';
            i+=2;
        }
    }
    else{
        tempnode = createOp(*token,0,NULL);
        push(tempnode);
    }
    while(token = strtok(NULL, " ")) {
        if(sscanf(token,"%lf", &number) == 1) {
            if(number> 9) {
                int t = (int)number % 10;
                int t2 = (int)number/10;
                output[i] =t2%10+'0';
                output[i+1] = t+'0';
                output[i+2] = ' ';
                i+=3;
            }
            else{
                output[i] = number+'0';
                output[i+1] = ' ';
                i+=2;
            }
        }
        else if(*token == '*' || *token == '+'||*token == '/'||*token == '-'||*token == '^') {
            if (peek() == NULL){
                tempnode = createOp(*token, 0, NULL);
                push(tempnode);
            }
            else {
                while (!stackEmpty()&&getPriority(*token) <= getPriority(peek()->contents.operator)) {
                    output[i] = pop()->contents.operator;
                    i++;
                }
                tempnode = createOp(*token,0,NULL);
                push(tempnode);
            }
        }
        else if (*token == '(') {
            tempnode = createOp(*token, 0, NULL);
            push(tempnode);
        }
        else if (*token == ')') {
            while (!stackEmpty()&&peek()->contents.operator != '(') {
                node *newnode = pop();
                output[i] = newnode->contents.operator;
                i++;
            }
            pop();
        }
        else {
            output = "Invalid equation";
            return;
        }
    }
    while (!stackEmpty()){
        if (peek()->contents.operator == '(' || peek()->contents.operator == ')') {
            output = "Invalid equation";
            return;
        }

        output[i] = pop()->contents.operator;
        i++;
    }

}
int getPriority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

