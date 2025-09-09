//
// Created by aleca on 9/9/2025.
//

#ifndef PERSISTENCIADEDATOS_H
#define PERSISTENCIADEDATOS_H

#include <fstream>
#include "ListaEstudiantes.h"

class ManejadorArchivos {
private:
    string nombreArchivo;//para q me manden el nombre del archivo por parametro

public:
    ManejadorArchivos(string archivo) : nombreArchivo(archivo) {}//constructor

    void guardarEstudiante(const Estudiante& e) { //me mandan un estudiante por parametro
        ofstream archivo(nombreArchivo, ios::binary | ios::app);
        archivo.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));//abro el archivo y escribo sobre el archivo los datos del estudiante
        archivo.close(); //cierro
    }

    void cargarLista(ListaEstudiantes& lista) { //cargo lista
        ifstream archivo(nombreArchivo, ios::binary);
        Estudiante e;
        while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) { //voy leyendo todo el archivo hasta q se acaben los datos
            lista.insertarOrdenado(e);//voy insertando y ordenando a la vez
        }
        archivo.close();//cerramos
    }

    void borrarLogico(int doc) {
        fstream io(nombreArchivo, ios::binary | ios::in | ios::out);//abro el archivo modo lectura y escritura
        Estudiante e;
        while (io.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) { //cada vuelta del while carga un estudiante
            if (e.getDocumento() == doc && e.getEstado() == 1) { //aca verificamos si el que queremos borarr coincide y se esta activo
                e.setEstado(0);
                io.seekp(-sizeof(Estudiante), ios::cur);//retrocedemos justo 1 registro atrás, para volver al inicio de ese estudiante.
                io.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));//lo sobreescribimos pero con estado 0
                break;
            }
        }
        io.close();//cerramos
    }
};

#endif




