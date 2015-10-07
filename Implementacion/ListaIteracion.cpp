#pragma once
#include  "ListaIteracion.h"

template <class T>
ListaIteracion<T>::ListaIteracion(Puntero<NodoLista<T>> nodo, Puntero<Comparador<T>> comp)
{
	_lista = nodo;
	_comp = comp;
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
//template<class T>
//void Avanzar() override;
//template<class T>
//void Reiniciar() override;