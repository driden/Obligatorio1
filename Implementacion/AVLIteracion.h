#ifndef AVLITERACION_H
#define AVLITERACION_H

#include "Iteracion.h"
#include "NodoAVL.h"
#include "AVLImp.h"

template<class T>
class AVLIteracion : public Iteracion<T>
{
private:
	Puntero<NodoAVL<T>> _root;
	Puntero<NodoAVL<T>> _actual;

public:
	AVLIteracion(const Puntero<NodoAVL<T>> tree)
	{
		_root = tree;
		_actual = tree;
	}
	~AVLIteracion(){}

	bool HayElemento() const override;
	bool HayElemento(Puntero<NodoAVL<T>> tree) const;

	const T& ElementoActual() const override;	
	void Avanzar() override; 
	void Avanzar(Puntero<NodoAVL<T>>& tree) ;
	
	void Reiniciar() override;	
};
#endif

#include "AVLIteracion.cpp"
