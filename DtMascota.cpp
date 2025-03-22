#include "DtMascota.h"

#include <iostream>
#include <string>
using namespace std;

DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiaria)
{
    this->nombre = nombre;
    this->genero = genero;
    this->peso = peso;
    this->racionDiaria = racionDiaria;
}

string DtMascota::getNombre()
{
    return this->nombre;
}

void DtMascota::setNombre(string nombre)
{
    this->nombre = nombre;
}

Genero DtMascota::getGenero()
{
    return this->genero;
}

void DtMascota::setGenero(Genero genero)
{
    this->genero = genero;
}

float DtMascota::getPeso()
{
    return this->peso;
}

void DtMascota::setPeos(float peso)
{
    this->peso = peso;
}

float DtMascota::getRacionDiaria()
{
    return this->racionDiaria;
}

void DtMascota::setRacionDiaria(float racionDiaria)
{
    this->racionDiaria = racionDiaria;
}

DtMascota::~DtMascota() {}