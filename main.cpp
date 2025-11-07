#include "red.h"
#include <limits>
#include <cctype>

// Función para limpiar el buffer de entrada
void limpiar_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para validar que sea un carácter válido
bool validar_caracter(char c) {
    return isalpha(c);
}

// Función para leer un entero con validación
int leer_entero(const string& mensaje, int min = INT_MIN, int max = INT_MAX) {
    int valor;
    while(true) {
        cout << mensaje;
        if(cin >> valor) {
            if(valor >= min && valor <= max) {
                limpiar_buffer();
                return valor;
            } else {
                cout << "Error: El valor debe estar entre " << min << " y " << max << endl;
            }
        } else {
            cout << "Error: Debe ingresar un numero valido" << endl;
            limpiar_buffer();
        }
    }
}

// Función para leer un carácter (nombre de enrutador) con validación
char leer_enrutador(const string& mensaje) {
    char nombre;
    while(true) {
        cout << mensaje;
        if(cin >> nombre) {
            if(validar_caracter(nombre)) {
                limpiar_buffer();
                return nombre;
            } else {
                cout << "Error: Debe ingresar una letra valida para el enrutador" << endl;
                limpiar_buffer();
            }
        } else {
            cout << "Error: Entrada invalida" << endl;
            limpiar_buffer();
        }
    }
}

int main()
{
    red net;
    char nombre, nombre1;
    int costo, n;

    while(true){
        cout << "\n\t=== Menu Principal ===" << endl;
        cout << "1) Agregar enrutador" << endl;
        cout << "2) Eliminar enrutador" << endl;
        cout << "3) Ver enrutador" << endl;
        cout << "4) Ver tabla" << endl;
        cout << "5) Ver ruta y costo" << endl;
        cout << "6) Cargar una red" << endl;
        cout << "7) Cambiar costo" << endl;
        cout << "8) Enlaces (eliminar o agregar)" << endl;
        cout << "9) Salir" << endl << endl;

        short option = leer_entero("Seleccione una opcion: ", 1, 9);

        switch (option) {
        case 1:
            nombre = leer_enrutador("Ingrese el nombre del enrutador: ");
            net.agregar_enrutador(nombre);
            break;

        case 2:
            if(net.esta_vacia()) {
                cout << "\nError: No hay enrutadores para eliminar" << endl;
            } else {
                nombre = leer_enrutador("Ingrese el nombre del enrutador: ");
                net.eliminar_enrutador(nombre);
            }
            break;

        case 3:
            if(net.esta_vacia()) {
                cout << "\nError: No hay enrutadores para mostrar" << endl;
            } else {
                nombre = leer_enrutador("Ingrese el nombre del enrutador: ");
                net.ver_enrutador(nombre);
            }
            break;

        case 4:
            if(net.esta_vacia()) {
                cout << "\nAVISO: No hay enrutadores ni rutas cargadas en la red." << endl;
                cout << "Por favor, agregue enrutadores o cargue una red primero (opciones 1 o 6)." << endl;
            } else {
                net.ver_tabla();
            }
            break;

        case 5:
            if(net.esta_vacia()) {
                cout << "\nError: No hay enrutadores en la red" << endl;
            } else {
                nombre = leer_enrutador("Ingrese el nombre del enrutador 1: ");
                nombre1 = leer_enrutador("Ingrese el nombre del enrutador 2: ");
                net.buscar_ruta(nombre, nombre1);
            }
            break;

        case 6:
            cout << "\n1) Red aleatoria" << endl;
            cout << "2) Desde un archivo" << endl;
            option = leer_entero("Seleccione una opcion: ", 1, 2);

            switch (option) {
            case 1:
                n = leer_entero("Ingrese cantidad de enrutadores [2,25]: ", 2, 25);
                net.red_aleatoria(n);
                break;
            case 2:
                net.leer_archivo();
                break;
            }
            break;

        case 7:
            if(net.esta_vacia()) {
                cout << "\nError: No hay enrutadores en la red" << endl;
            } else {
                nombre = leer_enrutador("Ingrese el nombre del enrutador 1: ");
                nombre1 = leer_enrutador("Ingrese el nombre del enrutador 2: ");
                costo = leer_entero("Ingrese el nuevo costo: ", 1, 1000);
                if(net.agregar_enlace(nombre, nombre1, costo))
                    cout << "Se ha cambiado el costo exitosamente" << endl;
                else
                    cout << "Error: No se pudo cambiar el costo" << endl;
            }
            break;

        case 8:
            if(net.esta_vacia()) {
                cout << "\nError: No hay enrutadores en la red" << endl;
            } else {
                cout << "\n1) Agregar enlace" << endl;
                cout << "2) Eliminar enlace" << endl;
                option = leer_entero("Seleccione una opcion: ", 1, 2);

                switch (option) {
                case 1:
                    nombre = leer_enrutador("Ingrese el nombre del enrutador 1: ");
                    nombre1 = leer_enrutador("Ingrese el nombre del enrutador 2: ");
                    costo = leer_entero("Ingrese el costo: ", 1, 1000);
                    if(net.agregar_enlace(nombre, nombre1, costo))
                        cout << "Se ha realizado el enlace exitosamente" << endl;
                    else
                        cout << "Error: No se pudo realizar el enlace" << endl;
                    break;
                case 2:
                    nombre = leer_enrutador("Ingrese el nombre del enrutador 1: ");
                    nombre1 = leer_enrutador("Ingrese el nombre del enrutador 2: ");
                    net.eliminar_enlace(nombre, nombre1);
                    break;
                }
            }
            break;

        case 9:
            cout << "\nSaliendo del programa..." << endl;
            return 0;

        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
    return 0;
}
