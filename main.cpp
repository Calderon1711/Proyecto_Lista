#include <iostream>

#include "Estudiante.h"
#include "PersistenciaDeDatos.h"
#include "ListaEstudiantes.h"
using namespace std;
int main() {
    ManejadorArchivos manejador("estudiantes.dat");
    ListaEstudiantes lista;

    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar lista enlazada (activos)\n";
        cout << "3. Mostrar borrados\n";
        cout << "4. Borrar estudiante (logico)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int doc, edad;
            string nombre;
            cout << "Documento: "; cin >> doc;
            cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            Estudiante e(doc, nombre.c_str(), edad);
            manejador.guardarEstudiante(e);
            lista.insertarOrdenado(e);
        }
        else if (opcion == 2) {
            lista.mostrarLista();
        }
        else if (opcion == 3) {
            lista.mostrarBorrados();
        }
        else if (opcion == 4) {
            int doc;
            cout << "Documento a borrar: "; cin >> doc;
            manejador.borrarLogico(doc);

            // recargar lista
            lista = ListaEstudiantes();
            manejador.cargarLista(lista);
        }

    } while (opcion != 0);

    return 0;
}
