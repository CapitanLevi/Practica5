#include <iostream>
#include "cuerpo.h"
#include "cuerpo.h"
#include <vector>
#include <fstream>

using namespace std;

void menu();
void funcioncalculo(vector<Cuerpo> planeta);


int main()
{
   menu();

    return 0;
}









void funcioncalculo(vector<Cuerpo> planeta)
{
    fstream file;

    float aceleracionx=0;
    float aceleraciony=0;

    float rx;
    float ry;
    float r;
    float theta;
    //float G=pow(6.67384,-11);
    float G=1;
    file.open("movimiento.txt", ios::out);
    //file<<planeta[0].getPx()<<"\t"<<planeta[0].getPy()<<;

    for(int i=0;i<planeta.size();i++){

        file<<planeta[i].getPx()<<"\t"<<planeta[i].getPy()<<"\t";
    }

    file<<endl;

    for(int k=0;k<10000;k++)
    {
        for(int i=0;i<planeta.size();i++){
            aceleracionx=0;
            aceleraciony=0;
            //cout<<endl<<endl;
          //  cout<<"aceleracionx es: "<<aceleracionx<<endl;
            //cout<<"aceleraciony es: "<<aceleraciony<<endl;
            //cout<<endl<<endl;
            for(int j=0;j<planeta.size();j++){
                if(i!=j){
                 //   planeta[i].calcAcc(planeta[j]);
                    rx=(planeta[j].getPx()-planeta[i].getPx());
              //      cout<<"rx es: "<<rx<<endl;
                    ry=(planeta[j].getPy()-planeta[i].getPy());
                //    cout<<"ry es: "<<ry<<endl;
                    r=sqrt(pow(rx,2)+pow(ry,2));
                  //  cout<<"r es: "<<endl;
                    theta=atan2(ry,rx);
                    //cout<<"theta es: "<<theta<<endl;
                    aceleracionx+=(G*planeta[j].getMasa()/pow(r,2))*cos(theta);

                    //cout<<"aceleracionx es: "<<aceleracionx<<endl;
                    aceleraciony+=(G*planeta[j].getMasa()/pow(r,2))*sin(theta);
                    //cout<<"aceleraciony es: "<<aceleraciony<<endl;
                }
            }
            planeta[i].setAx(aceleracionx);
            planeta[i].setAy(aceleraciony);
            aceleracionx=0;
            aceleraciony=0;
        }
        //file<<endl<<endl<<endl;

        for(int i=0;i<planeta.size();i++){

            planeta[i].actualizar();
            file<<planeta[i].getPx()<<"\t"<<planeta[i].getPy()<<"\t";
           // planeta[i].setAx(0.0);
           // planeta[i].setAy(0.0);

           // cout<<"paso por aqui"<<endl;

        }
        file<<endl;
         //file<<endl<<endl<<endl;



    }
    file.close();
    //cout<<"el tamanio es: "<<planeta.size()<<endl;



}
















void menu(){

    int opcion=0;


    cout<<"**************BIENVENIDO****************"<<endl;

    while (true){

        for(int i=0;i<100;i++){
            cout<<endl<<endl;
        }

        int planetas=0;
        vector<Cuerpo> mybody;

        cout<<"                     MENU                    "<<endl<<endl;
        cout<<"Ingrese 1 para ingresar el numero  de planetas "<<endl;
        cout<<"Ingrese 2 para salir"<<endl;
        cin>>opcion;
        //cin>>opcion;

        if(opcion!=1){break;}
        else{

            cout<<"Ingrese el numero de planetas"<<endl;
            cin>>planetas;

            for(int i=0;i<planetas;i++){
                  Cuerpo  planeta;
                  float masa;
                  float posx;
                  float posy;
                  float vx=0;
                  float vy=0;
                  float ax=0;
                  float ay=0;
                  cout<<endl<<endl<<endl;
                  cout<<"Ingrese la masa del planeta"<<" "<<i+1<<" :"<<endl;
                  cin>>masa;
                  cout<<"Ingrese la posicion en x del planeta"<<" "<<i+1<<" :"<<endl;
                  cin>>posx;
                  cout<<"Ingrese la posicion en y del planeta"<<" "<<i+1<<" :"<<endl;
                  cin>>posy;
                  cout<<"Ingrese la velocidad inicial en x: "<<endl;
                  cin>>vx;
                  cout<<"Ingrese la velocidad inicial en y: "<<endl;
                  cin>>vy;


                  planeta.setMasa(masa);
                  planeta.setPx(posx);
                  planeta.setPy(posy);
                  planeta.setVx(vx);
                  planeta.setVy(vy);
                  planeta.setAx(ax);
                  planeta.setAy(ay);
                  cout<<endl<<endl<<endl;

                  mybody.push_back(planeta);
              }


            cout<<"Archivo generandose con los resultados....."<<endl;
            cout<<endl<<endl<<"PRESIONE ENTER"<<endl;
            funcioncalculo(mybody);
            cin.ignore();
            cin.ignore();
            break;

        }


    }
}
