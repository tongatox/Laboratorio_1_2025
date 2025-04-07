#ifndef SOCIO
#define SOCIO

#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Mascota.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "Consulta.h"
#include "DtConsulta.h"
#include "Perro.h"
#include "Gato.h"

using namespace std;

#define MAX_MASCOTA 10
#define MAX_CONSULTA 20

class Socio
{
private:
    string ci;
    string nombre;
    DtFecha  fechaIngreso;
    Mascota *mascota[MAX_MASCOTA];
    Consulta *consulta[MAX_CONSULTA];
    int tope_Mascota;
    int tope_Consulta;

public:
    Socio(string ci, string nombre, DtFecha fechaIngreso);
    string getCi();
    void setCi(string ci);
    string getNombre();
    void setNombre(string nombre);
    DtFecha getFechaIngreso();
    void setFechaIngreso(DtFecha  fechaIngreso);
    ~Socio();

    int getCatMascota();
    void agregarMascota(Mascota *mascota);
    DtMascota **getMascota();

    int getCatConsulta();
    void agregarConsulta(Consulta *consulta);
    DtConsulta **getConsulta(DtFecha * fecha, int & cantConsultas);
};

#endif