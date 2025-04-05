todo: Main.o Socio.o Mascota.o Perro.o Gato.o Consulta.o DtMascota.o DtPerro.o DtGato.o DtConsulta.o DtFecha.o
	g++ -Wall -o main Main.o Socio.o Mascota.o Perro.o Gato.o Consulta.o DtMascota.o DtPerro.o DtGato.o DtConsulta.o DtFecha.o 
Main.o: Main.cpp
	g++ -Wall -c Main.cpp 
Socio.o:
	g++ -Wall -c Socio.cpp
Mascota.o:
	g++ -Wall -c Mascota.cpp
Perro.o:
	g++ -Wall -c Perro.cpp
Gato.o:
	g++ -Wall -c Gato.cpp
Consulta.o:
	g++ -Wall -c Consulta.cpp
DtMascota.o:
	g++ -Wall -c DtMascota.cpp
DtPerro.o:
	g++ -Wall -c DtPerro.cpp
DtGato.o:
	g++ -Wall -c DtGato.cpp
DtConsulta.o:
	g++ -Wall -c DtConsulta.cpp
DtFecha.o:
	g++ -Wall -c DtFecha.cpp

clean:
	rm -f *.o
	rm -f main