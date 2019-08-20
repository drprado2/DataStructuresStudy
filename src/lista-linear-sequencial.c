#include <stdio.h>
#include <stdbool.h>
#include "lista-linear-sequencial.h"

void initializeList(List* list){
    list->size = 0;
}

void printList(List* list){
    for(int i=0; i<list->size; i++)
        printf("List: %i\n", list->items[i]);
}

bool add(List* list, Register reg){
    if(list->size == DEFAULT_SIZE_LIST)
        return false;

    list->items[list->size] = reg;
    list->size++; 
    return true;   
}

bool addOnPosition(List* list, Register reg, int position){
    if(list->size == DEFAULT_SIZE_LIST || position < 0 || position >= list->size)
        return false;
    
    for(int i = list->size; i > position; i--)
        list->items[i] = list->items[i - 1];
    
    list->items[position] = reg;
    list->size++;
    return true;    
}

int getSize(List* list){
    return list->size;
}

int findIndex(List* list, PrimaryKey key){
    for(int i = 0; i < list->size; i++){
        if(list->items[i].key == key)
            return i;
    }
    return -1;
}

bool delete(List* list, Register element){
    int position = findIndex(list, element.key);
    if(position < 0)
        return false;
    
    for(int i = position; i < list->size; i++)
        list->items[i] = list->items[i+1];
    
    return true;
}

void restartList(List* list){
    list->size = 0;
}
