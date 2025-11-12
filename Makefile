# Makefile
# Este arquivo instrui o computador como COMPILAR o programa

# Compilador a usar
CC = gcc 
CFLASGS = - Wall -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = build/estoque

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)
	@echo "✓ Compilação concluída: $(TARGET)"

run: all
	@echo "✓ Executando o programa..."
	@./$(TARGET)

clean: all
	@echo "✓ Limpando arquivos compilados..."
	rm -rf build/*.o build/estoque

# ALVO: help
# Mostra as opções disponíveis
help:
	@echo "Comandos disponíveis:"
	@echo "  make        - Compila o programa"
	@echo "  make run    - Compila e executa"
	@echo "  make clean  - Remove arquivos compilados"
	@echo "  make help   - Mostra esta mensagem"

.PHONY: all run clean help
