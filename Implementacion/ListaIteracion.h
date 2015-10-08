#pragma once

#include "Iteracion.h"
#include "NodoLista.h"

template<class T>
class ListaIteracion : Iteracion<T>
{
private:
	Puntero<NodoLista<T>> _lista;
	Puntero<NodoLista<T>> _inicio;
	
public:

	ListaIteracion<T>(Puntero<NodoLista<T>> nodo);

	~ListaIteracion<T>();

	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

	Puntero<Iteracion<T>> Clonar() const override;
	//AUX
	Puntero<NodoLista<T>> ClonarLista(const Puntero<NodoLista<T>> lista) const;

	/*Puntero<NodoLista<T>> GetLista() const;
	void SetInicioLista(const Puntero<NodoLista<T>> & l);*/


};