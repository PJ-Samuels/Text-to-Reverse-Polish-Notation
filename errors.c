//
// Created by PJ Samuels on 4/22/21.
//
#include <stdio.h>
#include "errors.h"
#include "stack.h"
void errorMessage(int status){
    switch(status) {
        case SUCCESS:
            printf("Successful: ");
            break;
        case NONUM:
            printf("ERROR: Not Enough numbers");
            break;
        case ERROROPERATOR:
            printf("ERROR: To Many Operators");
            break;
        case DZERO:
            printf("ERROR: Divdes by 0");
            break;
        case ERRNULLPOINTER:
            printf("ERROR: NULL pointer");
            break;
        case NOOPERATOR:
            printf("ERROR: No Numbers OR Symbols too Early");
            break;
    }

}





