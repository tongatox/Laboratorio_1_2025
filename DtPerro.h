#ifndef DTPERRO
#define DTPERRO

#include <iostream>
#include <string>
#include "DtMascota.h"
#include "RazaPerro.h"

using namespace std;

class DtPerro : public DtMascota
{
private:
    RazaPerro raza;
    bool vacunaCachorro;
public:
    DtPerro(string nombre, Genero genero,float peso , RazaPerro raza,bool vacunaCachorro);
    RazaPerro getRaza();
    void setRaza(RazaPerro raza);
    bool getVacunaCachorro();
    void setVacunaCachorro(bool vacunaCachorro);
    ~DtPerro();
};




#endif