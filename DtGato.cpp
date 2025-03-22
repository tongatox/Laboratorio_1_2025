#include "DtGato.h"

#include <iostream>
#include <string>

using namespace std;

DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo pelo) : DtMascota(nombre, genero, peso, racionDiaria)
{
    this->pelo = pelo;
}

TipoPelo DtGato::getPelo()
{
    return this->pelo;
}

void DtGato::setPelo(TipoPelo pelo)
{
    this->pelo = pelo;
}

DtGato::~DtGato() {}