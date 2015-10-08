#pragma once

#include "Puntero.h"

template <class T>
class NodoLista
{
	T _dato;
	Puntero<NodoLista<T>>& _sig;
public:
	NodoLista<T>(const T& dato);
	const T& GetDato();
	const Puntero<NodoLista<T>> GetSiguiente();
	void SetSiguiente(const Puntero<NodoLista<T>> sig);

	Puntero<NodoLista<T>> Clonar();


};