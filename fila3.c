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
        return f->valor;
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

fila intercala(fila f1, fila f2)
{
    fila f3 = NULL;
    while (f1 != NULL || f2 != NULL)
    {
        if (f1 != NULL)
        {
            f3 = enqueue(f3, peek(f1));
        }
        if (f2 != NULL)
        {
            f3 = enqueue(f3, peek(f2));
        }

        f1 = dequeue(f1);
        f2 = dequeue(f2);
    }
    return f3;
}

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");

    printf("\t 1 - inserir na fila 1\n");

    printf("\t 2 - inserir na fila 2\n");

    printf("\t 99 - parar de inserir\n");
}

int main(int argc, char **argv)
{
    int opcao;
    int valor;

    fila f1 = NULL;
    fila f2 = NULL;
    fila f3 = NULL;
    int flag = 1;

    while (flag)
    {
        menu_opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser enfileirado na fila 1:\n");
            scanf("%d", &valor);
            f1 = enqueue(f1, valor);
            printf("Valor enfileirado!\n");
            break;
        case 2:
            printf("Digite o valor a ser enfileirado na fila 2:\n");
            scanf("%d", &valor);
            f2 = enqueue(f2, valor);
            printf("Valor enfileirado!\n");
            break;
        case 99:
            flag = 0;
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }

    f3 = intercala(f1, f2);
    print(f3);
}