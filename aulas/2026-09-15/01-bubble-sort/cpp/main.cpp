#include <iostream>
#include "sort.hpp"

int main() {
    int v[] = {90, 64, 34, 25, 12, 22, 11};
    const int n = sizeof(v) / sizeof(v[0]);

    Sort sort;
    
    sort.bubble(v, n, true);

    std::cout << std::endl;

    return 0;
}
