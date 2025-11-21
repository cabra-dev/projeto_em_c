#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estoque.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        opcao = -1; // Reinicia a opcao para evitar loops indesejados

        printf("\n=== SISTEMA DE ESTOQUE DA UNIPE ===\n"); 
        printf("1. Cadastrar Produto\n"); 
        printf("2. Movimentacao (Entrada/Saida)\n");
        printf("3. Consultar Produto\n");
        printf("4. Relatorio Geral\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: registrarMovimentacao(); break;
            case 3: consultarEstoque(); break;
            case 4: gerarRelatorio(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}