#ifndef DTMASCOTA
#define DTMASCOTA

#include <iostream>
#include <string>

#include "Genero.h"

using namespace std;

class DtMascota
{
private:
    string nombre;
    Genero genero;
    float peso;
    float racionDiaria;

public:

    DtMascota(string nombre, Genero genero, float peso , float racionDiaria);
    string getNombre();
    void setNombre(string nombre);
    Genero getGenero();
    void setGenero(Genero genero);
    float getPeso();
    void setPeos(float peso);
    ~DtMascota();

    virtual string tipoMascota() = 0;
    virtual float RacionDiaria() = 0;

};

#endif

