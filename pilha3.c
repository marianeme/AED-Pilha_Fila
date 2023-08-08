#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char elementos;
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
        printf("%c ", aux->elementos);
        aux = aux->proximo;
    }

    printf("\n");
}

int main()
{
    char equacao[50];
    int i;
    char elementos;

    printf("Digite uma equacao matematica: \n");
    fgets(equacao, 50, stdin);

    pilha p = NULL;
    for (i = 0; i < strlen(equacao); i++)
    {
        if (equacao[i] == '{' || equacao[i] == '[' || equacao[i] == '(')
        {
            p = push(p, equacao[i]);
        }
        else if (equacao[i] == '}' || equacao[i] == ']' || equacao[i] == ')')
        {
            if ((top(p) == '{' && equacao[i] == '}') || (top(p) == '[' && equacao[i] == ']') || (top(p) == '(' && equacao[i] == ')'))
            {
                p = pop(p);
            }
            else
            {
                printf("Nao esta balanceada!\n");
                return 0;
            }
        }
    }
    if (isEmpty(p))
    {
        printf("Esta balanceada!\n");
    }
    else
    {
        printf("Nao esta balanceada!\n");
    }
    
    return 0;
}
