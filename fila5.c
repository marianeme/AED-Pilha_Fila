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

void solucao(int dias, int *entrada)
{
    int i;
    fila torre = NULL;
    fila reserva = NULL;
    int maior = dias;

    for (i = 0; i < dias; i++)
    {
        if (entrada[i] == maior)
        {
            torre = enqueue(torre, entrada[i]);
            fila aux = reserva;
            while (aux != NULL)
            {
                if (aux->valor == maior - 1)
                {
                    torre = enqueue(torre, aux->valor);
                    maior = maior - 1;
                }
                else
                {
                    reserva = enqueue(reserva, aux->valor);
                }
                aux = aux->proximo;
            }
            reserva = dequeue(reserva);

            print(torre);
            maior = maior - 1;
            while (torre != NULL)
            {
                torre = dequeue(torre);
            }
        }
        else
        {
            reserva = enqueue(reserva, entrada[i]);
            printf("\n");
        }
    }
}

void main()
{
    int dias;
    printf("Digite a quantidade de dias\n");
    scanf("%d", &dias);
    int i;
    int *entrada = malloc(dias * sizeof(int));

    for (i = 0; i < dias; i++)
    {
        printf("Digite o tamanho do disco\n");
        scanf("%d", &entrada[i]);
    }

    solucao(dias, entrada);
}