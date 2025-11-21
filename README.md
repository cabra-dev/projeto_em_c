# Sistema de Controle de Estoque - UNIPÊ 📦

> Projeto avaliativo desenvolvido para a disciplina de Técnicas e Desenvolvimento de Algoritmos.

## 📝 Sobre o Projeto
Este é um sistema de gerenciamento de estoque desenvolvido em linguagem C. O objetivo é aplicar conceitos de **modularização**, **structs** e **matrizes** para criar uma aplicação de console funcional.

O sistema permite o cadastro de produtos, controle de fluxo (entradas e saídas) e auditoria através de relatórios.

## 🚀 Funcionalidades
Conforme os requisitos do projeto, o sistema realiza:

1.  **Cadastro de Produtos:** Armazena código, nome, preço e quantidade em um vetor de estruturas.
2.  **Movimentação de Estoque:**
    * Registra **Entradas** (aumenta estoque).
    * Registra **Saídas** (diminui estoque com validação de saldo).
    * Utiliza uma **Matriz** para salvar o histórico (Log).
3.  **Consulta:** Busca rápida de produtos pelo código.
4.  **Relatório Geral:** Exibe todas as movimentações feitas (Data, Tipo, Produto e Quantidade).

## 📂 Estrutura dos Arquivos
O projeto foi modularizado para melhor organização:

* `main.c`: Arquivo principal (Menu e controle de fluxo).
* `estoque.c`: Implementação das funções e lógica.
* `estoque.h`: Cabeçalho (Definição das structs e protótipos).

## 💻 Como Compilar e Rodar
Como o projeto é dividido em múltiplos arquivos, é necessário compilar o `main.c` junto com o `estoque.c`.

### Passo 1: Compilação
*Abra o terminal na pasta do projeto e digite.
`gcc main.c estoque.c -o sistema_estoque`

### Passo 2: Execução
* Após compilar, rode o executável gerado.
* No Windows (PowerShell/CMD).
`.\sistema_estoque.exe`

* No Linux/Mac.
`./sistema_estoque`

\\ (retire os ´´ quando for realizar a execução) \\

## ⚠️ Instrução de Uso (Formato de Data)
O sistema utiliza o padrão de leitura de inteiros do C. Ao digitar datas, utilize espaço para separar o dia do mês.

✅ Correto: 15 06 (Dia 15, Mês 06)
❌ Errado: 15/06 (Isso pode causar erro na leitura)

## 👨‍💻 Autores
[Eduardo]
[Matheus]

## 📄 Licença
Uso livre para fins de estudo e aperfeiçoamento.
Instituição: UNIPÊ - Centro Universitário de João Pessoa
Disciplina: Técnicas e Desenvolvimento de Algoritmos