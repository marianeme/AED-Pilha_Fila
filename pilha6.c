#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef no *pilha;

int isEmpty(pilha p)
{
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

pilha push(pilha p, int valor)
{
    pilha novo = (pilha)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    if (p == NULL)
    {
        return novo;
    }
    else
    {
        pilha aux = p;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        aux->proximo = novo;
        return p;
    }
}

pilha pop(pilha p)
{
    if (isEmpty(p) == 1)
    {
        return NULL;
    }
    else
    {
        pilha aux = p;
        while (aux->proximo->proximo != NULL)
        {
            aux = aux->proximo;
        }
        free(aux->proximo);
        aux->proximo = NULL;
        return p;
    }
}

int top(pilha p)
{
    if (isEmpty(p) == 1)
    {
        return -1;
    }
    pilha aux = p;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    return aux->valor;
}

void solucao(int min, int *caixa)
{
    int i;
    pilha saida = NULL;
    if (min > 1)
    {
        for (i = 0; i < min; i++)
        {
            if (saida != NULL)
            {
                if (caixa[i] == 0)
                {

                    printf("%d  ", top(saida));
                    saida = pop(saida);
                }
            }

            if (caixa[i] > 0)
            {
                saida = push(saida, caixa[i]);
            }
        }
    }
}

void main()
{
    int min;
    printf("Digite os minutos\n");
    scanf("%d", &min);
    int i;
    int *caixa = malloc(min * sizeof(int));

    for (i = 0; i < min; i++)
    {
        printf("Digite o array\n");
        scanf("%d", &caixa[i]);
    }

    solucao(min, caixa);
}
