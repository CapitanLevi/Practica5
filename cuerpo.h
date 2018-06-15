#ifndef CUERPO_H
#define CUERPO_H

#include <iostream>
#include <math.h>

#define DT 1 //es 0.001. Es la diferencia temporal dt entre un punto y otro

using namespace std;
class Cuerpo
{
private:
    float masa;
    float ax, ay;
    float vx, vy;
    float px, py;


public:
    Cuerpo();
//    Cuerpo(float _masa, float _ax, float _ay, float _vx, float _vy, float _px, float _py);
    // Getters
    float getMasa() const;
    float getAx() const;
    float getAy() const;
    float getVx() const;
    float getVy() const;
    float getPx() const;
    float getPy() const;
    // Setters
    void setMasa(float value);
    void setAx(float value);
    void setAy(float value);
    void setVx(float value);
    void setVy(float value);
    void setPx(float value);
    void setPy(float value);
    // Métodos
    void actualizar(void);
   // void calcularAcc(float dt);
    void calcularVel(float dt);
    void calcularPos(float dt);
    void imprimir(void);

};

#endif // CUERPO_H
