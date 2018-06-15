#include <iostream>
#include "cuerpo.h"
#include "cuerpo.h"
#include <vector>
#include <fstream>

using namespace std;

void menu();
void modelacion(vector<Cuerpo> planeta);

int main(){
    cout<<"**************BIENVENIDO****************"<<endl;
    int planetas=0;
    vector<Cuerpo> mybody;
    cout<<"Ingrese el numero de planetas: "; cin>>planetas;
    // Ciclo de creación de los planetas
    for(int i=0;i<planetas;i++){
        Cuerpo  planeta;
        float masa;
        float posx;
        float posy;
        float vx;
        float vy;
        float ax=0;
        float ay=0;
        cout<<"Ingrese dados del cuerpo "<<i+1<<": "<<endl;
        cout<<"Masa"<<": ";
        cin>>masa;
        cout<<"Posicion inicial en X: ";
        cin>>posx;
        cout<<"Posicion inicial en Y: ";
        cin>>posy;
        cout<<"Velocidad inicial en X: ";
        cin>>vx;
        cout<<"Velocidad inicial en Y: ";
        cin>>vy;

        planeta.setMasa(masa);
        planeta.setPx(posx);
        planeta.setPy(posy);
        planeta.setVx(vx);
        planeta.setVy(vy);
        planeta.setAx(ax);
        planeta.setAy(ay);
        mybody.push_back(planeta);
        cout<<endl;
    }
    cout<<"Archivo con los resultados generado."<<endl;
    modelacion(mybody);
    return 0;
}

void modelacion(vector<Cuerpo> planeta){
    fstream file;

    float aceleracionx=0;
    float aceleraciony=0;
    float rx;
    float ry;
    float r;
    float theta;
    float G=1;
    file.open("movimiento.txt", ios::out);
    for(int i=0;i<planeta.size();i++){
        file<<planeta[i].getPx()<<"\t"<<planeta[i].getPy()<<"\t";
    }
    file<<endl;
    // Generando 10.000 puntos diferentes (filas)
    for(int k=0;k<10000;k++){
        // Calculando la aceleración de la partícula i
        for(int i=0;i<planeta.size();i++){
            aceleracionx=0;
            aceleraciony=0;
            // Sumando a la aceleración de la partícula i todas las contribuciones de todos los demás planetas
            for(int j=0;j<planeta.size();j++){
                if(i!=j){
                    rx=(planeta[j].getPx()-planeta[i].getPx());
                    ry=(planeta[j].getPy()-planeta[i].getPy());
                    r=sqrt(pow(rx,2)+pow(ry,2));
                    theta=atan2(ry,rx);
                    aceleracionx+=(G*planeta[j].getMasa()/pow(r,2))*cos(theta);
                    aceleraciony+=(G*planeta[j].getMasa()/pow(r,2))*sin(theta);
                }
            }
            planeta[i].setAx(aceleracionx);
            planeta[i].setAy(aceleraciony);
        }
        for(int i=0;i<planeta.size();i++){
            planeta[i].actualizar();
            file<<planeta[i].getPx()<<"\t"<<planeta[i].getPy()<<"\t";
        }
        file<<endl;
    }
    file.close();
}

