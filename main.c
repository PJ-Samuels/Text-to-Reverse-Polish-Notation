#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stack.h"
#include "rpn.h"
typedef enum{op,num} TYPE;
typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    TYPE type;
    int precedence;
    node *next;
} node;
int main (int argc, char* argv[]) {
    char input[100];
    char output[100];
    int status = 0;
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

//    char temp[] = "7 ^ 2 * ( 25 + 10 / 5 ) - 13";
//    char temp2[] = "                       ";
//    converter(temp,temp2);

//    if (!in) {
//        perror("I/O error: ");
//        return -1;
//    }
    while (fgets(input, sizeof(input), in)){
        fprintf(out,"infix: %s", input);
        printf("%s", input);

        converter(input,output);
        fprintf(out, "postfix: %s\n",output);

        int status = 0;
        double ans = evaluate(output,&status);
        fprintf(out,"result: \n", ans);
//        memset();
    }
    fclose(in);

    return 0;
}

