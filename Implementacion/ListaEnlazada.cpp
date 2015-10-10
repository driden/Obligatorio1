#ifndef LISTAENLAZADA_CPP
#define LISTAENLAZADA_CPP

#include "ListaIteracion.h"
#include "ListaEnlazada.h"

template <class T>
void ListaEnlazada<T>::Insertar(const T& x)
{
	Puntero<NodoLista<T>> nuevo = new NodoLista<T>(x);
	if (_lista == nullptr)
	{
		_lista = nuevo;
	}
	else
	{
		Puntero<NodoLista<T>> aux = _lista;
		Puntero<NodoLista<T>> anterior = aux;
		while ( aux ->GetSiguiente() != nullptr)
		{
			anterior = aux;
			aux = aux->GetSiguiente();
		}
		anterior->SetSiguiente(nuevo);
	}
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
		//si es el primero
		if (_comp.SonIguales(x, _lista->GetDato()))
		{
			Puntero<NodoLista<T>> aBorrar = _lista;
			_lista = _lista->GetSiguiente();
			aBorrar = nullptr;
			//refresco iterador
			_iter = new ListaIteracion<T>(_lista);
		}
		else
		{
			Iterador<T> it = ObtenerIterador();
			Puntero<NodoLista<T>> aux = _lista;
			Puntero<NodoLista<T>> ant = _lista;

			while (_comp.SonDistintos(it.ElementoActual(), x))
			{
				ant = aux;
				aux = aux->GetSiguiente();
			}
			
			ant->SetSiguiente(aux->GetSiguiente());
			aux = nullptr;
		}
		this->cantElementos = cantElementos - 1;
	}
}

template <class T>
bool ListaEnlazada<T>::Existe(const T& x)
{
	bool existe = false;

	if (_lista != nullptr)
	{
		Puntero<NodoLista<T>> itera = _lista;

		while (itera != nullptr && _comp.SonDistintos(itera->GetDato(), x))
		{
			itera = itera->GetSiguiente();
		}

		if (itera != nullptr)
		{
			existe = true;
		}
		itera = nullptr;
	}
	return existe;
}

template <class T>
Puntero<NodoLista<T>> ListaEnlazada<T>::Recuperar(const T& x)
{
	Puntero<NodoLista<T>> nodo = nullptr;
	Puntero<NodoLista<T>> itera = _lista;

	if (Existe(x))
	{
		while (_comp.SonDistintos(itera->GetDato(), x))
		{
			itera = itera->GetSiguiente();
		}		
	}

	return itera;
}

template <class T>
Iterador<T> ListaEnlazada<T>::ObtenerIterador() const
{
	return new ListaIteracion<T>(_lista);	
}
#endif
