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

void solucao(int *array_A, int *array_B, int N)
{
    int i;
    int contagem = 0;
    fila arrayA = NULL;
    fila arrayB = NULL;

    for (i = 0; i < N; i++)
    {
        arrayA = enqueue(arrayA, array_A[i]);
        arrayB = enqueue(arrayB, array_B[i]);
    }

    while (arrayA != NULL && arrayB != NULL)
    {
        if (peek(arrayA) == peek(arrayB))
        {
            arrayA = dequeue(arrayA);
            arrayB = dequeue(arrayB);
        }
        else
        {
            arrayA = enqueue(arrayA, peek(arrayA));
            arrayA = dequeue(arrayA);
        }
        contagem++;
    }
    printf("Quantidade de Operacoes: %d\n", contagem);
}

void main()
{
    int N;
    printf("Digite o tamanho dos arrays:\n");
    scanf("%d", &N);
    int i;
    int *array_A = malloc(N * sizeof(int));
    int *array_B = malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        printf("Digite os valores para o array_a:\n");
        scanf("%d", &array_A[i]);
    }

    for (i = 0; i < N; i++)
    {
        printf("Digite os valores para o array_b:\n");
        scanf("%d", &array_B[i]);
    }
    solucao(array_A, array_B, N);
}