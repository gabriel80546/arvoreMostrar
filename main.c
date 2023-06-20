#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arvore {
    char* titulo;
    struct Node* filho;
    int numFilhos;
};

typedef struct Arvore Arvore;

int main() {
    Arvore* ser;
    ser = (Arvore*) malloc(sizeof(Arvore) * 1);
    printf("Ola mundo, ser = %p\n", ser);
    return 0;
}