#include <iostream>
#include<red.h>

using namespace std;

#define DOC "doc.txt"

int main(){

    red enrutadores;
    bool trabajando=true;
    while(trabajando==true){
        cout<<"Menu"<<endl;
        cout<<"Ingrese una de las siguientes opciones:"<<endl;
        cout<<"1.Cargar red desde el txt"<<endl;
        cout<<"2.Agregar enrutador"<<endl;
        cout<<"3.Eliminar enrutador"<<endl;
        cout<<"4.Modificar costo de enrutador"<<endl;
        cout<<"5.Mostrar camino y costo  mas eficientes de un enrutador a otro"<<endl;
        cout<<"0 para salir del programa"<<endl;
        int opcion=0;
        cin>>opcion;
        system("CLS");
        switch (opcion) {
        case 1:{
            ifstream leer;
            try {
                leer.open(DOC);
                if(!leer.is_open()) throw '1';
            }  catch (char c) {
                if(c=='1') cout<<"Problema con la lectura del archivo"<<endl;
            }
            string linea;
            string parteLinea;
            string nombreEnrutador;
            string nodo, costoStr;
            int costoInt;
            int separador1=0;
            int separador2=0;
            while(getline(leer,linea)){
                separador1=linea.find(":");
                nombreEnrutador=linea.substr(0,separador1);
                parteLinea=linea.substr(separador1+1);
                separador1=parteLinea.find("-");
                string numeroEnrutadores=parteLinea.substr(0,separador1);
                int numeroIteraciones=atoi(numeroEnrutadores.c_str());
                parteLinea=parteLinea.substr(separador1+1);
                for(int i=0;i<numeroIteraciones;i++){
                    separador1=parteLinea.find(":");
                    nodo=parteLinea.substr(0,separador1);
                    separador2=parteLinea.find(",");
                    costoStr=parteLinea.substr(separador1+1,separador2-separador1-1);
                    costoInt=atoi(costoStr.c_str());
                    enrutadores.modificacion1(nodo,costoInt);
                    parteLinea=parteLinea.substr(separador2+1);
                }
                enrutadores.modificacion2(nombreEnrutador);
            }
            leer.close();
            cout<<"La red ha sido cargada con exito."<<endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 2:{
            string nombre;
            string conexion;
            int conexiones;
            int costo;
            cout<<"Ingrese el nombre del nuevo enrutador: "; cin>>nombre;
            cout<<"\n Indique el numero de conexiones que tendra: ";cin>>conexiones;
            system("CLS");
            for(int i=0;i<conexiones;i++){
                cout<<"Indique a que enrutador estara conectado "<<nombre<< ": ";cin>>conexion;
                cout<<"\n Indique el costo hacia "<<conexion<<": ";cin>>costo;
                cout<<endl;
                enrutadores.agregarEnrutador(nombre,conexion,costo);
            }
            enrutadores.modificacion2(nombre);
            cout<<"Se ha agregado el nuevo enrutador"<<endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 3:{
            string nombre;
            cout<<"Escriba el nombre del enrutador que desea eliminar: ";cin>>nombre;
            enrutadores.eliminarEnrutador(nombre);
            cout<<"\n El enrutador se ha eliminado exitosamente..."<<endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 4:{
            string a;
            string b;
            int costo;
            cout<<"Indique el nombre de uno de los enrutadores: ";cin>>a;
            cout<<"\n Indique el nombre del otro enrutador: ";cin>>b;
            cout<<"\n Cual sera el valor del nuevo costo: ";cin>>costo;
            system("CLS");
            enrutadores.modificarCosto(a,b,costo);
            enrutadores.modificacion2(a);
            cout<<"El costo de la conexion se ha modificado con exito..."<<endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 5:{
            string a;
            string b;
            cout<<"Indique el nombre del enrutador origen: ";cin>>a;
            cout<<"\n Indique el nombre del enrutador destino: ";cin>>b;
            system("CLS");
            enrutadores.calcularRuta(a,b);
            system("PAUSE");
            system("CLS");
            break;
        }
        default:{
            trabajando=false;
            break;
        }
        }

    }
    return 0;
}
