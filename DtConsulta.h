#ifndef DTCONSULTA
#define DTCONSULTA

#include <iostream>
#include <string>
#include "DtFecha.h"

using namespace std;

class DtConsulta
{
private:
    string motivo;
    DtFecha fechaConsulta;
public:
    DtConsulta(string motivo,DtFecha fechaConsulta);
    string getMotivo();
    void setMotivo(string motivo);
    ~DtConsulta();
};

#endif