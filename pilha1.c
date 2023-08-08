#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int *elementos;
    int topo;
    int capacidade;
};

void inicializar(struct pilha *p, int capacidade)
{
    p->elementos = (int *)malloc(sizeof(int) * capacidade);
    p->topo = -1;
    p->capacidade = capacidade;
}

int isEmpty(struct pilha *p)
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct pilha *p, int valor)
{
    if (p->topo == p->capacidade - 1)
    {
        return 0;
    }
    else
    {
        p->elementos[++p->topo] = valor;
        return 1;
    }
}

int top(struct pilha *p)
{
    if (isEmpty(p) == 1)
    {
        return 0;
    }
    else
    {
        return p->elementos[p->topo];
    }
}

int pop(struct pilha *p)
{
    if (isEmpty(p) == 1)
    {
        return 0;
    }
    else
    {
        p->topo--;
        return 1;
    }
}

void print(struct pilha *p)
{
    int i;
    for (i = 0; i <= p->topo; i++)
    {
        printf("[%d]", p->elementos[i]);
    }
    printf("\n");
}

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");

    printf("\t 0 - inicializar\n");

    printf("\t 1 - push\n");

    printf("\t 2 - pop\n");

    printf("\t 3 - top\n");

    printf("\t 4 - isEmpty\n");

    printf("\t 5 - print\n");

    printf("\t 99 - sair\n");
}
int main(int argc, char **argv)
{
    int valor;
    int capacidade;
    int opcao;

    // declaracao da pilha
    struct pilha *p1;
    p1 = (struct pilha *)malloc(sizeof(struct pilha));

    while (1)
    {
        menu_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Digite a capacidade da pilha:\n");
            scanf("%d", &capacidade);
            inicializar(p1, capacidade);
            break;
        case 1:
            printf("Digite o valor a ser inserido no topo:\n");
            scanf("%d", &valor);
            if (push(p1, valor) == 1)
            {
                printf("Valor inserido no topo!\n");
            }
            else
            {
                printf("Valor nao inserido!\n");
            }
            break;
        case 2:
            if (pop(p1) == 1)
            {
                printf("Topo removido!\n");
            }
            else
            {
                printf("Topo nao removido!\n");
            }
            break;
        case 3:
            if (top(p1) == 0)
            {
                printf("Pilha esta vazia!\n");
            }
            else
            {
                printf("Topo: [%d]\n", top(p1));
            }
            break;
        case 4:
            if (isEmpty(p1) == 1)
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
