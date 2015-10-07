#pragma once
#include "NodoLista.h"

template<class T>
T& NodoLista<T>::GetDato()
{
	return _dato;
}
template <class T>
Puntero<NodoLista<T>> NodoLista<T>::GetSiguiente()
{
	return _sig;
}
template <class T>
void NodoLista<T>::SetSiguiente(const Puntero < NodoLista<T>> sig)
{
	_sig = sig;
}