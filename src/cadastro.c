#include <stdio.h>
#include <string.h>
#include "../include/cadastro.h"

// Vetor globbal de Produtos
Produto produtos[MAX_PRODUTOS];
int total_produtos = 0;

// Busca um produto pelo código
int buscarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Cadastra um novo produto
void cadastrarProduto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! (%d). \n", MAX_PRODUTOS);
        return;
    }

    Produto p;
    printf("\n--- Cadastro de Produto ---\n");
    printf("Código (inteiro): ");
    if (scanf("%d", &p.codigo) !=1) {
        printf("Entrada inválida para o código.\n");
        while(getchar() != '\n'); // Limpa o buffer de entrada
        return;
    }

    while(buscarProdutoPorCodigo(p.codigo) != -1) {
        printf("Já existe um produto com esse código. Digite outro código %d. \n", p.codigo);
        return;
    }

    printf("Nome: ");
    if (fgets(p.nome, MAX_NOME, stdin) == NULL) {
        printf("Erro ao ler o nome do produto.\n");
        return;
    }

    size_t ln = strlen(p.nome);
    if (ln > 0 && p.nome[ln - 1] == '\n') p.nome[ln - 1] = '\0';
    printf("Preço (ex: 19.99): ");
    if (scanf("%f", &p.preco) != 1) {
        printf("Entrada inválida para o preço.\n");
        while(getchar() != '\n'); // Limpa o buffer de entrada
        return;
    }

    printf("Quantidade inicial (inteiro): ");
    if (scanf("%d", &p.quantidade) != 1) {
        printf("Entrada inválida para a quantidade.\n");
        while(getchar() != '\n'); // Limpa o buffer de entrada
        return;
    }
    while (getchar() != '\n'); // Limpa o buffer de entrada
    produtos [total_produtos++] = p;
    printf("Produto cadastrado com sucesso! (posição %d)\n", total_produtos - 1);
}