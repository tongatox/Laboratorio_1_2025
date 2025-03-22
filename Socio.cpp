#include <Socio.h>
#include <iostream>
#include <string>

using namespace std;

Socio::Socio(int ci, string nombre, DtFecha fechaingreso)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaingreso = fechaingreso;
}

int Socio::getCi()
{
    return this->ci;
}

void Socio::setCi(int ci)
{
    this->ci = ci;
}

string Socio::getNombre()
{
    return this->nombre;
}

void Socio::setNombre(string nombre)
{
    this->nombre = nombre;
};

DtFecha Socio::getFechaingreso()
{
    return this->fechaingreso;
}

void Socio::setFechaingreso(DtFecha fechaingreso)
{
    this->fechaingreso = fechaingreso;
}

Socio::~Socio() {}