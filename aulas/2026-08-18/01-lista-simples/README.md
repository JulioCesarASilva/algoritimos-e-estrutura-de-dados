# Exercício — Lista simples

Exercício desenvolvido em aula para implementar uma lista simplesmente ligada de números reais. Cada nó armazena um valor e um ponteiro para o próximo elemento.

- `cpp/lista.hpp`: declara o nó e a interface da classe `Lista`.
- `cpp/lista.cpp`: implementa inserção no fim, remoção por valor e limpeza.

A lista libera todos os nós no destrutor, evitando vazamento da memória alocada durante as inserções.


## Compilação e execução

Execute os comandos **a partir da pasta com os codigos de suas respectivas linguagens**:

### C++

```bash
g++ main.cpp -o ../../tpm/main.bin
../../tpm/main.bin
```

Usar a pasta `tmp` para o arquivo compilado evita misturar artefatos de compilação com os códigos-fonte do repositório.
