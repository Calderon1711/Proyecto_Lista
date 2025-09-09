cmake_minimum_required(VERSION 3.30)
project(Proyecto_Lista)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Lista main.cpp
        Estudiante.h
        ListaEstudiantes.h
        PersistenciaDeDatos.h)
