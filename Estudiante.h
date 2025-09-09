//
// Created by aleca on 9/9/2025.
//

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <cstring>
using namespace std;

class Estudiante {
private:
    int documento;
    char nombre[50]; //para q al cargar los archivos binarioos sea mas sencillo
    int edad;
    int estado;

public:
    Estudiante() {
        documento = 0;
        strcpy(nombre, "");// xq es cadena char y mas facil para archivos binarios, lo q hace es copiar cadenas de caracteres tipo char[]
        edad = 0;
        estado = 1;
    }

    Estudiante(int doc, const char* nom, int ed) {
        documento = doc;
        strncpy(nombre, nom, sizeof(nombre)); //y aca copia nom en la cadena
        edad = ed;
        estado = 1;
    }

    // Getters
    int getDocumento() const { return documento; }
    const char* getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    int getEstado() const { return estado; }

    // Setters
    void setDocumento(int doc) { documento = doc; }
    void setNombre(const char* nom) { strncpy(nombre, nom, sizeof(nombre)); }
    void setEdad(int ed) { edad = ed; }
    void setEstado(int est) { estado = est; }

    void mostrar() const {
        cout << "Documento: " << documento
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Estado: " << (estado == 1 ? "Activo" : "Borrado") << endl;
    }
};

#endif

