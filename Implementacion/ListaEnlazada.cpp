#pragma once
#include "ListaEnlazada.h"

template <class T>
ListaEnlazada<T>::ListaEnlazada(const Puntero<Comparador<T>> comp)
{
	this->_lista = nullptr;
	this->_inicio = nullptr;
	this->_comp = comp;
	this->cantElementos = 0;
	this->_iter = new ListaIteracion<T>(_inicio);
}

template <class T>
void ListaEnlazada<T>::Insertar(const T& x)
{
	Iterador<T> it = this->ObtenerIterador();
	Puntero<NodoLista<T>> ant = nullptr;
	while (it->HayElemento())
	{
		ant = it->GetLista();
		it->Avanzar();
	}
	Puntero<NodoLista<T>> nuevo = new NodoLista<T>(x);
	ant->SetSiguiente(nuevo);
	this->cantElementos = cantElementos + 1;
}

template <class T>
const nat ListaEnlazada<T>::Largo() const
{
	return cantElementos;
}

template <class T>
void ListaEnlazada<T>::Eliminar(const T& x)
{
	if (Existe(x))
	{
		Iterador<T> it = this->ObtenerIterador();
		Puntero<NodoLista<T>> ant = nullptr;
		
		while (_comp->SonDistintos(it.ElementoActual(),x))
		{
			ant = it->GetLista();
			it->Avanzar();
		}

		Puntero<NodoLista<T>> aBorrar = it->GetLista();
		ant->SetSiguiente(aBorrar->GetSiguiente());
		
		aBorrar = nullptr;
		this->cantElementos = cantElementos - 1;
	}
}

template <class T>
bool ListaEnlazada<T>::Existe(const T& x)
{
	bool existe = false;

	if (_inicio != nullptr)
	{
		Iterador<T> it = this->ObtenerIterador();

		while (it.HayElemento() && _comp->SonDistintos(it.ElementoActual(), x))
		{
			it.Avanzar();
		}

		if (it.HayElemento())
		{
			existe = true;
		}
	}
	return existe;
}

template <class T>
Puntero<NodoLista<T>> ListaEnlazada<T>::Recuperar(const T& x)
{
	Puntero<NodoLista<T>> nodo = nullptr;
	Iterador<T> it = this->ObtenerIterador();

	if (Existe(x))
	{
		while (_comp->SonDistintos(it.ElementoActual(), x))
		{
			it->Avanzar();
		}
		nodo = it->GetLista();
	}

	return nodo;
}

template <class T>
Iterador<T> ListaEnlazada<T>::ObtenerIterador() const
{
	_iter.Reiniciar();
	return _iter;
}

