#ifndef LISTA_HPP
#define LISTA_HPP

typedef struct node {
    float val;
    struct node * prox;
} Node;

class Lista {
    private:
        Node * cabeca;

    public:
        Lista();
        ~Lista();
        bool insere(float num);
        bool remove(float num);
        float remove(int indice);
        bool limpa();
        bool insere(float num, int indice);
        void listar();
};

#endif
