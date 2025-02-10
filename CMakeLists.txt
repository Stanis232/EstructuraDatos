cmake_minimum_required(VERSION 3.20)
project(EstructuraDatos C)

# Configura el estándar de C
set(CMAKE_C_STANDARD 99)

# Ejecutable para el código en Tema2 (main.c + dependencias)
add_executable(MainEjecutable
        Tema2/main.c
        Tema2/complejo.c
        Tema2/circuito.c
)

# Ejecutable independiente para Practica2.c
add_executable(Practica2Ejecutable
        Tema1/Practica2.c
)

# Opcional: Puedes descomentar esto si quieres otro ejecutable
# add_executable(Ejemplo1Ejecutable Tema1/Ejemplo1.c)
