#pragma once

#include "Iteracion.h"
#include "NodoLista.h"
template<class T>
class ListaIteracion<T> : public Iteracion<T>
{
private:
	Puntero<NodoLista<T>> _lista;
	Puntero<Comparador<T>> _comp;
public:

	ListaIteracion<T>(Puntero<NodoLista<T>> nodo, Puntero<Comparador<T>> comp);

	~ListaIteracion<T>();

	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

	Puntero<Iteracion<T>> Clonar() const override
	{ return nullptr; }
};