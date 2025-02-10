cmake_minimum_required(VERSION 3.20)
project(EstructuraDatos C) # Asegúrate de poner "C" para proyectos en C

# Configura el estándar de C
set(CMAKE_C_STANDARD 99)

# Agrega tu archivo fuente principal
add_executable(EstructuraDatos
        #Tema0/Practica1.c
        Tema1/Practica2.c
        Tema2/complejo.c
        Tema2/complejo.h
        Tema2/main.c
        Tema2/circuito.c
        Tema2/circuito.h)
