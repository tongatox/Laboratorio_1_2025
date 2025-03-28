#include <Socio.h>
#include <iostream>
#include <string>

using namespace std;

Socio::Socio(string ci, string nombre, DtFecha fechaingreso)
{
    this->ci = ci;
    this->nombre = nombre;
    this->fechaingreso = fechaingreso;
    this->tope_Mascota = 0;
    this->tope_Consulta = 0;
}

int Socio::getCi()
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

DtFecha Socio::getFechaingreso()
{
    return this->fechaingreso;
}

void Socio::setFechaingreso(DtFecha fechaingreso)
{
    this->fechaingreso = fechaingreso;
}

Socio::~Socio() {}

void Socio::agregarMascota(Mascota *mascota)
{
    this->mascota[this->tope_Mascota] = mascota;
    this->tope_Mascota++;
}

Mascota **Socio::getMascota()
{
    Mascota **mascotas = new Mascota *[this->tope_Mascota];
    for (int i = 0; i < this->tope_Mascota; i++)
    {
        Mascota *mascota = new Mascota(this->mascota[i]->getNombre(),
                                       this->mascota[i]->getGenero(),
                                       this->mascota[i]->getPeso());
        mascotas[i] = mascota;
    }
    return mascotas;
}

void Socio::eliminarMascotas()
{
    for (int i = 0; i < this->tope_Mascota; i++)
    {

        this->mascota[i] = this->mascota[this->tope_Mascota - 1];
        this->mascota[this->tope_Mascota - 1] = NULL;
        delete this->mascota[this->tope_Mascota - 1];
        this->tope_Mascota--;
    }
}

void Socio::agregarConsulta(Consulta *consulta)
{
    this->consulta[this->tope_Consulta] = consulta;
    this->tope_Consulta++;
}

Consulta **Socio::getConsulta()
{
    Consulta **consultas = new Consulta *[this->tope_Consulta];
    for (int i = 0; i < this->tope_Consulta; i++)
    {
        Consulta *consulta = new Consulta(this->consulta[i]->getMotivo(),
                                          this->consulta[i]->getFechaConsulta());
        consultas[i] = consulta;
    }
    return consultas;
}

void Socio::eliminarConsultas()
{
    for (int i = 0; i < this->tope_Consulta; i++)
    {

        this->consulta[i] = this->consulta[this->tope_Consulta - 1];
        this->consulta[this->tope_Consulta - 1] = NULL;
        delete this->consulta[this->tope_Consulta - 1];
        this->tope_Consulta --;
    }
}
