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
// #include "TipoPelo.h"
// #include "RazaPerro.h"
// #include "Genero.h"

#include <iostream>
#include <string>

using namespace std;

#define MAX_SOCIOS 100

struct Socios
{
    Socio *s[MAX_SOCIOS];
    int tope;

} colSocios;

void menu()
{
    system("clear");
    cout << "________________________" << endl;
    cout << "_________MENU___________" << endl;
    cout << "1. Agregar Socio" << endl;
    cout << "2. Agregar Mascota" << endl;
    cout << "3. Agregar Consulta" << endl;
    cout << "4. Borrar Socios" << endl;
    cout << "5. Listar Mascotas" << endl;
    cout << "6. Salir" << endl;
    cout << "OPCION: ";
}

void agregarSocio(string ci, string nombre, DtFecha *fecha, DtMascota *dtmascota);

void menuAgregarSocio()
{
    string ci, nombre, nomMascota;
    Genero genero;
    RazaPerro raza;
    TipoPelo pelo;
    DtFecha *fecha;
    int opcion_gen, opcion_mas, opcion_raza, opcion_vac, opcion_pelo, dia, mes, anio;
    float peso, racionDiaria = 0;
    bool vac;

    system("clear");
    cout << "____________________________" << endl;
    cout << "_____Menu Agregar Socio_____" << endl;
    cout << "Ingrese Cédula: " << endl;
    cin >> ci;
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
    {
        i++;
    }
    if (colSocios.tope == 0 || colSocios.s[colSocios.tope - 1]->getCi() != ci)
    {
        cout << "Ingrese Nombre: " << endl;
        cin >> nombre;
        cout << "Ingrese fecha: " << endl;
        cout << "Día: " << endl;
        cin >> dia;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Año: " << endl;
        cin >> anio;
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
        DtPerro *perro;
        DtGato *gato;
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
            fecha = new DtFecha(dia, mes, anio);
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
            perro = new DtPerro(nomMascota, genero, peso, racionDiaria, raza, vac);
            agregarSocio(ci, nombre, fecha, perro);
            break;
        case 2:
            fecha = new DtFecha(dia, mes, anio);
            cout << "Seleccione el tipo de pelo del gato: " << endl;
            cout << "1.Corto." << endl;
            cout << "2.Mediano." << endl;
            cout << "3.Largo." << endl;
            cin >> opcion_pelo;
            switch (opcion_pelo)
            {
            case 1:
                pelo = TipoPelo(0);
                break;
            case 2:
                pelo = TipoPelo(1);
                break;
            case 3:
                pelo = TipoPelo(2);
                break;
            }
            gato = new DtGato(nomMascota, genero, peso, racionDiaria, pelo);
            agregarSocio(ci, nombre, fecha, gato);
            break;
        }
    }
    else
    {
        cout << "El socio no existe." << endl;
        system("sleep 5");
    }
}
void agregarSocio(string ci, string nombre, DtFecha *fecha, DtMascota *dtmascota)
{
    DtFecha fechaIngreso(fecha->getDia(), fecha->getMes(), fecha->getAnio());
    int i = 0;

    Socio *socio = new Socio(ci, nombre, fechaIngreso);
    colSocios.s[colSocios.tope] = socio;
    colSocios.tope++;
    if (dtmascota->tipoMascota() == "Perro")
    {
        try
        {
            DtPerro *dtp = dynamic_cast<DtPerro *>(dtmascota);
            Perro *perro = new Perro(dtp->getNombre(), dtp->getGenero(), dtp->getPeso(), dtp->getRaza(), dtp->getVacunaCachorro());
            colSocios.s[colSocios.tope - 1]->agregarMascota(perro);
            cout << "Socio y mascota agregado exitosamente" << endl;
            system("sleep 1");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << '\n';
            system("sleep 5");
        }
    }
    else if (dtmascota->tipoMascota() == "Gato")
    {
        try
        {
            DtGato *dtg = dynamic_cast<DtGato *>(dtmascota);
            Gato *gato = new Gato(dtg->getNombre(), dtg->getGenero(), dtg->getPeso(), dtg->getPelo());
            colSocios.s[colSocios.tope - 1]->agregarMascota(gato);
            cout << "Socio y mascota agregado exitosamente" << endl;
            system("sleep 1");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << '\n';
            system("sleep 5");
        }
    }
}

void agregarMascotas(string ci, DtMascota *dtmascota);

void menuAgregarMascotas()
{
    string ci, nomMascota;
    int opcion_gen, opcion_mas, opcion_raza, opcion_vac, opcion_pelo;
    RazaPerro raza;
    TipoPelo pelo;
    Genero genero;
    bool vac;
    float peso, racionDiaria;
    system("clear");
    cout << "____________________________" << endl;
    cout << "____Menu Agregar Mascota____" << endl;
    cout << "Ingrese ci del Socio: " << endl;
    cin >> ci;
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
        i++;
    if (colSocios.tope != 0 && colSocios.s[i]->getCi() == ci)
    {

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
        DtPerro *perro;
        DtGato *gato;
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
            perro = new DtPerro(nomMascota, genero, peso, racionDiaria, raza, vac);
            agregarMascotas(ci, perro);
            break;
        case 2:
            cout << "Seleccione el tipo de pelo del gato: " << endl;
            cout << "1.Corto." << endl;
            cout << "2.Mediano." << endl;
            cout << "3.Largo." << endl;
            cin >> opcion_pelo;
            switch (opcion_pelo)
            {
            case 1:
                pelo = TipoPelo(0);
                break;
            case 2:
                pelo = TipoPelo(1);
                break;
            case 3:
                pelo = TipoPelo(2);
                break;
            }
            gato = new DtGato(nomMascota, genero, peso, racionDiaria, pelo);
            agregarMascotas(ci, gato);
            break;
        }
    }
    else
    {
        cout << "El socio no existe." << endl;
        system("sleep 5");
    }
}

void agregarMascotas(string ci, DtMascota *dtmascota)
{
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
        i++;
    if (colSocios.tope != 0 && ci == colSocios.s[i]->getCi())
    {
        if (dtmascota->tipoMascota() == "Perro")
        {
            try
            {
                DtPerro *dtp = dynamic_cast<DtPerro *>(dtmascota);
                Perro *perro = new Perro(dtp->getNombre(), dtp->getGenero(), dtp->getPeso(), dtp->getRaza(), dtp->getVacunaCachorro());
                colSocios.s[i]->agregarMascota(perro);
                cout << "Mascota agregada exitosamente. " << endl;
                system("sleep 1");
            }
            catch (invalid_argument &e)
            {
                cout << e.what() << '\n';
                system("sleep 5");
            }
        }
        else if (dtmascota->tipoMascota() == "Gato")
        {
            try
            {
                DtGato *dtg = dynamic_cast<DtGato *>(dtmascota);
                Gato *gato = new Gato(dtg->getNombre(), dtg->getGenero(), dtg->getPeso(), dtg->getPelo());
                colSocios.s[i]->agregarMascota(gato);
                cout << "Mascota agregada exitosamente. " << endl;
                system("sleep 1");
            }
            catch (invalid_argument &e)
            {
                cout << e.what() << '\n';
                system("sleep 5");
            }
        }
    }
    else
    {
        cout << "No existe el socio." << endl;
        system("sleep 5");
    }
}

void ingresarConsulta(string motivo, string ci, DtFecha *fechaConsulta);

void menuIngresarConsultas()
{
    DtFecha *fecha;
    string motivo, ci;
    int dia, mes, anio;
    system("clear");
    cout << "____________________________" << endl;
    cout << "___Menu Agregar Consulta____" << endl;
    cout << "Ingrese ci de Socio: " << endl;
    cin >> ci;
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
        i++;
    if (colSocios.tope != 0 && colSocios.s[i]->getCi() == ci)
    {
        cout << "Ingrese motivo consulta: " << endl;
        cin >> motivo;
        cout << "Ingrese Fecha: " << endl;
        cout << "Dia: " << endl;
        cin >> dia;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Año: " << endl;
        cin >> anio;

        fecha = new DtFecha(dia, mes, anio);

        ingresarConsulta(motivo, ci, fecha);
    }
    else
    {
        cout << "No existe el Socio." << endl;
        system("sleep 5");
    }
}

void ingresarConsulta(string motivo, string ci, DtFecha *fecha)
{
    DtFecha fechaCon(fecha->getDia(), fecha->getMes(), fecha->getAnio());
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
        i++;
    if (colSocios.s[i]->getCi() == ci)
    {

        try
        {
            Consulta *consulta = new Consulta(motivo, fechaCon);
            colSocios.s[i]->agregarConsulta(consulta);

            cout << "Consulta agregada exitosamente." << endl;
            system("sleep 1");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << '\n';
        }
    }
    else
    {
        cout << "El Socio ingresado no existe." << endl;
        system("sleep 5");
    }
}

DtConsulta **verConsultasAntesDeFecha(DtFecha *fecha, string ciSocio, int &cantConsultas);

void menuVerConsultas()
{
    string ci;
    int dia, mes, anio;
    int cantConsultas;

    system("clear");
    cout << "____________________________" << endl;
    cout << "___Menu Mostrar Consultas___" << endl;
    cout << "Ingrese ci de Socio: " << endl;
    cin >> ci;
    cout << "Ingrese la fecha a consultar: " << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    cout << "Ingrese la cantidad de consultas que solicita: " << endl;
    cin >> cantConsultas;
    DtFecha *fecha = new DtFecha(dia, mes, anio);

    verConsultasAntesDeFecha(fecha, ci, cantConsultas);
}

DtConsulta **verConsultasAntesDeFecha(DtFecha *fecha, string ciSocio, int &cantConsultas)
{
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ciSocio)
        i++;
    if (colSocios.s[i]->getCi() == ciSocio)
    {
        return colSocios.s[i]->getConsulta(fecha, cantConsultas);
    }
    else
    {
        cout << "No existe  el socio." << endl;
        system("sleep 5");
    }
}

void eliminarSocio(string ci);

void menuEliminarSocio()
{
    string ci;

    system("clear");
    cout << "____________________________" << endl;
    cout << "_____Menu Eliminar Socio____" << endl;
    cout << "Ingrese ci del Socio a eliminar: " << endl;
    cin >> ci;

    eliminarSocio(ci);
}

void eliminarSocio(string ci)
{
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
        i++;
    if (colSocios.s[i]->getCi() == ci)
    {

        colSocios.s[i] = colSocios.s[colSocios.tope - 1];
        colSocios.s[colSocios.tope - 1] = NULL;
        delete colSocios.s[colSocios.tope - 1];
        colSocios.tope--;

        cout << "Socio eliminado exitosamente." << endl;
        system("sleep 1");
    }
    else
    {
        cout << "El Socio ingresado no existe." << endl;
        system("sleep 5");
    }
}

DtMascota **obtenerMascota(string ci, int &cantMascota);

void menuListarMascotas()
{
    string ci;
    int cantMascota;
    system("clear");
    cout << "____________________________" << endl;
    cout << "___Menu Mostrar Mascotas___" << endl;
    cout << "Ingrese ci del Socio que desea ver las mascotas: " << endl;
    cin >> ci;
    DtMascota **mascotas = obtenerMascota(ci, cantMascota);

    for (int i = 0; i <= cantMascota; i++)
    {

        int a = 0;
        while (a < colSocios.tope && colSocios.s[a]->getCi() != ci)
        {
            a++;
        }

        if (colSocios.s[a]->getCi() == ci)
        {
            if (DtPerro *perro = dynamic_cast<DtPerro *>(mascotas[i]))
            {
                cout << "- Nombre: " << perro->getNombre() << endl;
                cout << "- Genero: " << perro->getGenero() << endl;
                cout << "- Peso: " << perro->getPeso() << " kg." << endl;
                cout << "- Racion Diaria: " << perro->RacionDiaria() << " gramos." << endl;
                string vacuna;
                if (perro->getVacunaCachorro())
                {
                    cout << "- Tiene vacuna del Cachorro: Si" << endl;
                }
                else
                {
                    cout << "- Tiene vacuna del Cachorro: No" << endl;
                }

                //system("sleep 3");
            }
            else if (DtGato *gato = dynamic_cast<DtGato *>(mascotas[i]))
            {
                cout << "- Nombre: " << gato->getNombre() << endl;
                cout << "- Genero: " << gato->getGenero() << endl;
                cout << "- Peso: " << gato->getPeso() << " kg." << endl;
                cout << "- Racion Diaria: " << gato->RacionDiaria() << " gramos." << endl;
                cout << "- Tipo Pelo: " << gato->getPelo() << endl;
               // system("sleep 3");
            }
            
        }
    }
    system("sleep 3");
}

DtMascota **obtenerMascota(string ci, int &cantMascota)
{
    int i = 0;
    while (i < colSocios.tope && colSocios.s[i]->getCi() != ci)
    {
        i++;
    }
    if (colSocios.s[i]->getCi() == ci)
    {
        cantMascota = colSocios.s[i]->getCatMascota();
        return colSocios.s[i]->getMascota();
    }
    else
    {
        cout << "El socio no existe" << endl;
    }
}

int main()
{

    colSocios.tope = 0;

    menu();
    int opcion;
    cin >> opcion;
    while (opcion != 6)
    {
        switch (opcion)
        {
        case 1:
            menuAgregarSocio();
            break;
        case 2:
            menuAgregarMascotas();
            break;
        case 3:
            menuIngresarConsultas();
            break;
        case 4:
            menuEliminarSocio();
            break;
        case 5:
            menuListarMascotas();
            break;
        }
        menu();
        cin >> opcion;
    }
    cout << "CHAU!!!\n";
    system("sleep 1");
}