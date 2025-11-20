#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

Produto listaProdutos[MAX_PRODUTOS]; 
int totalProdutos = 0;
int matrizMovimentacao[MAX_MOVIMENTACOES][5];
int totalMovimentacoes = 0; 

// Função auxiliar para buscar índice
int buscarIndiceProduto(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (listaProdutos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastro de Produtos
void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("\n Capacidade maxima atingida!\n");
        return;
    }

    Produto p;
    printf("\n--- CADASTRO DE PRODUTOS ---\n");
    printf("Digite o codigo: ");
    scanf("%d", &p.codigo);
    limparBuffer();

    if (buscarIndiceProduto(p.codigo) != -1) {
        printf("O codigo ja existe!\n");
        return;
    }

    printf("Digite o nome: ");
    fgets(p.nome, NOME_MAX, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o preco: ");
    scanf("%f", &p.preco);

    printf("Digite a quantidade inicial: ");
    scanf("%d", &p.quantidade);

    listaProdutos[totalProdutos] = p;
    totalProdutos++;
    printf("Produto cadastrado com sucesso!\n");
}

// Movimentação de Entrada e Saida do Produto
void registrarMovimentacao() {
    if (totalMovimentacoes >= MAX_MOVIMENTACOES) {
        printf("\n Historico cheio!\n");
        return;
    }
    int codigo, tipo, qtd, dia, mes;

    printf("\n --- REGISTRAR MOVIMENTACAO ---\n");
    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    int i = buscarIndiceProduto(codigo);
    if (i == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Produto: %s | Saldo Atual: %d\n", listaProdutos[i].nome, listaProdutos[i].quantidade);
    printf("Tipo (1-Entrada / 2-Saida): ");
    scanf("%d", &tipo);

    if (tipo != 1 && tipo != 2) {
        printf("Tipo invalido\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    // Lógica de atualização do saldo
    if (tipo == 1) {
        listaProdutos[i].quantidade += qtd; // Entrada
    } else {
        if (qtd > listaProdutos[i].quantidade) {
            printf("Saldo insuficiente!\n");
            return;
        }
        listaProdutos[i].quantidade -= qtd; 
    }

    printf("Data (Dia Mes): ");
    scanf("%d %d", &dia, &mes);

    // Gravação na Matriz
    matrizMovimentacao[totalMovimentacoes][0] = codigo;
    matrizMovimentacao[totalMovimentacoes][1] = tipo;
    matrizMovimentacao[totalMovimentacoes][2] = qtd;
    matrizMovimentacao[totalMovimentacoes][3] = dia;
    matrizMovimentacao[totalMovimentacoes][4] = mes;
    totalMovimentacoes++;

    printf("Movimentacao registrada com sucesso!\n");
}

// Consulta de Estoque
void consultarEstoque() {
    int codigo;
    printf("\n--- CONSULTAR ESTOQUE ---\n");
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i = buscarIndiceProduto(codigo);
    if (i == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("\n Produto: %s\n", listaProdutos[i].nome);
    printf("\n Preco: R$ %.2f\n", listaProdutos[i].preco);
    printf("\n Quantidade em Estoque: %d\n", listaProdutos[i].quantidade);

    // Verificação do Status do Produto
    if (listaProdutos[i].quantidade == 0) {
        printf("Esgotado\n");
    } else {
        printf("Disponivel\n");
    }
}

// Relatorio
void gerarRelatorio() {
    printf("\n--- RELATORIO DE MOVIMENTACOES ---\n");
    printf("DATA\tTIPO\tPRODUTO(ID)\tQUANTIDADE\n");

    for(int i = 0; i < totalMovimentacoes; i++) {
        int cod = matrizMovimentacao[i][0];
        int tipo = matrizMovimentacao[i][1];
        int qtd = matrizMovimentacao[i][2];
        int dia = matrizMovimentacao[i][3];
        int mes = matrizMovimentacao[i][4];

        char desc[10];
        if (tipo == 1) strcpy(desc, "ENTRADA");
        else strcpy(desc, "SAIDA"); 
        
        printf("%02d/%02d\t%s\t%d\t\t%d\n", dia, mes, desc, cod, qtd);
    }
}