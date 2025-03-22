#include "Gato.h"

#include <iostream>
#include <string>

using namespace std;

Gato::Gato(string nombre, Genero genero, float peso, TipoPelo pelo) : Mascota(nombre, genero, peso)
{
    this->pelo = pelo;
}

TipoPelo Gato::getTipoPelo() {
    return this -> pelo;
}

void Gato::setTipoPelo(TipoPelo pelo)
{
    this->pelo = pelo;
}

Gato::~Gato() {}
