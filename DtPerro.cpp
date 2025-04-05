#include "DtPerro.h"

#include <iostream>
#include <string>

using namespace std;

DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro) : DtMascota(nombre, genero, peso, racionDiaria)
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


string DtPerro::tipoMascota()
{
    return "Perro";
}


float DtPerro::RacionDiaria()
{
    int racion = this->getPeso() * 0.025;
    return racion;
}