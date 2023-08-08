#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int *elementos;
    int particao;
    int capacidade;
};

void inicializar(struct fila *f, int capacidade)
{
    f->elementos = (int *)malloc(sizeof(int) * capacidade);
    f->particao = 0;
    f->capacidade = capacidade;
}

int isEmpty(struct fila *f)
{
    if (f->particao > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int enqueue(struct fila *f, int valor)
{
    if (f->particao < f->capacidade)
    {
        f->elementos[f->particao] = valor;
        f->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct fila *f)
{
    if (isEmpty(f) == 1)
    {
        return 0;
    }
    else
    {
        int i;
        for (i = 0; i <= f->particao - 2; i++)
        {
            f->elementos[i] = f->elementos[i + 1];
        }
        f->particao--;
        return 1;
    }
}

int peek(struct fila *f)
{
    if (isEmpty(f) == 1)
    {
        return 0;
    }
    else
    {
        return f->elementos[0];
    }
}

void print(struct fila *f)
{
    int i;
    for (i = 0; i < f->particao; i++)
    {
        printf("[%d]", f->elementos[i]);
    }
    printf("\n");
}

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");

    printf("\t 0 - inicializar\n");

    printf("\t 1 - enqueue\n");

    printf("\t 2 - dequeue\n");

    printf("\t 3 - peek\n");

    printf("\t 4 - isEmpty\n");

    printf("\t 5 - print\n");

    printf("\t 99 - sair\n");
}

int main(int argc, char **argv)
{
    int valor;
    int capacidade;
    int opcao;

    struct fila *f1;
    f1 = (struct fila *)malloc(sizeof(struct fila));

    while (1)
    {
        menu_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Digite a capacidade da fila:\n");
            scanf("%d", &capacidade);
            inicializar(f1, capacidade);
            break;
        case 1:
            printf("Digite o valor a ser enfileirado:\n");
            scanf("%d", &valor);
            if (enqueue(f1, valor) == 1)
            {
                printf("Valor enfileirado!\n");
            }
            else
            {
                printf("Valor nao enfileirado!\n");
            }
            break;
        case 2:
            if (dequeue(f1) == 1)
            {
                printf("Primeiro desenfileirado!\n");
            }
            else
            {
                printf("Primeiro nao desenfileirado\n");
            }
            break;
        case 3:
            if (peek(f1) == 0)
            {
                printf("Fila esta vazia!\n");
            }
            else
            {
                printf("Primeiro: [%d]\n", peek(f1));
            }
            break;
        case 4:
            if (isEmpty(f1) == 1)
            {
                printf("A fila esta vazia!\n");
            }
            else
            {
                printf("A fila nao esta vazia!\n");
            }
            break;
        case 5:
            printf("Fila 1:\n");
            print(f1);
            break;
        case 99:
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    }
}