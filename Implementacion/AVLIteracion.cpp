#ifndef AVLITERACION_CPP
#define AVLITERACION_CPP

#include "AVLIteracion.h"

template <class T>
bool AVLIteracion<T>::HayElemento() const
{
	return HayElemento(_actual);
}

template <class T>
bool AVLIteracion<T>::HayElemento(Puntero<NodoAVL<T>> tree) const
{
	bool hay = false;
	if (tree != nullptr && tree->GetIzq() != nullptr)
	{
		hay = true;
	}
	if (tree != nullptr && tree->GetDer() != nullptr)
	{
		hay = true;
	}
	if (tree != nullptr)
		hay = true;
	return hay;
}

template <class T>
const T& AVLIteracion<T>::ElementoActual() const
{
	return _actual->GetDato();
}

template <class T>
void AVLIteracion<T>::Avanzar()
{
	Avanzar(_actual);
}

template <class T>
void AVLIteracion<T>::Avanzar(Puntero<NodoAVL<T>> &tree)
{
	if (tree != nullptr && tree->GetIzq() != nullptr)
	{
		tree = tree->GetIzq();
	}
	if (tree != nullptr && tree->GetDer() != nullptr)
	{
		tree = tree->GetDer();
	}
}

template <class T>
void AVLIteracion<T>::Reiniciar()
{
	_actual = _root;
}

#endif
