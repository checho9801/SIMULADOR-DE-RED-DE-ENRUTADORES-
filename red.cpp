#include "red.h"

red::red()
{

}

void red::modificacion1(string clave, int valor){
    singleMap[clave]=valor;
}

void red::modificacion2(string clave2){
    conexiones[clave2]=singleMap;
    singleMap.clear();
}

void red::modificaciones(string nuevo, string listo, int costo, int opcion){
    map<string,int> temporal;
    map<string,int>::iterator itTemp;
    for(itOut=conexiones.begin();itOut!=conexiones.end();itOut++){
        if(itOut->first==listo){
            temporal=itOut->second;
            switch (opcion) {
            case 1:{
                temporal.insert(pair<string,int>(nuevo,costo));
                break;
            }
                /*Se busca la clave por nombre del enrutador listo en conexiones y le inserta
                 la nueva conexion al nuevo enrutador*/
            case 2:{
                temporal[nuevo]=costo;
                break;
            }
            }
            conexiones[listo]=temporal;
            break;
        }
    }
}

void red::agregarEnrutador(string _nuevo, string _listo, int _costo){
    singleMap[_listo]=_costo;
    modificaciones(_nuevo,_listo,_costo,1);
}

void red::eliminarEnrutador(string _eliminar){
    conexiones.erase(_eliminar);
    map<string,int> temporal;
    map<string,int>::iterator itTemp;
    for(itOut=conexiones.begin();itOut!=conexiones.end();itOut++){
        temporal=itOut->second;
        temporal.erase(_eliminar);
        conexiones[itOut->first]=temporal;
    }
}

void red::modificarCosto(string _nuevo, string _listo, int _costo){
    singleMap=conexiones[_nuevo];
    singleMap[_listo]=_costo;
    modificaciones(_nuevo,_listo,_costo,2);
}

//[2,0,2]
void red::calcularRuta(string origen, string destino){
    vector<int> calculador, mejor, visitados, recorridoDef;
    vector<int>::iterator itV;
    int temp=0;//Guarda costo acumulado
    priority_queue<vector<int>> mejorCamino;
    string pasoStr1=origen,pasoStr2;
    char pasoCh1=pasoStr1[0],pasoCh2;
    int pasoInt1=pasoCh1,pasoInt2=0;//paso"1 guarda el nodo en el cual se encuentra el algoritmo
    visitados.push_back(pasoInt1);
    while(true){
        singleMap=conexiones[pasoStr1];
        for(itIn=singleMap.begin();itIn!=singleMap.end();itIn++){
            calculador.push_back((-1*itIn->second)+temp);
            calculador.push_back(pasoInt1);
            pasoStr2=itIn->first;
            pasoCh2=pasoStr2[0];
            pasoInt2=pasoCh2;
            calculador.push_back(pasoInt2);
            mejorCamino.push(calculador);
            calculador.clear();
        }

        while(true){
            unsigned long long int contador=0;
            mejor=mejorCamino.top();
            for(itV=visitados.begin();itV!=visitados.end();itV++){
                if(mejor[2]!=*itV) contador+=1;
            }
            if(contador==visitados.size()) break;
            else mejorCamino.pop();
        }
        mejorCamino.pop();
        temp=mejor[0];
        pasoInt1=mejor[2];
        pasoCh1=pasoInt1;
        pasoStr1=pasoCh1;
        visitados.push_back(pasoInt1);

        bool parteRecorrido=true;
        for(unsigned long long int i=0;i<recorridoDef.size();i++){
            if(mejor[1]==recorridoDef[i]) parteRecorrido=false;
        }
        if(parteRecorrido==true) recorridoDef.push_back(mejor[1]);
        /*Ciclo realizado para evitar error cuando un nodo tiene el mismo costo para enviar
        información a varios de sus nodos contiguos*/

        if(pasoStr1==destino){
            for(itV=recorridoDef.begin();itV!=recorridoDef.end();itV++){
                pasoCh1=*itV;
                pasoStr1=pasoCh1;
                cout<<" -> "<<pasoStr1;
            }
            cout<<" -> "<<destino;
            break;
        }
    }
    cout<<endl;
    cout<<"Con el costo mas eficiente igual a: "<<mejor[0]*-1<<endl;
}



