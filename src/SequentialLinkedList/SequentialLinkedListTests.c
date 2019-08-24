#include "SequentialLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Helpers/Helpers.h"
#include "SequentialLinkedListTests.h"

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
    printf("\nRunning scenario adding items with full list...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);

    for(int i = 1; i <= 50; i++){
        Register reg = { .key = i };
        add(list, reg);
    }

    Register reg = { .key = 51 };

    bool resultAdd1 = add(list, reg);

    if(!resultAdd1 && list->size == 50) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}


void printingList(){
    printf("\nRunning scenario printing list...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    Register reg1 = { .key = 1 };
    Register reg2 = { .key = 2 };
    Register reg3 = { .key = 3 };
    add(list, reg1);
    add(list, reg2);
    add(list, reg3);
    printList(list);
    setPrintTextColorGreen();
    printf("Success!\n");
    setPrintTextColorDefault();
}

void addingItensOnSpecificPosition(){
    printf("\nRunning scenario adding item on specific position...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);

    for(int i = 1; i <= 8; i++){
        Register reg = { .key = i };
        add(list, reg);
    }

    Register reg1 = { .key = 9 };
    Register reg2 = { .key = 10 };
    Register reg3 = { .key = 11 };

    bool result1 = addOnPosition(list, reg1, 7);
    bool result2 = addOnPosition(list, reg2, 0);
    bool result3 = addOnPosition(list, reg3, 4);

    bool successAdding = result1 && result2 &&  result3;

    int positionReg1 = findIndex(list, reg1.key);
    int positionReg2 = findIndex(list, reg2.key);
    int positionReg3 = findIndex(list, reg3.key);

    bool successPositions = positionReg1 == 9 && positionReg2 == 0 && positionReg3 == 4;

    if(successAdding && successPositions && list->size == 11) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

void addingItemOnSpecificInvalidPosition(){
    printf("\nRunning scenario adding item on specific position...\n");
    List* list = (List*) malloc(sizeof(List));
    initializeList(list);
    Register reg = { .key = 1 };
    Register reg1 = { .key = 2 };

    bool result = addOnPosition(list, reg, -1);
    bool result1 = addOnPosition(list, reg1, 0);

    if(!result && !result1 && list->size == 0) {
        setPrintTextColorGreen();
        printf("Success!\n");
    } else{
        setPrintTextColorRed();
        printf("Fail!\n");
    }
    setPrintTextColorDefault();
}

void runAllSequentialLinkedListScenarios(){
    printf("\nRunning scenario adding item on specific position...\n");
    printingList();
    initializingList();
    addingItems();
    addingItemsWithFullList();
    addingItemOnSpecificInvalidPosition();
    addingItensOnSpecificPosition();
    printf("\nRunning scenario adding item on specific position...\n");
}