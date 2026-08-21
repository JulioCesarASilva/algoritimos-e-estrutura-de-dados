#include "./lista.hpp"
#include <malloc.h>

// Construtor
Lista::lista() {
    cabeca = NULL
}

// Destrutor
Lista::~lista() {
    limpa();
}

bool Lista::insere(float num) {
    Node *p = cabeca;

    if(p ==NULL){
        p = (Node*)malloc(sizeof(Node)); //aloca
        p -> val = num;
        p -> prox = NULL; 
        cabeca = p;
        return true;
    } else {
        while (p->prox !== NULL) {
            p = p->prox;
        }

        p->prox = (Node*)malloc(sizeof(Node));
        p->prox->val = num;
        p->prox->prox = NULL;
        return true;
    }

    return false;
}

bool Lista::remove(float num) {
    Node *p, *q;
    p = cabeca;
    q = cabeca;

    if(p !== NULL) {
        if(p->val == num) {
            cabeca = p->prox;
            delete(p);
            return true;
        } else {
            p= p->prox;
            while (p !== NULL && p->val !== num) {
                p = p->prox;
                q = q->prox;
            }

            if (p!==NULL && p->val == num) {
                q->prox = NULL;
                delete(p);
                return true;
            }
        }
    } 

    return false;
}
