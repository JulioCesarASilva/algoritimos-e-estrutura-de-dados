# Versão melhorada: fila circular

Esta implementação transforma o exemplo demonstrativo em um programa
interativo de fila circular. Os dados podem ser incluídos, consultados e
removidos pelo menu, e a fila é preservada entre execuções.

## Melhorias implementadas

- menu interativo para operar a fila;
- validação das opções e dos valores numéricos informados;
- mensagens para fila cheia, fila vazia e entradas inválidas;
- consulta e remoção do primeiro elemento da fila;
- armazenamento da fila em `fila.dat` ao sair do programa;
- carregamento automático de `fila.dat` ao iniciar;
- validação básica dos índices carregados, evitando o uso de dados inválidos.

## Capacidade

O vetor interno possui 10 posições, mas uma delas é reservada para distinguir
uma fila cheia de uma fila vazia. Portanto, a fila armazena no máximo **9
inteiros** ao mesmo tempo.

## Compilação e execução

Execute a partir de `versao-melhorada/c`:

```bash
gcc main.c -o ../../../tmp/fila-circular.bin
../../../tmp/fila-circular.bin
```

O executável é criado em `tmp/fila-circular.bin`.

O programa apresenta as opções abaixo:

```text
1 - Mostrar fila
2 - Inserir no final da fila
3 - Remover o primeiro da fila
4 - Mostrar primeiro da fila
0 - Salvar e sair
```

Ao escolher `0`, o estado atual da fila é salvo em `tmp/fila.dat`. Na próxima
execução, esse arquivo é carregado automaticamente. Caso ele não exista, o
programa começa com uma fila vazia.

> Para reiniciar a fila, remova `tmp/fila.dat` antes de executar o programa
> novamente.
