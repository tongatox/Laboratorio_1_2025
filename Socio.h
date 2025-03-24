#ifndef SOCIO
#define SOCIO

#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"

using namespace std;

#define MAX_MASCOTA 10
#define MAX_CONSULTA 20

class Socio
{
private:
    int ci;
    string nombre;
    DtFecha fechaingreso;
    Mascota *mascota[MAX_MASCOTA];
    Consulta *consulta[MAX_CONSULTA];
    int tope_Mascota;
    int tope_Consulta;

public:
    Socio(int ci, string nombre, DtFecha fechaingreso);
    int getCi();
    void setCi(int ci);
    string getNombre();
    void setNombre(string nombre);
    DtFecha getFechaingreso();
    void setFechaingreso(DtFecha fechaingreso);
    ~Socio();

    void agregarMascota(Mascota *mascota);
    Mascota **getMascota();

    void agregarConsulta(Consulta *consulta);
    Consulta **getConsulta();
};

#endif