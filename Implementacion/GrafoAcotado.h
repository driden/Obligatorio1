#ifndef GRAFOACOTADO_H
#define GRAFOACOTADO_H

#include "Grafo.h"
#include "Set.h"
#include "Puntero.h"
#include "Array.h"

template<class T>
class GrafoAcotado : public Grafo<T>
{
	private:
	Array<T> _vertices;
	Array<Array<nat>> _matrizAdyacencia;	
	Comparador<T> _comparador;

	public:
	GrafoAcotado<T>(Puntero<Set<T>> &vertices,Comparador<T> comp);

	bool InsertarArista(T& origen, T& destino, nat peso) override;

	nat AdyacenteConMenorCosto(nat previo, Array<bool> conocido, Array<nat> costo, Array<int> anterior);
	void ImprimirCaminoMasCorto(nat v_origen, nat v_destino, Array<int> anterior);
	bool HayCamino(nat v_origen, nat v_destino, Array<int> anterior);
	bool CaminoMasCorto(T& origen, T&destino) override; //Dijkstra

	bool SubgrafoRecubridorCostoMinimo() override; //Prim

	//Auxiliares para usar con el array local donde se guardan los vertices
	T VerticeEnIndice(const nat i);
	nat IndiceElemento(const T &elem);
};
#endif
#include "GrafoAcotado.cpp"
