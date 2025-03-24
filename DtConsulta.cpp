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

void DtConsulta::getFechaConsulta()
{
    return this->fechaConsulta;
}

DtFecha DtConsulta::setFechaConsulta(DtFecha fechaConsulta)
{
    this->fechaConsulta = fechaConsulta;
}

DtConsulta::~DtConsulta() {}

