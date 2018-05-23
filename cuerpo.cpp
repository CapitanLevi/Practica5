#include "cuerpo.h"

Cuerpo::Cuerpo()
{
    cout<<"Creando cuerpo por defecto"<<endl;
    masa = 0;
    ax = ay = 0;
    vx = vy = 0;
    px = py = 0;
}

Cuerpo::Cuerpo(float _masa, float _ax, float _ay, float _vx, float _vy, float _px, float _py)
{
    cout<<"Creando cuerpo personalizado"<<endl;
    masa = _masa;
    ax = _ax;
    ay = _ay;
    vx = _vx;
    vy = _vy;
    px = _px;
    py = _py;
}
float Cuerpo::getMasa() const
{
    return masa;
}
float Cuerpo::getAx() const
{
    return ax;
}
float Cuerpo::getAy() const
{
    return ay;
}
float Cuerpo::getVx() const
{
    return vx;
}
float Cuerpo::getVy() const
{
    return vy;
}
float Cuerpo::getPx() const
{
    return px;
}
float Cuerpo::getPy() const
{
    return py;
}

void Cuerpo::setMasa(float value)
{
    masa = value;
}
void Cuerpo::setAx(float value)
{
    ax = value;
}
void Cuerpo::setAy(float value)
{
    ay = value;
}
void Cuerpo::setVx(float value)
{
    vx = value;
}
void Cuerpo::setVy(float value)
{
    vy = value;
}
void Cuerpo::setPx(float value)
{
    px = value;
}
void Cuerpo::setPy(float value)
{
    py = value;
}


void Cuerpo::imprimir(void){
    cout<<px<<"\t"<<py<<endl;
}

void Cuerpo::actualizar()
{
   // calcularAcc(DT);
    calcularVel(DT);
    calcularPos(DT);
}




void Cuerpo::calcularVel(float dt){
    vx = vx + ax*dt;
    vy = vy + ay*dt;
}

void Cuerpo::calcularPos(float dt){
    px = px + vx*dt + (1/2)*ax*pow(dt,2);
    py = py + vy*dt + (1/2)*ay*pow(dt,2);
}








