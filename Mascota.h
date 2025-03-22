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
    ~Mascota();
};

#endif