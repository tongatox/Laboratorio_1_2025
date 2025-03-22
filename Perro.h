#ifndef PERRO
#define PERRO

#include "Mascota.h"
#include <iostream>
#include <string>
#include "RazaPerro.h"

using namespace std;

class Perro: public Mascota
{
    private:
        RazaPerro raza;
        bool vacunaCachorro;

    public:

        Perro(string nombre,Genero genero,float peso,RazaPerro raza , bool vacunaCachorro);
        RazaPerro getRaza();
        void setRaza(RazaPerro raza);
        bool getVacunaCachorro();
        void setVacunaCachorro(bool vacunaCachorro);
        ~Perro();

};

#endif