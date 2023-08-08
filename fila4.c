#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char elementos[150];
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

fila enqueue(fila f, char *elementos)
{
    fila novo = (fila)malloc(sizeof(no));
    strcpy(novo->elementos, elementos);
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

char *peek(fila f)
{
    if (isEmpty(f) == 1)
    {
        return "/";
    }
    else
    {
        return f->elementos;
    }
}

void print(fila f)
{
    fila aux = f;
    while (aux != NULL)
    {
        printf("[%s]", aux->elementos);
        aux = aux->proximo;
    }

    printf("\n");
}

int main()
{
    fila f = NULL;
    fila aux = NULL;
    int i;
    int numero;

    char string1[150];
    char string2[150];

    printf("Digite o numero:\n");
    scanf("%d", &numero);

    printf("Resultado:\n");
    f = enqueue(f, "1");
    for (i = 0; i < numero; i++)
    {
        strcpy(string1, peek(f));
        f = dequeue(f);
        printf("%s ", string1);
        strcpy(string2, string1);
        strcat(string1, "0");
        strcat(string2, "1");
        f = enqueue(f, string1);
        f = enqueue(f, string2);
    }
}
