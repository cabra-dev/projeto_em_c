#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estoque.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        opcao = -1; // <--- ADICIONE ISSO (Evita o loop infinito se digitar errado)

        printf("\n=== SISTEMA DE ESTOQUE DA UNIPE ===\n"); // Ajustei o texto
        printf("1. Cadastrar Produto\n"); // Corrigido "Produtdo"
        printf("2. Movimentacao (Entrada/Saida)\n");
        printf("3. Consultar Produto\n"); // Removido o ")" estranho
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