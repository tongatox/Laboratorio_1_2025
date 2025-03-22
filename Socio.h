#ifndef SOCIO
#define SOCIO

#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Mascota.h"
using namespace std;

class Socio {
    private:
        int ci;
        string nombre;
        DtFecha fechaingreso;
        Mascota * mascota;
    public:

        Socio(int ci, string nombre, DtFecha fechaingreso);
        int getCi();
        void setCi(int ci);
        string getNombre();
        void setNombre(string nombre);
        DtFecha getFechaingreso();
        void setFechaingreso(DtFecha fechaingreso);
        ~Socio();

};










#endif