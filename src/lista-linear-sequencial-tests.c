// Quando importamos módulos próprios não usamos o < > usamos ""
#include "lista-linear-sequencial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setPrintTextColorRed(){
    printf("\033[0;31m");
}

void setPrintTextColorGreen(){
    printf("\033[0;32m");
}

void setPrintTextColorDefault(){
    printf("\033[0m");
}

void initializingList(){
    printf("\nRunning scenario initializing list...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);

    if(list->size == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

void addingItems(){
    printf("\nRunning scenario adding items...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    int numberOfErrors = 0;

    Register reg1 = { .key = 3 };
    Register reg2 = { .key = 2 };
    Register reg3 = { .key = 1 };

    bool resultAdd1 = add(list, reg1);

    if(list->items[0].key != reg1.key || !resultAdd1) numberOfErrors++;
    if(list->size != 1) numberOfErrors++;

    bool resultAdd2 = add(list, reg2);
    bool resultAdd3 = add(list, reg3);

    if(list->items[0].key != reg1.key) numberOfErrors++;
    if(list->items[1].key != reg2.key || !resultAdd2) numberOfErrors++;
    if(list->items[2].key != reg3.key || !resultAdd3) numberOfErrors++;
    if(list->size != 3) numberOfErrors++;

    if(numberOfErrors == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

void addingItemsWithFullList(){
    printf("\nRunning scenario adding items...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    int numberOfErrors = 0;

    Register reg1 = { .key = 3 };
    Register reg2 = { .key = 2 };
    Register reg3 = { .key = 1 };

    bool resultAdd1 = add(list, reg1);

    if(list->items[0].key != reg1.key || !resultAdd1) numberOfErrors++;
    if(list->size != 1) numberOfErrors++;

    bool resultAdd2 = add(list, reg2);
    bool resultAdd3 = add(list, reg3);

    if(list->items[0].key != reg1.key) numberOfErrors++;
    if(list->items[1].key != reg2.key || !resultAdd2) numberOfErrors++;
    if(list->items[2].key != reg3.key || !resultAdd3) numberOfErrors++;
    if(list->size != 3) numberOfErrors++;

    if(numberOfErrors == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}


void printingList(){
    List* list = (List*) malloc(sizeof(List));
    initializingList(list);
    Register reg1 = { .key = 1 };
    Register reg2 = { .key = 2 };
    Register reg3 = { .key = 3 };
    add(list, reg1);
    add(list, reg2);
    add(list, reg3);
    printList(list);
}

void addingItemOnSpecificPositionLessThenZero(){
    printf("\nRunning scenario adding item on specific position...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    int numberOfErrors = 0;

    Register reg1 = { .key = 3 };

    bool result = addOnPosition(list, reg1, -1);

    if(!result && list->size == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

void addingItemOnSpecificPositionLessThenZero(){
    printf("\nRunning scenario adding item on specific position...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    int numberOfErrors = 0;

    Register reg1 = { .key = 3 };

    bool result = addOnPosition(list, reg1, -1);

    if(!result && list->size == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

int main(){
    initializingList();
    addingItems();
//    printingList();
}