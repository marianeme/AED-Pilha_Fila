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

// topo é o fim da pilha

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

void print(pilha p)
{
    pilha aux = p;
    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}

void fibonacci(int n)
{
    int ultimo = 1;
    int penultimo = 0;
    int i;
    int numero;
    pilha p = NULL;

    if (n < 1)
    {
        printf("Numero invalido!\n");
    }

    for (i = 0; i < n; i++)
    {

        if (i == 1)
        {
            p = push(p, 0);
            p = push(p, 1);
        }

        if (i >= 2)
        {
            numero = ultimo + penultimo;
            p = push(p, numero);
            penultimo = ultimo;
            ultimo = numero;
        }
    }
    print(p);
}

int main()
{
    int rep;

    printf("Digite um numero: ");
    scanf("%d", &rep);
    printf("Sequencia fibonacci:\n");
    fibonacci(rep);

    return 0;
}