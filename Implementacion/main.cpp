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

	cout << "Existe(10)? " << lista->Existe(10) << endl;
	cout << "Existe(1)? " << lista->Existe(1) << endl;
	cout << "Existe(2)? " << lista->Existe(2) << endl;
	cout << "Existe(3)? " << lista->Existe(3) << endl;
	cout << "Existe(5)? " << lista->Existe(5) << endl;
	cout << "Existe(7)? " << lista->Existe(7) << endl;

	lista->Eliminar(1);
	cout << "<<<<ELIMINAR 1>>>>>" << endl;
	cout << "Existe(1)? " << lista->Existe(1) << endl;
	
	lista->Eliminar(4);
	cout << "<<<<ELIMINAR 4>>>>>" << endl;
	cout << "Existe(4)? " << lista->Existe(4) << endl;
	
	cout << "<<<<INSERTA 1>>>>>" << endl;
	lista->Insertar(1);
	cout << "<<<<<BORRA 2>>>>>" << endl;
	lista->Eliminar(2);
	cout << "Existe(2)? " << lista->Existe(2) << endl;


	
	
	Iterador<int> it = lista->ObtenerIterador();

	while (it.HayElemento()) 
	{
		cout << it.ElementoActual() << endl;
		it.Avanzar();
	}
	
	




	system("pause");
}
