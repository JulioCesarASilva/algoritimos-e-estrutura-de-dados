#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 10
typedef struct
{
    int itens[TAMANHO];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p)
{
    p->topo = -1;
}

// Verifica se está vazia
bool isEmpty(Pilha *p)
{
    return p->topo == -1;
}

// Verifica se está cheia
bool isFull(Pilha *p)
{
    return p->topo == TAMANHO - 1;
}

// Inserir (push)
bool push(Pilha *p, int valor)
{
    if (isFull(p))
    {
        printf("❌ Erro: pilha cheia! Não é possível inserir.\n");
        return false;
    }
    p->itens[++(p->topo)] = valor;
    return true;
}

// Remover (pop)
bool pop(Pilha *p, int *valor)
{
    if (isEmpty(p))
    {
        printf("❌ Erro: pilha vazia! Não há o que remover.\n");
        return false;
    }
    *valor = p->itens[(p->topo)--];
    return true;
}

// Consultar topo (opcional)
bool top(Pilha *p, int *valor)
{
    if (isEmpty(p))
    {
        return false;
    }
    *valor = p->itens[p->topo];
    return true;
}

// Exibe a pilha do topo para a base
void exibir(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("📭 Pilha está vazia.\n");
        return;
    }
    printf("📊 Pilha (topo → base): ");
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Menu interativo
void menu()
{
    printf("\n=== TESTADOR DE PILHA ===\n");
    printf("1 - Inserir (push)\n");
    printf("2 - Remover (pop)\n");
    printf("3 - Ver topo\n");
    printf("4 - Exibir pilha\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    Pilha minhaPilha;
    inicializar(&minhaPilha);

    int opcao, valor, removido;
    bool sair = false;

    while (!sair)
    {
        exibir(&minhaPilha); // Mostra o estado atual antes de cada ação
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Inserir
            printf("Digite o valor inteiro para inserir: ");
            scanf("%d", &valor);
            if (push(&minhaPilha, valor))
            {
                printf("✅ Inserido %d com sucesso.\n", valor);
            }
            break;

        case 2: // Remover
            if (pop(&minhaPilha, &removido))
            {
                printf("🗑️  Removido %d do topo.\n", removido);
            }
            break;

        case 3: // Ver topo
            if (top(&minhaPilha, &valor))
            {
                printf("🔝 Topo da pilha: %d\n", valor);
            }
            else
            {
                printf("⚠️  Pilha vazia, não há topo.\n");
            }
            break;

        case 4: // Exibir (já é mostrado automaticamente, mas repetimos)
            exibir(&minhaPilha);
            break;

        case 0: // Sair
            printf("Encerrando o programa. Até logo!\n");
            sair = true;
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        printf("\n"); // Linha em branco para separar iterações
    }

    return 0;
}
