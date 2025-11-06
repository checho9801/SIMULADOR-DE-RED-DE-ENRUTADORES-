#ifndef RED_H
#define RED_H
#include<string.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<fstream>
#include<limits>
#include<algorithm>
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
    bool validarEnrutador(const string& nombre) const;
    bool validarConexion(const string& origen, const string& destino) const;

public:
    red();
    void modificacion1(string clave,int valor);
    void modificacion2(string clave2);
    bool agregarEnrutador(string _nuevo, string _listo, int _costo);
    bool eliminarEnrutador(string _eliminar);
    bool modificarCosto(string _nuevo, string _listo, int _costo);
    void calcularRuta(string origen, string destino);
    void mostrarRed() const;
    void limpiarRed();
    int obtenerNumeroEnrutadores() const;
    bool existeEnrutador(const string& nombre) const;
};

#endif // RED_H