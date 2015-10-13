#ifndef COLADINAMICA_CPP
#define COLADINAMICA_CPP

#include "ColaDinamica.h"
template <class T>
void ColaDinamica<T>::Encolar(const T& elemento)
{
	Puntero<NodoLista<T>> newNodo = new NodoLista<T>(elemento);
	if (_final == nullptr)
	{
		_final = newNodo;
		_inicio = _final;
	} else
	{
		_final->SetSiguiente(newNodo);
	}
}

template <class T>
T ColaDinamica<T>::DesEncolar()
{
	T elemento = _inicio->GetDato();
	_inicio->SetSiguiente(_inicio->SetSiguiente());
	return elemento;
}

template <class T>
bool ColaDinamica<T>::EstaVacia()
{
	return _final == nullptr;
}
#endif
