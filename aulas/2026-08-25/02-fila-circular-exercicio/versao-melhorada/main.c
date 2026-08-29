#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAMANHO 10   // Capacidade máxima (uma posição fica reservada)

// Estrutura da fila circular
typedef struct {
    int itens[TAMANHO];
    int frente;      // Índice do primeiro elemento
    int tras;        // Índice onde o próximo elemento será inserido
} Fila;

// Inicializa a fila (frente = tras = 0)
void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

// Verifica se a fila está vazia
bool isEmpty(Fila *f) {
    return f->frente == f->tras;
}

// Verifica se a fila está cheia (circular)
bool isFull(Fila *f) {
    return (f->tras + 1) % TAMANHO == f->frente;
}

// Insere um elemento no final da fila (enqueue)
bool enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        printf("Erro: fila cheia!\n");
        return false;
    }

    f->itens[f->tras] = valor;
    f->tras = (f->tras + 1) % TAMANHO;

    return true;
}

// Retira o elemento do início da fila (dequeue)
bool dequeue(Fila *f, int *valor) {
    if (isEmpty(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }

    *valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % TAMANHO;

    return true;
}

// Consulta o primeiro elemento sem remover (front)
bool front(Fila *f, int *valor) {
    if (isEmpty(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }

    *valor = f->itens[f->frente];

    return true;
}

// Exibe todos os elementos da fila (do início ao fim)
void exibir(Fila *f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila (início -> fim): ");

    int i = f->frente;

    while (i != f->tras) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % TAMANHO;
    }

    printf("\n");
}

// Salva a fila inteira no arquivo
bool salvar_binario(const Fila *f) {
    FILE *arquivo = fopen("fila.dat", "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir fila.dat");
        return false;
    }

    if (fwrite(f, sizeof(Fila), 1, arquivo) != 1) {
        printf("Erro ao salvar a fila.\n");
        fclose(arquivo);
        return false;
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar fila.dat.\n");
        return false;
    }

    return true;
}

// Carrega a fila inteira do arquivo
bool carregar_binario(Fila *f) {
    FILE *arquivo = fopen("fila.dat", "rb");

    if (arquivo == NULL) {
        // Não existe arquivo salvo: começa com uma fila vazia
        inicializar(f);
        return false;
    }

    Fila temporaria;

    if (fread(&temporaria, sizeof(Fila), 1, arquivo) != 1) {
        printf("Erro ao carregar a fila.\n");
        fclose(arquivo);
        inicializar(f);
        return false;
    }

    fclose(arquivo);

    // Validação contra arquivo inválido ou corrompido
    if (temporaria.frente < 0 || temporaria.frente >= TAMANHO ||
        temporaria.tras < 0 || temporaria.tras >= TAMANHO) {
        printf("Arquivo de fila inválido.\n");
        inicializar(f);
        return false;
    }

    *f = temporaria;

    return true;
}

// Limpa buffer do teclado
void limpar_buffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpa terminal
void limpar_terminal(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu(void) {
    limpar_terminal();

    printf("=== Fila ===\n");
    printf("1 - Mostrar fila\n");
    printf("2 - Inserir no final da fila\n");
    printf("3 - Remover remover o primeiro da fila\n");
    printf("4 - Mostrar primeiro da fila\n");
    printf("0 - Salvar e sair\n");
    printf("Escolha uma opção: ");
}


int main() {
    Fila minhaFila;
    int opcao, valor;
    bool sair = false;

    // Tenta buscar a fila. Se não existir nada, cria outra.
    carregar_binario(&minhaFila);

    while (!sair) {
        menu();

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();

            printf("Opção inválida! Tente novamente.\n");
            printf("Pressione Enter para continuar...");
            getchar();

            continue;
        }

        // Limpa o ENTER que ficou no console
        limpar_buffer();

        switch (opcao) {
            case 0: // Sair
                if (salvar_binario(&minhaFila)) {
                    printf("Fila salva com sucesso.\n");
                }

                printf("Encerrando o programa.\n");
                sair = true;
                break;

            case 1: // Mostrar Fila
                exibir(&minhaFila);

                printf("\nPressione Enter para continuar...");
                getchar();

                break;

            case 2:
                printf("Numero a inserir: ");

                if (scanf("%d", &valor) == 1) {
                    // Limpa o numero que ficou no console
                    limpar_buffer();

                    enqueue(&minhaFila, valor);
                } else {
                    // Limpa o qualquer bagaça que ficou no console
                    limpar_buffer();

                    printf("Numero inválido!\n");
                }

                printf("Pressione Enter para continuar...");
                getchar();

                break;

            case 3:
                if (dequeue(&minhaFila, &valor)) {
                    printf("Numero removido: %d\n", valor);
                }
                
                printf("Pressione Enter para continuar...");
                getchar();

                break;

            case 4:
                if (front(&minhaFila, &valor)) {
                    printf("Primeiro numero: %d\n", valor);
                }

                printf("Pressione Enter para continuar...");
                getchar();

                break;

            default:
                printf("Opção inválida! Tente novamente.\n");

                printf("Pressione Enter para continuar...");
                getchar();

                break;
        }
    }

    return 0;
}
