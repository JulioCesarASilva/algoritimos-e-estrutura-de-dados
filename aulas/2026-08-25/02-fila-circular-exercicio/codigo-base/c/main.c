#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10   // Capacidade máxima (uma posição fica reservada)

// Estrutura da fila circular
typedef struct {
    int itens[TAMANHO];
    int frente;      // Índice do primeiro elemento
    int tras;        // Índice onde o próximo elemento será inserido
} Fila;

// Inicializa a fila (frente = tras = 0)
void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

// Verifica se a fila está vazia
bool isEmpty(Fila *f) {
    return f->frente == f->tras;
}

// Verifica se a fila está cheia (circular)
bool isFull(Fila *f) {
    return (f->tras + 1) % TAMANHO == f->frente;
}

// Insere um elemento no final da fila (enqueue)
bool enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        printf("Erro: fila cheia!\n");
        return false;
    }
    f->itens[f->tras] = valor;
    f->tras = (f->tras + 1) % TAMANHO;
    return true;
}

// Retira o elemento do início da fila (dequeue)
bool dequeue(Fila *f, int *valor) {
    if (isEmpty(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }
    *valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % TAMANHO;
    return true;
}

// Consulta o primeiro elemento sem remover (front)
bool front(Fila *f, int *valor) {
    if (isEmpty(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }
    *valor = f->itens[f->frente];
    return true;
}

// Exibe todos os elementos da fila (do início ao fim)
void exibir(Fila *f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila (início -> fim): ");
    int i = f->frente;
    while (i != f->tras) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % TAMANHO;
    }
    printf("\n");
}

int main() {
    Fila minhaFila;
    inicializar(&minhaFila);

    // Insere alguns valores
    enqueue(&minhaFila, 10);
    enqueue(&minhaFila, 20);
    enqueue(&minhaFila, 30);
    exibir(&minhaFila);   // 10 20 30

    // Consulta o início
    int valor;
    if (front(&minhaFila, &valor)) {
        printf("Início: %d\n", valor);   // 10
    }

    // Remove o primeiro
    if (dequeue(&minhaFila, &valor)) {
        printf("Removeu: %d\n", valor);  // 10
    }
    exibir(&minhaFila);   // 20 30

    // Insere mais valores
    enqueue(&minhaFila, 40);
    enqueue(&minhaFila, 50);
    exibir(&minhaFila);   // 20 30 40 50

    return 0;
}
