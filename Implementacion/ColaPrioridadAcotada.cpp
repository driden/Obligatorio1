#ifndef COLAPRIORIDADACOTADA_CPP
#define COLAPRIORIDADACOTADA_CPP
#include "ColaPrioridadAcotada.h"


template <class T>
ColaPrioridadAcotada<T>::ColaPrioridadAcotada(nat max)
{
	//la cubeta 0 NO SE USA!
	_pqueue = Array<NodoCP<T>>(max + 1);
	_tope = 1;
}

template <class T>
void ColaPrioridadAcotada<T>::Insertar(const T& x, const nat p)
{
}

template <class T>
nat ColaPrioridadAcotada<T>::Tamanio()
{
	//tope arranca en 1, entonces
	return _tope - 1;
}

template <class T>
bool ColaPrioridadAcotada<T>::EstaVacia()
{
	return this == nullptr || this->_tope = 1;
}

#endif