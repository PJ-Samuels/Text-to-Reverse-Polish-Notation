//
// Created by PJ Samuels on 4/22/21.
//
#ifndef PS5_NODE_H
#define PS5_NODE_H
typedef struct node node;
struct node* createNode(double value, int type, node* next);
node* createOp(char operator, int t, node* n);
#endif //PS5_NODE_H
