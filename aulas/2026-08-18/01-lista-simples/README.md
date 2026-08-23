# Exercício — Lista simples

Exercício desenvolvido em aula para implementar uma lista simples de números reais. Cada nó armazena um valor e um ponteiro para o próximo elemento.

- `cpp/lista.hpp`: declara o nó e a interface da classe `Lista`.
- `cpp/lista.cpp`: implementa as operações da lista.
- `cpp/main.cpp`: apresenta um exemplo de uso da classe.

## Operações disponíveis

- `insere(float num)`: insere um valor no fim da lista;
- `insere(float num, int indice)`: insere um valor no índice informado;
- `remove(float num)`: remove a primeira ocorrência do valor informado;
- `remove(int indice)`: remove e retorna o valor do índice informado;
- `limpa()`: remove todos os nós da lista.
- `listar()`: lista todos os nós da lista.


## Compilação e execução

Execute os comandos **a partir da pasta com os codigos de suas respectivas linguagens**:

### C++

```bash
g++ main.cpp lista.cpp lista.hpp -o ../../tmp/main.bin
../../tpm/main.bin
```

Usar a pasta `tmp` para o arquivo compilado evita misturar artefatos de compilação com os códigos-fonte do repositório.
