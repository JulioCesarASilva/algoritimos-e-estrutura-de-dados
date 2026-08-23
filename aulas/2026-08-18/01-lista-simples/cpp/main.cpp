#include <iostream>
#include "./lista.hpp"

int main() {
    Lista lista;

    lista.insere(10.5f);
    lista.insere(11.0f);
    lista.insere(50.5f);
    lista.insere(20.5f);
    lista.insere(15.5f, 1);
    
    std::cout << "Lista: ";
    lista.listar();

    std::cout << "Removido por indice: " << lista.remove(1) << std::endl;
    std::cout << "Removeu o valor 20.5: " << lista.remove(20.5f) << std::endl;

    std::cout << "Lista: ";
    lista.listar();

    lista.limpa();
    return 0;
}
