#ifndef MASCOTA
#define MASCOTA
#include <iostream>
#include <string>
#include "Genero.h"
using namespace std;

class Mascota
{
private:
    string nombre;
    Genero genero;
    float peso;

public:
    Mascota(string nombre, Genero genero, float peso);
    string getNombre();
    void setNombre(string nombre);
    Genero getGenero();
    void setGenero(Genero genero);
    float getPeso();
    void setPeso(float peso);
    virtual ~Mascota() = 0;

    virtual float calcularRacion() = 0 ;
    virtual string tipoMascota() = 0;
};

#endif