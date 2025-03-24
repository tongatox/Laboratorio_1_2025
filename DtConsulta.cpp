#include "DtConsulta.h"

#include <iostream>
#include <string>

using namespace std;

DtConsulta::DtConsulta(string motivo, DtFecha fechaConsulta)
{
    this->motivo = motivo;
    this->fechaConsulta = fechaConsulta;
}

string DtConsulta::getMotivo()
{
    return this->motivo;
}

void DtConsulta::setMotivo(string motivo)
{
    this->motivo = motivo;
}

DtFecha DtConsulta::getFechaConsulta()
{
    return this->fechaConsulta;
}

void DtConsulta::setFechaConsulta(DtFecha fechaConsulta)
{
    this->fechaConsulta = fechaConsulta;
}

DtConsulta::~DtConsulta() {}

