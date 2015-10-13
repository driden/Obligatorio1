#ifndef GRAFO_H
#define GRAFO_H

typedef unsigned int nat;

template<class T>
class Grafo abstract
{
	public:
	
	virtual ~Grafo() {}

	virtual bool InsertarArista(T& origen, T& destino, nat peso) abstract;

	virtual bool CaminoMasCorto(T& origen, T&destino) abstract; //Dijkstra

	virtual bool SubgrafoRecubridorCostoMinimo() abstract; //Prim
};

#endif