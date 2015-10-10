#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"
#include "Lista.h"
#include "ListaEnlazada.h"
#include "Utilidades.h"
#include "ComparadorInt.h"
#include "ListaEnlazada.cpp"

#include "NodoLista.h"
Puntero<ISistema> Inicializar(nat MAX_BARRIOS, nat MAX_CLIENTES)
{
	return new Sistema(MAX_BARRIOS, MAX_CLIENTES);
}

void main()
{
	//Puntero<ConductorPrueba> cp = new ConductorPrueba();
	//Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	//pruebas[0] = new PruebaMemoria();
	//pruebas[1] = new CasoDePrueba(Inicializar);
	//pruebas[2] = pruebas[0];
	//cp->CorrerPruebas(pruebas.ObtenerIterador());

	//cout << "dsps del 0 " << Utilidades::ProximoPrimo(0) << endl;
	//cout << "dsps del 1 " << Utilidades::ProximoPrimo(1) << endl;
	//cout << "dsps del 2 " << Utilidades::ProximoPrimo(2) << endl;
	//cout << "dsps del 3 " << Utilidades::ProximoPrimo(3) << endl;
	//cout << "dsps del 4 " << Utilidades::ProximoPrimo(4) << endl;
	//cout << "dsps del 5 " << Utilidades::ProximoPrimo(5) << endl;
	//cout << "dsps del 8 " << Utilidades::ProximoPrimo(8) << endl;
	//cout << "dsps del 17 " << Utilidades::ProximoPrimo(17) << endl;
	//cout << "dsps del 55 " << Utilidades::ProximoPrimo(55) << endl;
	//cout << "dsps del 401 " << Utilidades::ProximoPrimo(401) << endl;
	//cout << "dsps del 1602 " << Utilidades::ProximoPrimo(1602) << endl;
	//cout << "dsps del 3511 " << Utilidades::ProximoPrimo(3511) << endl;

	Comparador<int> comp = new ComparadorInt();
	Puntero<Lista<int>> lista = new ListaEnlazada<int>(comp);
	
	
	lista->Insertar(1);
	lista->Insertar(2);
	lista->Insertar(3);
	lista->Insertar(4);


	system("pause");
}
