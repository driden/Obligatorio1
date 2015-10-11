#ifndef SETACOTADO_CPP
#define SETACOTADO_CPP
#include "SetAcotado.h"

template <class T>
SetAcotado<T>::SetAcotado(nat tamanio,Comparador<T> comp)
{
	_set = Array<T>(tamanio, nullptr);
	_comp = comp;
	_tope = 0;
}

template <class T>
void SetAcotado<T>::Insertar(const T& x)
{
	_set[_tope] = x;
	_tope++;
}

template <class T>
bool SetAcotado<T>::EsVacio() const
{
	return _tope == 0;
}

template <class T>
bool SetAcotado<T>::EsLleno() const
{
	return _tope == (_set.Largo - 1);
}

template <class T>
nat SetAcotado<T>::Tamanio() const
{
	return _tope + 1;
}

template <class T>
bool SetAcotado<T>::Pertenece(const T& x) const
{
	bool pertenece = false;
	int i = 0;
	
	while (!pertenece && i < _tope)
	{
		if (_comp.SonIguales(_set[i], x))
			pertenece = true;
		i++;
	}
	return pertenece;
}

template <class T>
Puntero<Set<T>> SetAcotado<T>::Union(Puntero<Set<T>> A) const
{
	//Idea:
	//Cargo el Set nuevo con todos los datos que estan en A
	//Despues pregunto por cada uno de los datos en este si esta o no
	
	Puntero<Set<T>> newSet = new SetAcotado(this->Tamanio(), _comp);
	Iterador<T> iterA = A->ObtenerIterador();

	iterA.Reiniciar();
	while (iterA.HayElemento())
	{
		newSet->Insertar(iterA.ElementoActual());
	}
	
	for (int i = 0; _tope; i++)
	{
		if (!newSet->Pertenece(_set[i]))
			newSet->Insertar(_set[i]);
	}
	return newSet;
}

template <class T>
Puntero<Set<T>> SetAcotado<T>::Interseccion(Puntero<Set<T>> A) const
{
	//Idea:
	//Creo un nuevo set vacio y me traigo el iterador de A
	//me muevo con ese iterador y pregunto si el elementoActual esta en this
	//Si esta -> lo agrego
	Puntero<Set<T>> newSet = new SetAcotado(this->Tamanio(), _comp);
	Iterador<T> iterA = A->ObtenerIterador();

	while (iterA.HayElemento())
	{
		T elem = iterA.ElementoActual();
		if (this->Pertenece(elem))
		{
			newSet->Insertar(elem);
		}
	}
	return newSet;
}

template <class T>
Puntero<Set<T>> SetAcotado<T>::Diferencia(Puntero<Set<T>> A) const
{
	//Todo lo que esta en this->_set y no esta en A
	Puntero<Set<T>> newSet = new SetAcotado(this->Tamanio(), _comp);

	for (int i = 0; i < _tope; i++)
	{
		if (!A->Pertenece(_set[i]))
			newSet->Insertar(_set[i]);
	}
	return newSet;
}

template <class T>
Iterador<T> SetAcotado<T>::ObtenerIterador() const
{
	return _set.ObtenerIterador();
}
#endif
