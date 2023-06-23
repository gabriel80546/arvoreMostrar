#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore {
    char* titulo;
    struct Arvore** filho;
    int numFilhos;
} Arvore;

Arvore* criarNo(char* titulo, int numFilhos) {
    Arvore* no = (Arvore*)malloc(sizeof(Arvore));
    no->titulo = strdup(titulo);
    no->numFilhos = numFilhos;
    no->filho = (Arvore**)malloc(sizeof(Arvore*) * numFilhos);

    return no;
}

void exibirArvore(Arvore* no, int nivel) {
    if (no == NULL) {
        return;
    }

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("%s\n", no->titulo);

    for (int i = 0; i < no->numFilhos; i++) {
        if (no->filho[i] != NULL) {
            exibirArvore(no->filho[i], nivel + 1);
        }
    }
}

void liberarArvore(Arvore* no) {
    if (no == NULL) {
        return;
    }

    free(no->titulo);

    for (int i = 0; i < no->numFilhos; i++) {
        liberarArvore(no->filho[i]);
    }

    free(no->filho);
    free(no);
}

int main() {
    Arvore* linguagem = criarNo("linguagem", 3);
        Arvore* natureza = criarNo("natureza", 2);
            Arvore* humana = criarNo("humana", 0);
            Arvore* seresVivos = criarNo("seres vivos", 0);
        Arvore* multiverso = criarNo("multiverso", 2);
            Arvore* invertida = criarNo("invertida", 0);
            Arvore* impossivel = criarNo("impossivel", 0);
        Arvore* desconhecida = criarNo("desconhecida", 3);
            Arvore* inventada = criarNo("inventada", 0);
            Arvore* inconsciente = criarNo("inconsciente", 0);
            Arvore* deuses = criarNo("deuses", 0);

    linguagem->filho[0] = natureza;
        natureza->filho[0] = humana;
        natureza->filho[1] = seresVivos;
    linguagem->filho[1] = multiverso;
        multiverso->filho[0] = invertida;
        multiverso->filho[1] = impossivel;
    linguagem->filho[2] = desconhecida;
        desconhecida->filho[0] = inventada;
        desconhecida->filho[1] = inconsciente;
        desconhecida->filho[2] = deuses;

    exibirArvore(linguagem, 0);
    liberarArvore(linguagem);
    return 0;
}
