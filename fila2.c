#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef no *fila;

int isEmpty(fila f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

fila enqueue(fila f, int valor)
{
    fila novo = (fila)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    if (f == NULL)
    {
        return novo;
    }
    else
    {
        fila aux = f;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        aux->proximo = novo;
        return f;
    }
}

fila dequeue(fila f)
{
    if (f == NULL)
    {
        return NULL;
    }

    fila aux = f->proximo;
    free(f);
    return aux;
}

int peek(fila f)
{
    if (isEmpty(f) == 1)
    {
        return -1;
    }
    else
    {
        fila aux = f;
        return aux->valor;
    }
}

void print(fila f)
{
    fila aux = f;
    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");

    printf("\t 1 - enqueue\n");

    printf("\t 2 - dequeue\n");

    printf("\t 3 - peek\n");

    printf("\t 4 - isEmpty\n");

    printf("\t 5 - print\n");

    printf("\t 99 - sair\n");
}

int main(int argc, char **argv)
{
    int opcao;
    int valor;

    fila f1 = NULL;

    while (1)
    {
        menu_opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser enfileirado:\n");
            scanf("%d", &valor);
            f1 = enqueue(f1, valor);
            printf("Valor enfileirado!\n");
            break;
        case 2:
            if (isEmpty(f1))
            {
                printf("Primeiro nao removido!\n");
            }
            else
            {
                f1 = dequeue(f1);
                printf("Primeiro removido!\n");
            }
            break;
        case 3:
            printf("Primeiro: [%d]\n", peek(f1));
            break;
        case 4:
            if (isEmpty(f1))
            {
                printf("A fila esta vazia!\n");
            }
            else
            {
                printf("A fila nao esta vazia!\n");
            }
            break;
        case 5:
            printf("fila 1:\n");
            print(f1);
            break;
        case 99:
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    }
}
