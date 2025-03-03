# Configurar estándar de C
cmake_minimum_required(VERSION 3.20)
project(EstructuraDatos C)

set(CMAKE_C_STANDARD 99)

# Agregar directorios donde están los archivos de cabecera
include_directories(Tema2 Tema2_0 Tema3)

# Ejecutable para el código en Tema2 (main.c + dependencias)
add_executable(MainEjecutable
        Tema2/main.c
        Tema2/complejo.c
        Tema2/circuito.c
        Tema3/ListaEstatica.c
        Tema3/Elemento.c
        Tema3_1/ListaEnlazada.c  # <- Agregado
)

# Ejecutable independiente para Practica2.c
add_executable(Practica2Ejecutable
        Tema1/Practica2.c
        Tema3/ListaEstatica.c
        Tema3/Elemento.c
        Tema3_1/ListaEnlazada.c  # <- Agregado
)

# Ejecutable que usa Bitmap (Para la práctica de fractales)
add_executable(FractalEjecutable
        Tema2_0/main.c
        Tema2_0/Bitmap.c
        Tema3/ListaEstatica.c
        Tema3/Elemento.c
        Tema3_1/main.c
        Tema3_1/ListaEnlazada.c  # <- Agregado
)
