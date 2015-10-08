#pragma once
#include  "ListaIteracion.h"

template <class T>
ListaIteracion<T>::ListaIteracion(Puntero<NodoLista<T>> nodo)
{
	_lista = nodo;
	_inicio = nodo;
}

template<class T>
bool ListaIteracion<T>::HayElemento() const
{
	return _lista != nullptr;
}
template<class T>
const T& ListaIteracion<T>::ElementoActual() const
{
	return _lista->GetDato();
}

template <class T>
void ListaIteracion<T>::Avanzar()
{
	_lista = _lista->_sig;
}

template <class T>
void ListaIteracion<T>::Reiniciar()
{
	_lista = _inicio;
}

template <class T>
Puntero<Iteracion<T>> ListaIteracion<T>::Clonar() const
{
	ListaIteracion<T> newList = nullptr;
	if (HayElemento())
	{
		newList = new ListaIteracion(this->_inicio->Clonar());
		newList->_lista = ClonarLista(this->_lista);
	}
	return newList;
}

template <class T>
Puntero<NodoLista<T>> ListaIteracion<T>::ClonarLista(const Puntero<NodoLista<T>> lista) const
{
	Puntero<NodoLista<T>> newNodo = nullptr;
	if (lista != nullptr)
	{
		newNodo = new NodoLista<T>(lista->GetDato());
		newNodo->SetSiguiente(ClonarLista(lista->GetSiguiente()));
	}
	return newNodo;
}

//template <class T>
//Puntero<NodoLista<T>> ListaIteracion<T>::GetLista() const
//{
//	return this->_lista;
//}
//
//template <class T>
//void ListaIteracion<T>::SetInicioLista(const Puntero<NodoLista<T>>& l)
//{
//	this->_inicio = l;
//
//}