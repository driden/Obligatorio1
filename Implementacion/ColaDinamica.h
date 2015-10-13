#ifndef COLADINAMICA_H
#define COLADINAMICA_H

#include "Cola.h"
#include "Puntero.h"
#include "NodoLista.h"

template<class T>
class ColaDinamica : Cola<T>
{
	Puntero<NodoLista<T>> _inicio;
	Puntero<NodoLista<T>> _final;

	ColaDinamica<T>() {
		_inicio = nullptr;
		_final = nullptr;
	}
	void Encolar(const T& elemento) override;
	T DesEncolar() override;
	bool EstaVacia() override;
};


#endif
#include "ColaDinamica.cpp"