#include "./lista.hpp"
#include <cstdlib>

// Construtor
Lista::Lista() {
    cabeca = NULL;
}

// Destrutor
Lista::~Lista() {
    limpa();
}

bool Lista::insere(float num) {
    Node *p = cabeca;

    if (p == NULL) {
        p = (Node*) malloc(sizeof(Node)); // aloca

        if (p == NULL) {
            return false;
        }

        p->val = num;
        p->prox = NULL;
        cabeca = p;
        return true;
    } else {
        while (p->prox != NULL) {
            p = p->prox;
        }

        p->prox = (Node*) malloc(sizeof(Node));

        if (p->prox == NULL) {
            return false;
        }

        p->prox->val = num;
        p->prox->prox = NULL;
        return true;
    }
}

bool Lista::remove(float num) {
    Node *p, *q;
    p = cabeca;
    q = cabeca;

    if (p != NULL) {
        if(p->val == num) {
            cabeca = p->prox;
            free(p);
            return true;
        } else {
            p = p->prox;

            while (p != NULL && p->val != num) {
                p = p->prox;
                q = q->prox;
            }

            if (p != NULL) {
                q->prox = p->prox;
                free(p);
                return true;
            }
        }
    }

    return false;
}

float Lista::remove(int indice) {
    Node *p = cabeca;
    Node *q = NULL;
    float num;

    if (indice < 0) {
        return 0;
    }

    for (int i = 0; i < indice && p != NULL; i++) {
        q = p;
        p = p->prox;
    }

    if (p == NULL) {
        return 0;
    }

    num = p->val;

    if (q == NULL) {
        cabeca = p->prox;
    } else {
        q->prox = p->prox;
    }

    free(p);
    return num;
}

bool Lista::limpa() {
    Node *p = cabeca;
    Node *q;

    while (p != NULL) {
        q = p;
        p = p->prox;
        free(q);
    }

    cabeca = NULL;
    return true;
}

bool Lista::insere(float num, int indice) {
    Node *novo;
    Node *p = cabeca;

    if (indice < 0) {
        return false;
    }

    if (indice == 0) {
        novo = (Node*) malloc(sizeof(Node));

        if (novo == NULL) {
            return false;
        }

        novo->val = num;
        novo->prox = cabeca;
        cabeca = novo;
        return true;
    }

    for (int i = 0; i < indice - 1 && p != NULL; i++) {
        p = p->prox;
    }

    if (p == NULL) {
        return false;
    }

    novo = (Node*) malloc(sizeof(Node));

    if (novo == NULL) {
        return false;
    }

    novo->val = num;
    novo->prox = p->prox;
    p->prox = novo;
    return true;
}

void Lista::listar() {
    Node *p = cabeca;

    while (p != NULL) {
        std::cout << p->val;

        if (p->prox != NULL) {
            std::cout << " -> ";
        }

        p = p->prox;
    }

    std::cout << std::endl;
}

