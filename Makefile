# Nome do executável final
EXEC = compiler

# Fontes
BISON_SRC = parser.y
FLEX_SRC = lexical.l

# Arquivos gerados
BISON_OUT = parser.tab.c parser.tab.h
FLEX_OUT = lex.yy.c

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -o $(EXEC)

# Regra padrão
build: $(EXEC)

# Gera o executável final
$(EXEC): $(BISON_OUT) $(FLEX_OUT)
	$(CC) $(CFLAGS) parser.tab.c lex.yy.c

# Gera os arquivos do Bison
parser.tab.c parser.tab.h: $(BISON_SRC)
	bison -d $(BISON_SRC)

# Gera o arquivo do Flex
lex.yy.c: $(FLEX_SRC)
	flex $(FLEX_SRC)

# Atalho para compilar e rodar
run: build
	./$(EXEC) < teste.txt

# Limpa os arquivos gerados
clean:
	rm -f $(EXEC) $(BISON_OUT) $(FLEX_OUT)
