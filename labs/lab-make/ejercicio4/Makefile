# Nombre del ejecutable final
PROGRAMA := programa

# Compilador y flags
CC     := gcc
CFLAGS := -Wall


SRCS := main.c operaciones.c

OBJS := $(SRCS:.c=.o)

# Regla principal
all: $(PROGRAMA)

$(PROGRAMA): $(OBJS)
	$(CC) $^ -o $(PROGRAMA)

# TODO 4: Escribí la regla de patrón para compilar cada .c en su .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA) $(OBJS)

# TODO 5: Declarar los targets que NO son archivos usando .PHONY
#         Agregá: all y clean
.PHONY: all clean