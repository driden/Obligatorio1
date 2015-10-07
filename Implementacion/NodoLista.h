#pragma once
#include "Puntero.h" 

template <class T>
class NodoLista < T >
{
private:
	T& _dato;
	Puntero<NodoLista<T>>& _sig;

public:
	NodoLista(const T& dato)
	{
		_dato = dato;
		_sig = nullptr;
	}

	T& GetDato();
	Puntero<NodoLista<T>> GetSiguiente();
	void SetSiguiente(const Puntero < NodoLista<T>> sig);

};