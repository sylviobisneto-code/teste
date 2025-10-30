
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Ingresso {
    char nomeCliente[50];
    char setor[20];
    int numero;
    float valor;
    struct Ingresso *prox;
    struct Ingresso *ant;
} Ingresso;

Ingresso *inicio = NULL;
Ingresso *fim = NULL;

void cadastrarIngresso() {
    Ingresso *novo = (Ingresso*) malloc(sizeof(Ingresso));

    printf("Nome do cliente: ");
    scanf(" %49[^\n]", novo->nomeCliente);

    printf("Setor: ");
    scanf(" %19[^\n]", novo->setor);

    printf("Numero do ingresso: ");
    scanf("%d", &novo->numero);

    printf("Valor do ingresso: ");
    scanf("%f", &novo->valor);

    novo->prox = NULL;
    novo->ant = fim;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }
    fim = novo;

    printf("Ingresso cadastrado com sucesso!\n");
}

void listarIngressos() {
    Ingresso *temp = inicio;
    if (temp == NULL) {
        printf("Nenhum ingresso cadastrado.\n");
        return;
    }

    while (temp != NULL) {
        printf("Cliente: %s | Setor: %s | Numero: %d | Valor: %.2f\n",
               temp->nomeCliente, temp->setor, temp->numero, temp->valor);
        temp = temp->prox;
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Ingressos ---\n");
        printf("1 - Cadastrar ingresso\n");
        printf("2 - Listar ingressos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarIngresso(); break;
            case 2: listarIngressos(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
