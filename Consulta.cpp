#include "Consulta.h"

#include <iostream>
#include <string>

using namespace std;

Consulta::Consulta(string motivo, DtFecha fechaConsulta)
{
    this->motivo = motivo;
    this->fechaConsulta = fechaConsulta;
}

string Consulta::getMotivo()
{
    return this->motivo;
}

void Consulta::setMotivo(string motivo)
{
    this->motivo = motivo;
}

DtFecha Consulta::getFechaConsulta()
{
    return this->fechaConsulta;
}

void Consulta::setFechaConsulta(DtFecha fechaConsulta)
{
    this->fechaConsulta = fechaConsulta;
}

Consulta::~Consulta() {}
