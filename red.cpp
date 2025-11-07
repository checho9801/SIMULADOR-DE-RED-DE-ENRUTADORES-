#include "red.h"

red::red()
{

}

void red::modificacion1(string clave, int valor){
    if(valor >= 0) {
        singleMap[clave] = valor;
    }
}

void red::modificacion2(string clave2){
    if(!clave2.empty()) {
        conexiones[clave2] = singleMap;
        singleMap.clear();
    }
}

bool red::validarEnrutador(const string& nombre) const {
    return !nombre.empty() && conexiones.find(nombre) != conexiones.end();
}

bool red::validarConexion(const string& origen, const string& destino) const {
    if(!validarEnrutador(origen)) return false;
    auto it = conexiones.find(origen);
    return it->second.find(destino) != it->second.end();
}

void red::modificaciones(string nuevo, string listo, int costo, int opcion){
    if(costo < 0) return;

    map<string,int> temporal;
    for(itOut = conexiones.begin(); itOut != conexiones.end(); itOut++){
        if(itOut->first == listo){
            temporal = itOut->second;
            switch (opcion) {
            case 1:{
                temporal.insert(pair<string,int>(nuevo, costo));
                break;
            }
            case 2:{
                temporal[nuevo] = costo;
                break;
            }
            }
            conexiones[listo] = temporal;
            break;
        }
    }
}

bool red::agregarEnrutador(string _nuevo, string _listo, int _costo){
    if(_nuevo.empty() || _listo.empty() || _costo < 0) {
        return false;
    }

    singleMap[_listo] = _costo;
    modificaciones(_nuevo, _listo, _costo, 1);
    return true;
}

bool red::eliminarEnrutador(string _eliminar){
    if(_eliminar.empty() || !validarEnrutador(_eliminar)) {
        return false;
    }

    conexiones.erase(_eliminar);
    map<string,int> temporal;
    for(itOut = conexiones.begin(); itOut != conexiones.end(); itOut++){
        temporal = itOut->second;
        temporal.erase(_eliminar);
        conexiones[itOut->first] = temporal;
    }
    return true;
}

bool red::modificarCosto(string _nuevo, string _listo, int _costo){
    if(_nuevo.empty() || _listo.empty() || _costo < 0) {
        return false;
    }

    if(!validarEnrutador(_nuevo)) {
        return false;
    }

    singleMap = conexiones[_nuevo];
    singleMap[_listo] = _costo;
    modificaciones(_nuevo, _listo, _costo, 2);
    return true;
}

void red::calcularRuta(string origen, string destino){
    if(!validarEnrutador(origen) || !validarEnrutador(destino)) {
        cout << "Error: Uno o ambos enrutadores no existen en la red." << endl;
        return;
    }

    if(origen == destino) {
        cout << "Origen y destino son el mismo enrutador: " << origen << endl;
        cout << "Costo: 0" << endl;
        return;
    }

    vector<int> calculador, mejor, visitados, recorridoDef;
    vector<int>::iterator itV;
    int temp = 0;
    priority_queue<vector<int>> mejorCamino;
    string pasoStr1 = origen, pasoStr2;
    char pasoCh1 = pasoStr1[0], pasoCh2;
    int pasoInt1 = pasoCh1, pasoInt2 = 0;
    visitados.push_back(pasoInt1);

    while(true){
        if(conexiones.find(pasoStr1) == conexiones.end()) {
            cout << "Error: El enrutador " << pasoStr1 << " no tiene conexiones." << endl;
            return;
        }

        singleMap = conexiones[pasoStr1];
        for(itIn = singleMap.begin(); itIn != singleMap.end(); itIn++){
            calculador.push_back((-1 * itIn->second) + temp);
            calculador.push_back(pasoInt1);
            pasoStr2 = itIn->first;
            pasoCh2 = pasoStr2[0];
            pasoInt2 = pasoCh2;
            calculador.push_back(pasoInt2);
            mejorCamino.push(calculador);
            calculador.clear();
        }

        if(mejorCamino.empty()) {
            cout << "No existe ruta entre " << origen << " y " << destino << endl;
            return;
        }

        while(true){
            if(mejorCamino.empty()) {
                cout << "No existe ruta entre " << origen << " y " << destino << endl;
                return;
            }

            unsigned long long int contador = 0;
            mejor = mejorCamino.top();
            for(itV = visitados.begin(); itV != visitados.end(); itV++){
                if(mejor[2] != *itV) contador += 1;
            }
            if(contador == visitados.size()) break;
            else mejorCamino.pop();
        }
        mejorCamino.pop();
        temp = mejor[0];
        pasoInt1 = mejor[2];
        pasoCh1 = pasoInt1;
        pasoStr1 = pasoCh1;
        visitados.push_back(pasoInt1);

        bool parteRecorrido = true;
        for(unsigned long long int i = 0; i < recorridoDef.size(); i++){
            if(mejor[1] == recorridoDef[i]) parteRecorrido = false;
        }
        if(parteRecorrido == true) recorridoDef.push_back(mejor[1]);

        if(pasoStr1 == destino){
            cout << "Ruta optima desde " << origen << " hasta " << destino << ":" << endl;
            cout << origen;
            for(itV = recorridoDef.begin(); itV != recorridoDef.end(); itV++){
                pasoCh1 = *itV;
                pasoStr1 = pasoCh1;
                cout << " -> " << pasoStr1;
            }
            cout << " -> " << destino << endl;
            cout << "Costo total: " << mejor[0] * -1 << endl;
            break;
        }
    }
}

void red::mostrarRed() const {
    if(conexiones.empty()) {
        cout << "La red esta vacia." << endl;
        return;
    }

    cout << "Estado actual de la red:" << endl;
    cout << "========================" << endl;
    for(auto it = conexiones.begin(); it != conexiones.end(); it++) {
        cout << "Enrutador: " << it->first << endl;
        cout << "Conexiones:" << endl;
        for(auto conn = it->second.begin(); conn != it->second.end(); conn++) {
            cout << "  -> " << conn->first << " (costo: " << conn->second << ")" << endl;
        }
        cout << endl;
    }
}

void red::limpiarRed() {
    conexiones.clear();
    singleMap.clear();
}

int red::obtenerNumeroEnrutadores() const {
    return conexiones.size();
}

bool red::existeEnrutador(const string& nombre) const {
    return conexiones.find(nombre) != conexiones.end();
}
