//
// Created by aleca on 9/9/2025.
//

#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H
//creo struct para no hacer toda las clase
struct NodoEstudiante {
    Estudiante est;
    NodoEstudiante* sig;
    NodoEstudiante(const Estudiante& e) : est(e), sig(nullptr) {}//constructor
};

class ListaEstudiantes {
private:
    NodoEstudiante* cabeza;// nodo cabeza o sea el primero

public:
    ListaEstudiantes() : cabeza(nullptr) {}//constructyor

    NodoEstudiante* getCabeza() { return cabeza; }

    void insertarOrdenado(const Estudiante& e) {
        NodoEstudiante* nuevo = new NodoEstudiante(e);
        if (!cabeza || cabeza->est.getDocumento() > e.getDocumento()) { //si cabez no esta vacia o si cabeza tiene mayor "id"
            nuevo->sig = cabeza;//entonces el q estaba en cabeza pasa al siguiente
            cabeza = nuevo;//y el nuevo pasa a primero
            return;
        }
        NodoEstudiante* actual = cabeza;
        while (actual->sig && actual->sig->est.getDocumento() < e.getDocumento()) {//lo q hace actual->sig es q no nos salgamos de la lista
//mientras el siguiente nodo tenga un documento menor al del estudiante nuevo, avanzamos.

            actual = actual->sig;
        }
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
    }

    void mostrarLista() const {
        NodoEstudiante* actual = cabeza;
        while (actual) {
            if (actual->est.getEstado() == 1) { // solo activos
                actual->est.mostrar();
            }
            actual = actual->sig;
        }
    }

    void mostrarBorrados() const {
        NodoEstudiante* actual = cabeza;
        while (actual) {
            if (actual->est.getEstado() == 0) { // solo borrados
                actual->est.mostrar();
            }
            actual = actual->sig;
        }
    }
};



#endif //LISTAESTUDIANTES_H
