#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char elementos;
    struct no *proximo;
} no;

typedef no *pilha;
typedef no *fila;

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

pilha pop(pilha p)
{
    if (isEmpty(p) == 1 || p->proximo == NULL)
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

pilha push(pilha p, char elementos)
{
    pilha novo = (pilha)malloc(sizeof(no));
    novo->elementos = elementos;
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

char top(pilha p)
{
    if (isEmpty(p) == 1)
    {
        return '?';
    }
    pilha aux = p;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    return aux->elementos;
}

void print(pilha p)
{
    pilha aux = p;
    while (aux != NULL)
    {
        printf("%c", aux->elementos);
        aux = aux->proximo;
    }

    printf("\n");
}

fila enqueue(fila f, char elementos)
{
    fila novo = (fila)malloc(sizeof(no));
    novo->elementos = elementos;
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
    if (f == NULL)
    {
        return -1;
    }
    else
    {
        return f->elementos;
    }
}

int main()
{
    char biblioteca[100];
    int i;
    char elementos;

    printf("Biblioteca: \n");
    fgets(biblioteca, 100, stdin);

    pilha p = NULL;
    fila f = NULL;
    for (i = 0; i < strlen(biblioteca); i++)
    {
        if (biblioteca[i] == '\\')
        {
            while (top(p) != '/')
            {
                f = enqueue(f, top(p));
                p = pop(p);
            }
            p = pop(p);
            while (f != NULL)
            {
                p = push(p, peek(f));
                f = dequeue(f);
            }
        }
        else
        {
            p = push(p, biblioteca[i]);
        }
    }
    print(p);
}