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

void reverso(char string[])
{
    int i;
    pilha p = NULL;
    for (i = 0; i < strlen(string)-1; i++)
    {
        p = push(p, string[i]);
    }
    for (i = 0; i < strlen(string)-1; i++)
    {
        string[i] = top(p);
        p = pop(p);
    }
}

void remover_espacos(char string[])
{
    int contador = 0;
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
           string[contador] = string[i];
           contador++;
        }
    }
    string[contador] = '\0';
}
void main()
{
    char str1[100]; 
    printf("Digite uma frase/palavra: \n");
    fgets(str1, 100, stdin);
    remover_espacos(str1);   
    char str2[100];     
    strcpy(str2, str1); 
    reverso(str1);    
    if (strcmpi(str1, str2) == 0)
    {
        printf("E um palindromo!\n");
    }
    else
    {
        printf("Nao e um palindromo!\n");
    }
}
