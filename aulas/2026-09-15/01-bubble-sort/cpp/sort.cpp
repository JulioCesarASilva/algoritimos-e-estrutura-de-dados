
#include "sort.hpp"

void imprimirVetor(int v[], int n, int idx1 = -1, int idx2 = -1, bool s = false) {       
    s ? std::cout << "Processando lista: [" : std::cout << "[";
    for (int i = 0; i < n; ++i) {
        // Se o elemento for um dos que estão sendo comparados, ganha cor Amarela (\033[33m)
        if (i == idx1 || i == idx2) {
            std::cout << "\033[33m" << v[i] << "\033[0m ";
        } else {
            i != n -1 ? std::cout << v[i] << " " : std::cout << v[i];
        }
    }
    std::cout << "]" << std::endl;
}

void Sort::bubble(int v[], int n, bool i = false) {
    int temp;
    std::cout << std::endl;

    for (int k = 0; k < n - 1; k++)
    {
        for (int j = 0; j < n - 1 - k; j++)
        {
            if (v[j] > v[j + 1])
            {
                if (i) {
                    // Apaga a linha anterior
                    std::cout << "\033[F\033[K";
                    imprimirVetor(v, n, k, j, true);
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                if (i) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }
            }
        }
    }

    if (i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        // Apaga a linha anterior
        std::cout << "\033[F\033[K";
        std::cout << "Lista ordenada: ";
        imprimirVetor(v, n);
    }
}