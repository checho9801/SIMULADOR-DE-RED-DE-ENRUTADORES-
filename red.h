#ifndef RED_H
#define RED_H
#include<string.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<fstream>
#include <cstdlib>

using namespace std;

class red
{
private:
    map<string,int> singleMap;
    map<string,map<string,int>> conexiones;
    map<string,int>::iterator itIn;
    map<string,map<string,int>>::iterator itOut;

    void modificaciones(string nuevo, string listo, int costo, int opcion);
    /*Funcion que agrega nuevas conexiones de los enrutadores del mapa conexiones y también
    modifica costos de conexion.
    opcion 1: Agregar.
    opcion 2: modificar costo.
    */

public:
    red();
    void modificacion1(string clave,int valor);
    /*Para agregar un nuevo enrutador y sus costos hacia los otros enrutadores.*/

    void modificacion2(string clave2);
    /*Guarda todas las rutas de un enrutador nuevo en el mapa de conexiones*/

    void agregarEnrutador(string _nuevo, string _listo, int _costo);
    /*Guarda un nuevo enrutador y sus conexiones*/

    void eliminarEnrutador(string _eliminar);
    /*Elimina el enrutador indicado de la red*/

    void modificarCosto(string _nuevo, string _listo, int _costo);
    /*Modifica el costo de la conexion indicada*/

    void calcularRuta(string origen, string destino);
    /*Calcula el camino más corto y menor costo de un nodo a otro, también muestra que camino
    seguir y dicho costo*/

};

#endif // RED_H
