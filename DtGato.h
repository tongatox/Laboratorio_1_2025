#ifndef DTGATO
#define DTGATO

#include <iostream>
#include <string>
#include "TipoPelo.h"
#include "DtMascota.h"

using namespace std;

class DtGato : public DtMascota
{
private:
    TipoPelo pelo;
public:
    DtGato(string nombre,Genero genero, float peso,float racionDiaria,TipoPelo pelo);
    TipoPelo getPelo();
    void setPelo(TipoPelo pelo);
    ~DtGato();
};





#endif