#ifndef CADASTRO_H
#define CADASTRO_H

#define MAX_PRODUTOS 100
#define MAX_NOME 60

// Estrutura para armazenar informações do produto
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    float preco;
    int quantidade;
} Produto;

// Variável global para armazenar os produtos cadastrados
extern Produto produtos[MAX_PRODUTOS];
extern int total_produtos;


// Protótipos das funções
void cadastrarProduto();
void listarProdutos();
void consultarProduto();
int buscarProdutoPorCodigo(int codigo);

#endif