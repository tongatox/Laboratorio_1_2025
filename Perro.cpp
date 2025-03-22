#include "Perro.h"

#include <iostream>
#include <string>

using namespace std;

Perro::Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro) : Mascota(nombre, genero, peso)
{
    this->raza = raza;
    this->vacunaCachorro = vacunaCachorro;
}

RazaPerro Perro::getRaza()
{
    return this->raza;
}

void Perro::setRaza(RazaPerro raza)
{
    this->raza = raza;
}

bool Perro::getVacunaCachorro()
{
    return this->vacunaCachorro;
}
void Perro::setVacunaCachorro(bool vacunaCachorro)
{
    this->vacunaCachorro = vacunaCachorro;
}

Perro::~Perro() {}


