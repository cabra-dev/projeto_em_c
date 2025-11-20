#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>

// Constantes globais
#define MAX_PRODUTOS 50
#define MAX_MOVIMETACOES 100
#define NOME_MAX 50

// Estrutura do Produto
typedef struct {
    int codigo;
    char nome[NOME_MAX];
    float preco;
    int quantidade;
} Produto;

// Protótipo das Funções
void inicializarSistema();
void cadastrarProduto();
void registrarMovimentacao();
void consultarEstoque();
void gerarRelatorio();
void limparBuffer();

#endif