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
    Arvore* silvestre = criarNo("silvestre", 3);
        Arvore* pandinha = criarNo("pandinha", 3);
            Arvore* cargos = criarNo("cargos", 0);
            Arvore* youtuber = criarNo("youtuber", 0);
            Arvore* elonMusk = criarNo("elon musk", 0);
        Arvore* dezG = criarNo("dezG", 2);
            Arvore* chefeElite = criarNo("Chefe Elite", 0);
            Arvore* reiDoRap = criarNo("Rei do Rap", 0);
        Arvore* gabriel = criarNo("gabriel", 3);
            Arvore* enxadrista = criarNo("Enxadrista", 0);
            Arvore* donoDoServidor = criarNo("Dono do Servidor", 0);
            Arvore* programador = criarNo("programador", 0);

    silvestre->filho[0] = pandinha;
        pandinha->filho[0] = cargos;
        pandinha->filho[1] = youtuber;
        pandinha->filho[2] = elonMusk;
    silvestre->filho[1] = dezG;
        dezG->filho[0] = chefeElite;
        dezG->filho[1] = reiDoRap;
    silvestre->filho[2] = gabriel;
        gabriel->filho[0] = enxadrista;
        gabriel->filho[1] = donoDoServidor;
        gabriel->filho[2] = programador;

    exibirArvore(silvestre, 0);
    liberarArvore(silvestre);
    return 0;
}
