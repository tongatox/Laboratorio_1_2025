#include "Socio.h"
#include "Consulta.h"
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "DtConsulta.h"
#include "DtMascota.h"
#include "DtGato.h"
#include "DtPerro.h"
#include "DtFecha.h"
//#include "TipoPelo.h"
//#include "RazaPerro.h"
//#include "Genero.h"

#include <iostream>
#include <string>

using namespace std;

#define MAX_SOCIOS 100

struct Socios
{
    Socios *s[MAX_SOCIOS];
    int tope;
} colSocios;

void menu()
{
    system("clear");
    cout << "____________________________" << endl;
    cout << "_________MENU___________" << endl;
    cout << "1. Agregar Socio" << endl;
    cout << "2. Agregar Mascota" << endl;
    cout << "3. Agregar Consulta" << endl;
    cout << "4. Listar Consultas" << endl;
    cout << "5. Borrar Socios" << endl;
    cout << "6. Listar Mascotas" << endl;
    cout << "7. Calcular Racion" << endl;
    cout << "8. Salir" << endl;
    cout << "OPCION: ";
}

void agregarsocio(string ci, string nombre, DtMascota &dtmascota);

void menuAgregarSocio()
{
    string ci, nombre, nomMascota;
    Genero genero;
    RazaPerro raza;
    int opcion_gen, opcion_mas, opcion_raza, opcion_vac;
    float peso;
    bool vac;

    system("clear");
    cout << "____________________________" << endl;
    cout << "_____Menu Agregar Socio_____" << endl;
    cout << "Ingrese Cédula: " << endl;
    cin >> ci;
    cout << "Ingrese Nombre: " << endl;
    cin >> nombre;
    cout << "Seleccione tipo mascota." << endl;
    cout << "1.Perro." << endl;
    cout << "2.Gato." << endl;
    cin >> opcion_mas;
    cout << "Ingrese nombre Mascota: " << endl;
    cin >> nomMascota;
    cout << "Seleccione genero de la mascota." << endl;
    cout << "1.Macho." << endl;
    cout << "2.Hembra." << endl;
    cin >> opcion_gen;
    switch (opcion_gen)
    {
    case 1:
        genero = Genero(0);
        break;
    case 2:
        genero = Genero(1);
        break;
    }
    cout << "Ingrese peso: " << endl;
    cin >> peso;
    DtPerro perro;
    DtGato gato;
    switch (opcion_mas)
    {
    case 1:

        cout << "Seleccione la raza del perro." << endl;
        cout << "1.Labrador." << endl;
        cout << "2.Ovejero." << endl;
        cout << "3.Bulldog." << endl;
        cout << "4.Pitbull." << endl;
        cout << "5.Collie." << endl;
        cout << "6.Pekines." << endl;
        cout << "7.Otro." << endl;
        cin >> opcion_raza;
        cout << "El perro fue vacunado de cachorro." << endl;
        cout << "1.Si." << endl;
        cout << "2.No." << endl;
        cin >> opcion_vac;
        switch (opcion_raza)
        {
        case 1:
            raza = RazaPerro(0);
            break;
        case 2:
            raza = RazaPerro(1);
            break;
        case 3:
            raza = RazaPerro(2);
            break;
        case 4:
            raza = RazaPerro(3);
            break;
        case 5:
            raza = RazaPerro(4);
            break;
        case 6:
            raza = RazaPerro(5);
            break;
        case 7:
            raza = RazaPerro(6);
            break;
        }
        switch (opcion_vac)
        {
        case 1:
            vac = true;
            break;

        case 2:
            vac = false;
            break;
        }
        perro = DtPerro();

    case 2:
        genero = Genero(1);
    }
}
