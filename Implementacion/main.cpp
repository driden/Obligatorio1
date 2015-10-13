﻿#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"
#include "Lista.h"
#include "ListaEnlazada.h"
#include "Utilidades.h"
#include "ComparadorInt.h"
#include "ListaEnlazada.cpp"
#include "HashImp.h"
#include "TablaHash.h"
#include "CadenaFuncionHash.h"
#include "NodoLista.h"
#include "ColaPrioridadAcotada.h"
#include "SetAcotado.h"
#include "ComparadorCadena.h"
#include "GrafoAcotado.h"



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

	//Comparador<int> comp = new ComparadorInt();
	//Puntero<Lista<int>> lista = new ListaEnlazada<int>(comp);

	//lista->Insertar(1);
	//lista->Insertar(2);
	//lista->Insertar(3);
	//lista->Insertar(4);

	//cout << "Existe(10)? " << lista->Existe(10) << endl;
	//cout << "Existe(1)? " << lista->Existe(1) << endl;
	//cout << "Existe(2)? " << lista->Existe(2) << endl;
	//cout << "Existe(3)? " << lista->Existe(3) << endl;
	//cout << "Existe(5)? " << lista->Existe(5) << endl;
	//cout << "Existe(7)? " << lista->Existe(7) << endl;

	//lista->Eliminar(1);
	//cout << "<<<<ELIMINAR 1>>>>>" << endl;
	//cout << "Existe(1)? " << lista->Existe(1) << endl;
	//
	//lista->Eliminar(4);
	//cout << "<<<<ELIMINAR 4>>>>>" << endl;
	//cout << "Existe(4)? " << lista->Existe(4) << endl;
	//
	//cout << "<<<<INSERTA 1>>>>>" << endl;
	//lista->Insertar(1);
	//cout << "<<<<<BORRA 2>>>>>" << endl;
	//lista->Eliminar(2);
	//cout << "Existe(2)? " << lista->Existe(2) << endl;


	//
	//
	//Iterador<int> it = lista->ObtenerIterador();

	//while (it.HayElemento()) 
	//{
	//	cout << it.ElementoActual() << endl;
	//	it.Avanzar();
	//}

	/* PRUEBAS DE LAS OPERACIONES DE HASH MAP */
	//Puntero<TablaHash<Cadena, int>> hashMap = new HashImp<Cadena, int>(4,new CadenaFuncionHash() , comp);

	/*


	hashMap->Agregar("Uno", 1);
	hashMap->Agregar("Dos", 2);
	hashMap->Agregar("Tres", 3);
	hashMap->Agregar("Cuatro", 4);
	hashMap->Agregar("Uno", 11);
	hashMap->Agregar("Uno", 111);

	hashMap->Borrar("Uno");
	hashMap->Borrar("Dos");
	hashMap->Borrar("Tres");
	hashMap->Borrar("Cuatro");
	hashMap->Borrar("Uno");

	hashMap->EstaLlena();
	hashMap->EstaVacia();
	hashMap->Largo();

	//hashMap->Obtener("Uno", 1);
	hashMap->Pertenece("Uno");
	hashMap->Pertenece("Dos");
	hashMap->Pertenece("Tres");
	hashMap->Pertenece("Cuatro");
	hashMap->Pertenece("0");


	*/
	/*PRUEBAS DE LAS OPERACIONES DE SET*/

	//Comparador<int> cmp = new ComparadorInt();
	//Puntero<SetAcotado<int>> set = new SetAcotado<int>(10, cmp);
	//Puntero<SetAcotado<int>> setAComparar = new SetAcotado<int>(15, cmp);

	//	set->EsLleno();
	//set->EsVacio();
	//set->Tamanio();

	//set->Insertar(5);
	//set->Insertar(10);
	//set->Insertar(25);
	//set->Eliminar(25);
	//set->Eliminar(10);
	//set->Imprimir();
	//
	//	set->Pertenece(5);
	//	set->Pertenece(-1);
	//	set->Pertenece(0);

	//	set->Eliminar(5);
	//	set->EsLleno();
	//	set->EsVacio();
	//	set->Tamanio();


	//Puntero<ColaPrioridad<int>> pq = new ColaPrioridadAcotada<int>(10);

	//pq->Insertar(13,13);
	//pq->Insertar(21,21);
	//pq->Insertar(16,16);
	//pq->Insertar(24,24);
	//pq->Insertar(31,31);
	//pq->Insertar(19,19);
	//pq->Insertar(68,68);
	//pq->Insertar(65,65);
	//pq->Insertar(26,26);
	//pq->Insertar(32,32);
	//
	//pq->BorrarMin();

	//Puntero<SetAcotado<int>> retornoUnion =set->Union(setAComparar);
	//Puntero<SetAcotado<int>> retornoInterseccion = set->Interseccion(setAComparar);
	//Puntero<SetAcotado<int>> retornoDiferencia = set->Diferencia(setAComparar);
	//retornoUnion->Imprimir();
	//retornoInterseccion->Imprimir();
	//retornoDiferencia->Imprimir();

	Comparador<Cadena> comparadorCadena = new ComparadorCadena();
	Puntero<Set<Cadena>> vertices = new SetAcotado<Cadena>(8, comparadorCadena);

	vertices->Insertar("Cero");
	vertices->Insertar("Uno");
	vertices->Insertar("Dos");
	vertices->Insertar("Tres");
	vertices->Insertar("Cuatro");
	vertices->Insertar("Cinco");
	vertices->Insertar("Seis");
	vertices->Insertar("Siete");

	Puntero<Grafo<Cadena>> grafo = new GrafoAcotado<Cadena>(vertices, comparadorCadena);
	Cadena cero = Cadena("Cero");
	Cadena uno = Cadena("Uno");
	Cadena dos = Cadena("Dos");
	Cadena tres = Cadena("Tres");
	Cadena cuatro = Cadena("Cuatro");
	Cadena cinco = Cadena("Cinco");
	Cadena seis = Cadena("Seis");
	Cadena siete = Cadena("Siete");

	grafo->InsertarArista(cero, uno, 4);
	grafo->InsertarArista(cero, tres,5 );
	grafo->InsertarArista(dos, uno, 2);
	grafo->InsertarArista(dos, cuatro, 8);
	grafo->InsertarArista(dos, cinco, 3);
	grafo->InsertarArista(cuatro, seis, 1);
	grafo->InsertarArista(cinco, tres, 1);
	grafo->InsertarArista(seis, cuatro, 1);
	grafo->InsertarArista(siete, seis, 9);

	grafo->CaminoMasCorto(dos, seis);
	system("pause");
}
