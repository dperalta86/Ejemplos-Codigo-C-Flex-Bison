# Detecta el SO
ifeq ($(OS),Windows_NT)
    TARGET = arreglos-en-c.exe
    RMDIR = cmd /C rmdir /S /Q
else
    TARGET = arreglos-en-c
    RMDIR = rm -rf
endif

# Variables de compilación
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = -lm

# Directorios
SRC_DIR = ejemplos_arreglos
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# vpath: busca archivos .c en SRC_DIR
vpath %.c $(SRC_DIR)

# Archivos fuente
SOURCES = main.c \
          coordenadas.c \
          por_parametro.c \
          por_parametro_2.c \
          por_parametro_bidimensional.c \
          puntajes.c \
          recorrer.c \
          retornar.c \
          tamanio_del_arreglo.c

# Archivos objeto
OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Targets principales
.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Compilación completada: $@"

# Regla para compilar archivos objeto
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia archivos intermedios y ejecutable
clean:
	$(RMDIR) $(BUILD_DIR)
	@echo "✓ Limpieza completada"

.PRECIOUS: $(OBJECTS)
