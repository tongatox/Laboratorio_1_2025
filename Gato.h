#ifndef GATO
#define GATO

#include "Mascota.h"
#include <iostream>
#include <string>
#include "TipoPelo.h"

using namespace std;

class Gato: public Mascota
{
    private:
        TipoPelo pelo;
    public:

        Gato(string nombre,Genero genero,float peso,TipoPelo pelo);
        TipoPelo getTipoPelo();
        void setTipoPelo(TipoPelo pelo);
        ~Gato();

};

#endif