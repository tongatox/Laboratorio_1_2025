#ifndef CONSULTA
#define CONSULTA

#include <iostream>
#include <string>
#include "DtFecha.h"
using namespace std;


class Consulta
{
private:
    string motivo;
    DtFecha fechaConsulta;
public:
    Consulta(string motivo,DtFecha fechaConsulta);
    string getMotivo();
    void  setMotivo(string motivo);
    DtFecha getFechaConsulta();
    void setFechaConsulta(DtFecha fechaConsulta);
    ~Consulta();
};


#endif