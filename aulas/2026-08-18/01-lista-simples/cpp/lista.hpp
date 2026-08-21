typedef struct node { 
    float val;
    struct node * prox;
} Node;

class Lista {
    private: 
        Node * cabeca;
    public: 
        lista();
        ~lista();
        bool insere(float num);
        bool remove(float num);
        float remove(int indice);
        bool limpa();
        bool insere(float num, int indice);
}