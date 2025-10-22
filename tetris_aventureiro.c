#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

typedef struct {
    char tipo;
    int id;
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca itens[MAX_FILA];
    int inicio, fim, total;
} Fila;

// Estrutura da pilha
typedef struct {
    Peca itens[MAX_PILHA];
    int topo;
} Pilha;

// Funcoes da fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaVazia(Fila *f) {
    return f->total == 0;
}

int filaCheia(Fila *f) {
    return f->total == MAX_FILA;
}

void enfileirar(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao e possivel inserir nova peca.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->total++;
}

Peca desenfileirar(Fila *f) {
    Peca vazia = {'?', -1};
    if (filaVazia(f)) {
        printf("Fila vazia! Nenhuma peca para jogar.\n");
        return vazia;
    }
    Peca p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
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
        idx = (idx + 1) % MAX_FILA;
    }
    printf("\n");
}

// Funcoes da pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

void empilhar(Pilha *p, Peca x) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Nao e possivel empilhar nova peca.\n");
        return;
    }
    p->itens[++p->topo] = x;
}

Peca desempilhar(Pilha *p) {
    Peca vazia = {'?', -1};
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nao ha peca para usar.\n");
        return vazia;
    }
    return p->itens[p->topo--];
}

void mostrarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha: (vazia)\n");
        return;
    }
    printf("Pilha (Topo -> Base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->itens[i].tipo, p->itens[i].id);
    }
    printf("\n");
}

// Gerador de pecas
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
    Pilha reserva;
    inicializarFila(&fila);
    inicializarPilha(&reserva);

    int proxID = 0;

    // Inicializa a fila com 5 pecas
    for (int i = 0; i < MAX_FILA; i++) {
        enfileirar(&fila, gerarPeca(&proxID));
    }

    int opcao;
    do {
        printf("\n=== NIVEL AVENTUREIRO ===\n");
        mostrarFila(&fila);
        mostrarPilha(&reserva);
        printf("1 - Jogar peca\n2 - Reservar peca (fila -> pilha)\n3 - Usar peca reservada\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Peca jogada = desenfileirar(&fila);
            if (jogada.id != -1) {
                printf("Peca jogada: [%c %d]\n", jogada.tipo, jogada.id);
                enfileirar(&fila, gerarPeca(&proxID));
            }
        } else if (opcao == 2) {
            if (filaVazia(&fila)) {
                printf("Fila vazia! Nao ha peca para reservar.\n");
            } else if (pilhaCheia(&reserva)) {
                printf("Pilha cheia! Nao e possivel reservar mais pecas.\n");
            } else {
                Peca movida = desenfileirar(&fila);
                empilhar(&reserva, movida);
                printf("Peca reservada: [%c %d]\n", movida.tipo, movida.id);
                enfileirar(&fila, gerarPeca(&proxID));
            }
        } else if (opcao == 3) {
            Peca usada = desempilhar(&reserva);
            if (usada.id != -1) {
                printf("Peca usada da reserva: [%c %d]\n", usada.tipo, usada.id);
                enfileirar(&fila, gerarPeca(&proxID));
            }
        }
    } while (opcao != 0);

    printf("Encerrando nivel aventureiro...\n");
    return 0;
}