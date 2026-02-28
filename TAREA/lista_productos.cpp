#include <iostream>
#include <string>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto datos;
    Nodo* siguiente;
};

int main() {

    cout << "Nombre: BRANDON PRETZANTZIN" << endl << endl;

    Nodo* cabeza = nullptr;
    Nodo* nuevo = nullptr;
    Nodo* ultimo = nullptr;

    for (int i = 0; i < 4; i++) {

        nuevo = new Nodo;  // memoria dinámica
        nuevo->siguiente = nullptr;  // inicialización obligatoria

        cout << "Ingrese codigo del producto " << i + 1 << ": ";
        cin >> nuevo->datos.codigo;

        cin.ignore();
        cout << "Ingrese nombre del producto " << i + 1 << ": ";
        getline(cin, nuevo->datos.nombre);

        cout << "Ingrese precio del producto " << i + 1 << ": ";
        cin >> nuevo->datos.precio;

        cout << endl;

        if (cabeza == nullptr) {
            cabeza = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    Nodo* auxiliar = cabeza;
    double total = 0;

    cout << "----- LISTA DE PRODUCTOS -----" << endl;

    while (auxiliar != nullptr) {
        cout << "Codigo: " << auxiliar->datos.codigo << endl;
        cout << "Nombre: " << auxiliar->datos.nombre << endl;
        cout << "Precio: Q" << auxiliar->datos.precio << endl;
        cout << "----------------------" << endl;

        total += auxiliar->datos.precio;

        auxiliar = auxiliar->siguiente;
    }

    cout << "Total acumulado: Q" << total << endl << endl;

    auxiliar = cabeza;

    while (auxiliar != nullptr) {
        Nodo* temp = auxiliar;
        auxiliar = auxiliar->siguiente;
        delete temp;
    }

    cabeza = nullptr;

    return 0;
}
