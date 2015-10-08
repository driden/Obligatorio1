#pragma once
#include "Lista.h"
#include "ListaIteracion.h";

template<class T>
class ListaEnlazada : public Lista<T>
{
	nat cantElementos;
	Puntero<NodoLista<T>> _lista;
	Puntero<NodoLista<T>> _inicio;
	Puntero<Comparador<T>> _comp;
	Iterador<T> _iter;

	
	public:

	ListaEnlazada(const Puntero<Comparador<T>> comp);

	void Insertar(const T &x) override;

	const nat Largo() const override;

	void Eliminar(const T &x) override;

	bool Existe(const T &x) override;

	Puntero<NodoLista<T>> Recuperar(const T &x) override;

	Iterador<T> ObtenerIterador() const override;

};



