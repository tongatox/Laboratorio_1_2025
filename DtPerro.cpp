#include "DtPerro.h"

#include <iostream>
#include <string>

using namespace std;

DtPerro::DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro) : DtMascota(nombre, genero, peso)
{
    this->raza = raza;
    this->vacunaCachorro = vacunaCachorro;
}

RazaPerro DtPerro::getRaza()
{
    return this->raza;
}

void DtPerro::setRaza(RazaPerro raza)
{
    this->raza = raza;
}

bool DtPerro::getVacunaCachorro()
{
    return this->vacunaCachorro;
}

void DtPerro::setVacunaCachorro(bool vacunaCachorro)
{
    this->vacunaCachorro = vacunaCachorro;
}

DtPerro::~DtPerro() {}