#pragma once
#include "NodoLista.h"

template <class T>
NodoLista<T>::NodoLista(const T& dato)
{
	_dato = dato;
	_sig = nullptr;
}

template<class T>
const T& NodoLista<T>::GetDato()
{
	return _dato;
}
template <class T>
const Puntero<NodoLista<T>> NodoLista<T>::GetSiguiente()
{
	return _sig;
}
template <class T>
void NodoLista<T>::SetSiguiente(const Puntero < NodoLista<T>> sig)
{
	_sig = sig;
}

template <class T>
Puntero<NodoLista<T>> NodoLista<T>::Clonar()
{
	NodoLista<T> newNodo = new NodoLista<T>(this->GetDato());
	newNodo.SetSiguiente(this->GetSiguiente());
	return newNodo;
}