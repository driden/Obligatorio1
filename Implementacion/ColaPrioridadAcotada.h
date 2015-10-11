#ifndef COLAPRIORIDADACOTADA_H
#define COLAPRIORIDADACOTADA_H

#include "ColaPrioridad.h"
#include "Array.h"
#include "NodoCP.h"

template<class T>
class ColaPrioridadAcotada : public ColaPrioridad<T>
{
	private:
	Array<NodoCP<T>> _pqueue;
	nat _tope;
	
	public:
	~ColaPrioridadAcotada() {}

	ColaPrioridadAcotada<T>(nat max);

	void Insertar(const T &x, const nat p) override;

	Puntero<T> BorrarMin() override;

	nat Tamanio() override;

	bool EstaVacia() override;
};

#endif
#include "ColaPrioridadAcotada.cpp"
