#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;

struct Tiempo {
    int time;
    int cont;
    int segtime;
    float promedio;
};

struct nodo {
    char nombre[25];
    int camisa;
    Tiempo tiempo;
    int contador;
    nodo *sig, *sig2;
};

nodo *cab = NULL, *cab1 = NULL;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void registrar() {
    system("cls");

    nodo *nuevo = (nodo *) malloc(sizeof(nodo));
    if (!nuevo) {
        cout << "Error al asignar memoria." << endl;
        return;
    }

    nuevo->contador = 0;
    nuevo->tiempo.time = 0;
    nuevo->tiempo.promedio = 0;

    cout << "Ingrese numero de la Camisa: ";
    cin >> nuevo->camisa;
    cout << "Ingrese el nombre del participante: ";
    cin.ignore();
    cin.getline(nuevo->nombre, 25);

    nuevo->sig = NULL;
    nuevo->sig2 = cab1;
    cab1 = nuevo;

    if (cab == NULL) {
        cab = nuevo;
    } else {
        nodo *aux = cab;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }

    system("cls");
}

void tiempo() {
    int camis;
    bool encontrado = false;

    cout << "Ingrese el numero de la camisa: ";
    cin >> camis;

    for (nodo *aux = cab; aux != NULL; aux = aux->sig) {
        if (camis == aux->camisa) {
            encontrado = true;

            cout << "Ingrese el tiempo del corredor (segundos): ";
            cin >> aux->tiempo.time;

            aux->contador++;
            aux->tiempo.promedio = ((aux->tiempo.promedio * (aux->contador - 1)) + aux->tiempo.time) / aux->contador;

            cout << "Registro Exitoso" << endl;
            return;
        }
    }

    if (!encontrado) {
        cout << "No se encontró el corredor." << endl;
    }
}

void mostrar() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t\tLista de tiempos de los participantes\n\n";

    int i = 1;
    for (nodo *aux = cab; aux != NULL; aux = aux->sig) {
        cout << i++ << ". Camisa: " << aux->camisa << " | Nombre: " << aux->nombre
             << " | Tiempo transcurrido: " << aux->tiempo.time << "s" << endl;
    }
}

void mostraOrdenamiento() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Lista de Ordenación Pila\n";

    int cont = 1;
    for (nodo *aux = cab1; aux != NULL; aux = aux->sig2) {
        cout << cont++ << ". Camisa: " << aux->camisa << " | Nombre: " << aux->nombre
             << " | Tiempo: " << aux->tiempo.time << "s" << endl;
    }
}

void mostraPromedio() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Lista de Promedio de tiempos\n";

    int c = 1;
    for (nodo *aux = cab1; aux != NULL; aux = aux->sig2) {
        cout << c++ << ". Camisa: " << aux->camisa << " | Promedio: " << aux->tiempo.promedio << "s" << endl;
    }
}

void eliminar() {
    SetConsoleTextAttribute(hConsole, 6);

    if (cab != NULL) {
        nodo *aux = cab;
        cab = cab->sig;
        free(aux);
        cout << "El corredor ha sido eliminado." << endl;
    } else {
        cout << "No hay corredores registrados." << endl;
    }
}

int main() {
    int opc = 0;

    do {
        SetConsoleTextAttribute(hConsole, 1);
        cout << "\n\tMENU\n";
        cout << "1. Registrar participante\n";
        cout << "2. Colocar tiempo de llegada\n";
        cout << "3. Ver lista de participantes\n";
        cout << "4. Mostrar promedios\n";
        cout << "5. Mostrar ordenamiento\n";
        cout << "6. Eliminar participante\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                tiempo();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                mostraPromedio();
                break;
            case 5:
                mostraOrdenamiento();
                break;
            case 6:
                eliminar();
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opc != 7);

    return 0;
}
