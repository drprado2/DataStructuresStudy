#include "Helpers.h"
#include <stdio.h>

void setPrintTextColorRed(){
    printf("\033[0;31m");
}

void setPrintTextColorGreen(){
    printf("\033[0;32m");
}

void setPrintTextColorDefault(){
    printf("\033[0m");
}
