#include "Socio.h"
#include <iostream>
#include <string>

using namespace std;

Socio::Socio(string ci, string nombre, DtFecha fechaIngreso) : fechaIngreso(fechaIngreso)
{
    this->ci = ci;
    this->nombre = nombre;
    this->tope_Mascota = 0;
    this->tope_Consulta = 0;
}

string Socio::getCi()
{
    return this->ci;
}

void Socio::setCi(string ci)
{
    this->ci = ci;
}

string Socio::getNombre()
{
    return this->nombre;
}

void Socio::setNombre(string nombre)
{
    this->nombre = nombre;
};

DtFecha Socio::getFechaIngreso()
{
    return this->fechaIngreso;
}

void Socio::setFechaIngreso(DtFecha fechaIngreso)
{
    this->fechaIngreso = fechaIngreso;
}

Socio::~Socio()
{

    for (int i = this->tope_Consulta; i < 0; i--)
    {

        this->consulta[i] = this->consulta[this->tope_Consulta - 1];
        this->consulta[this->tope_Consulta - 1] = NULL;
        delete this->consulta[this->tope_Consulta - 1];
        this->tope_Consulta--;
    }
    for (int i = this->tope_Mascota; i < 0; i--)
    {

        this->mascota[i] = this->mascota[this->tope_Mascota - 1];
        this->mascota[this->tope_Mascota - 1] = NULL;
        delete this->mascota[this->tope_Mascota - 1];
        this->tope_Mascota--;
    }
}

void Socio::agregarMascota(Mascota *mascota)
{
    cout << "Prueba 1.5.1" << endl;
    if (this->tope_Mascota < 10)
    {
        this->mascota[this->tope_Mascota] = mascota;
        this->tope_Mascota++;
    }
    else
    {
        cout << "El maximo de mascota es 10" << endl;
        system("sleep 1");
    }
}

DtMascota **Socio::getMascota()
{
    cout << "Prueba 1.6.1" << endl;
    DtMascota **mascotas = new DtMascota *[this->tope_Mascota];
    for (int i = 0; i < this->tope_Mascota; i++)
    {
        try
        {
            cout << "Prueba 1.6.2" << endl;
            DtPerro *perro = dynamic_cast<DtPerro *>(mascotas[i]);
            mascotas[i] = perro;
        }
        catch (bad_cast)
        {
            cout << "Prueba 1.6.3" << endl;
            DtGato *gato = dynamic_cast<DtGato *>(mascotas[i]);
            mascotas[i] = gato;
        }
    }
    return mascotas;
}

void Socio::agregarConsulta(Consulta *consulta)
{
    if (this->tope_Consulta < 20)
    {
        this->consulta[this->tope_Consulta] = consulta;
        this->tope_Consulta++;
    }
    else
    {
        cout << "El maximo de consultas es 20" << endl;
    }
}

int Socio::getCatConsulta()
{
    return this->tope_Consulta;
}

DtConsulta **Socio::getConsulta()
{
    DtConsulta **consultas = new DtConsulta *[this->tope_Consulta];
    for (int i = 0; i < this->tope_Consulta; i++)
    {
        DtConsulta *consulta = new DtConsulta(this->consulta[i]->getMotivo(),
                                              this->consulta[i]->getFechaConsulta());
        consultas[i] = consulta;
    }
    return consultas;
}

int Socio::getCatMascota()
{
    return this->tope_Mascota;
}
