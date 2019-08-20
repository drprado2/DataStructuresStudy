#include <stdbool.h>

#define DEFAULT_SIZE_LIST 50

typedef int PrimaryKey;

typedef struct {
    PrimaryKey key;
    // ... outros campos
} Register;

typedef struct {
    Register items[DEFAULT_SIZE_LIST];
    int size;
} List;

void initializeList(List* list);

void printList(List* list);

bool add(List* list, Register reg);

bool addOnPosition(List* list, Register reg, int position);

int getSize(List* list);

int findIndex(List* list, PrimaryKey key);

bool delete(List* list, Register element);

void restartList(List* list);
