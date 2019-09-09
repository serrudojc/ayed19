CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
OBJS= main.o funciones.o
HEADERS=*.hpp
EXE=main
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
