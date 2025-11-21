# Sistema de Controle de Estoque - UNIPÊ 📦

> Projeto avaliativo desenvolvido para a disciplina **Técnicas e Desenvolvimento de Algoritmos**.

---

## 📝 Sobre o Projeto

Este sistema foi desenvolvido em linguagem **C** com foco em aplicar conceitos fundamentais de programação estruturada, tais como:

* Modularização (arquivos `.c` e `.h`)
* Estruturas (`struct`)
* Matrizes e vetores
* Validação de dados
* Interação via console

Ele simula um **controle básico de estoque**, permitindo que o usuário cadastre produtos, registre entradas/saídas e visualize relatórios completos de movimentações.

---

## 🚀 Funcionalidades

O sistema oferece as seguintes operações:

### **1. Cadastro de Produtos**

Armazena em vetor:

* Código
* Nome
* Preço
* Quantidade

Inclui validação para evitar códigos duplicados.

### **2. Movimentação de Estoque**

Registra:

* **Entrada** (aumenta estoque)
* **Saída** (valida o saldo antes de remover)

Todas as movimentações são salvas em uma **matriz de log**, contendo:

```
[código, tipo (1=Entrada / 2=Saída), quantidade, dia, mês]
```

### **3. Consulta de Produtos**

Busca por código e exibe:

* Nome
* Preço
* Quantidade
* Status (Disponível / Esgotado)

### **4. Relatório Geral**

Mostra o histórico completo das movimentações, incluindo data e tipo.

---

## 📂 Estrutura do Projeto

```
📁 projeto-estoque-c
 ├── main.c          # Gerencia o menu e fluxo principal
 ├── estoque.c       # Funções de lógica e operações do estoque
 ├── estoque.h       # Cabeçalho com constantes, structs e protótipos
 └── README.md       # Documentação
```

---

## 💻 Como Compilar e Executar

Como o projeto é modular, compile **todos os arquivos juntos**.

### 🔧 Passo 1: Compilar

```bash
gcc main.c estoque.c -o sistema_estoque
```

### ▶️ Passo 2: Executar

#### **Windows (PowerShell/CMD):**

```bash
./sistema_estoque.exe
```

#### **Linux/Mac:**

```bash
./sistema_estoque
```

---

## ⚠️ Observação Importante Sobre Datas

A entrada da data deve ser feita com espaço entre dia e mês:

```
✔ Correto: 15 06
✘ Errado: 15/06
```

O formato "15/06" não é reconhecido pela função `scanf` e causará erro de leitura.

---

## 👨‍💻 Autores

* **Eduardo**
* **Matheus**

---

## 📄 Licença

Uso livre para fins acadêmicos e aperfeiçoamento.

**Instituição:** UNIPÊ — Centro Universitário de João Pessoa
**Disciplina:** Técnicas e Desenvolvimento de Algoritmos
