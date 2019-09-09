CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
OBJS= ejer1profe.o
HEADERS=*.h
EXE=ejer1profe
MAKEFILE=Makefile

$(EXE): $(OBJS)
	@echo "### Generando el ejecutable"
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c $(MAKEFILE) $(HEADERS)
	@echo "### Compilando " $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "### Borrando todo"
	rm $(OBJS)
	rm $(EXE)

all: clean $(EXE)
