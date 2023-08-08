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
    if (isEmpty(p) == 1)
    {
        pilha novo = (pilha)malloc(sizeof(no));
        novo->valor = valor;
        novo->proximo = p;
        return novo;
    }
    else
    {
        pilha aux = p;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        pilha novo = (pilha)malloc(sizeof(no));
        novo->valor = valor;
        novo->proximo = NULL;

        aux->proximo = novo;
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

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");

    printf("\t 1 - push\n");

    printf("\t 2 - pop\n");

    printf("\t 3 - top\n");

    printf("\t 4 - isEmpty\n");

    printf("\t 5 - print\n");

    printf("\t 99 - sair\n");
}

int main(int argc, char **argv)
{
    int opcao;
    int valor;

    pilha p1 = NULL;

    while (1)
    {
        menu_opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido no topo:\n");
            scanf("%d", &valor);
            p1 = push(p1, valor);
            printf("Valor inserido no topo!\n");
            break;
        case 2:
            if (pop(p1) == NULL)
            {
                printf("Topo nao removido!\n");
            }
            else
            {
                printf("Topo removido!\n");
            }
            break;
        case 3:
            printf("Topo: [%d]\n", top(p1));
            break;
        case 4:
            if (isEmpty(p1))
            {
                printf("A pilha esta vazia!\n");
            }
            else
            {
                printf("A pilha nao esta vazia!\n");
            }
            break;
        case 5:
            printf("Pilha 1:\n");
            print(p1);
            break;
        case 99:
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    }
}
