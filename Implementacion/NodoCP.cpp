#ifndef NODOCP_CPP
#define NODOCP_CPP
#include "NodoCP.h"

template <class T>
const T& NodoCP<T>::GetElemento() const
{
	return _element;
}

template <class T>
const nat NodoCP<T>::GetPrioridad() const
{
	return _prioridad;
}

template <class T>
void NodoCP<T>::SetElemento(const T& e)
{
	this->_element = e;
}

template <class T>
void NodoCP<T>::SetPrioridad(const nat p)
{
	this->_prioridad = p;
}
#endif
