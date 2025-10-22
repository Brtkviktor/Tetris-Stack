#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

// Estrutura que representa uma peca do Tetris
typedef struct {
    char tipo; // 'I', 'O', 'T', 'L'
    int id;    // identificador unico
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca itens[MAX];
    int inicio, fim, total;
} Fila;

// Funcoes basicas da fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaVazia(Fila *f) {
    return f->total == 0;
}

int filaCheia(Fila *f) {
    return f->total == MAX;
}

void enfileirar(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao e possivel inserir nova peca.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

Peca desenfileirar(Fila *f) {
    Peca vazia = {'?', -1};
    if (filaVazia(f)) {
        printf("Fila vazia! Nenhuma peca para jogar.\n");
        return vazia;
    }
    Peca p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return p;
}

void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila: (vazia)\n");
        return;
    }
    printf("Fila: ");
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        printf("[%c %d] ", f->itens[idx].tipo, f->itens[idx].id);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

// Funcao geradora de pecas automaticas
char tipos[] = {'I', 'O', 'T', 'L'};
Peca gerarPeca(int *proxID) {
    Peca p;
    p.tipo = tipos[rand() % 4];
    p.id = (*proxID)++;
    return p;
}

// Programa principal
int main() {
    srand(time(NULL));
    Fila fila;
    inicializarFila(&fila);
    int proxID = 0;

    // Inicializa a fila com 5 pecas
    for (int i = 0; i < MAX; i++) {
        enfileirar(&fila, gerarPeca(&proxID));
    }

    int opcao;
    do {
        printf("\n=== NIVEL NOVATO ===\n");
        mostrarFila(&fila);
        printf("1 - Jogar peca\n2 - Inserir nova peca\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Peca jogada = desenfileirar(&fila);
            if (jogada.id != -1) {
                printf("Peca jogada: [%c %d]\n", jogada.tipo, jogada.id);
                Peca nova = gerarPeca(&proxID);
                enfileirar(&fila, nova);
                printf("Nova peca gerada: [%c %d]\n", nova.tipo, nova.id);
            }
        } else if (opcao == 2) {
            Peca nova = gerarPeca(&proxID);
            enfileirar(&fila, nova);
            printf("Nova peca inserida: [%c %d]\n", nova.tipo, nova.id);
        }
    } while (opcao != 0);

    printf("Encerrando nivel novato...\n");
    return 0;
}