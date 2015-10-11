#ifndef COLAPRIORIDADACOTADA_CPP
#define COLAPRIORIDADACOTADA_CPP
#include "ColaPrioridadAcotada.h"
#include "ComparadorNat.h"

template <class T>
ColaPrioridadAcotada<T>::ColaPrioridadAcotada(nat max)
{
	//la cubeta 0 NO SE USA!
	_pqueue = Array<Puntero<NodoCP<T>>>(max + 1);
	_comp = new ComparadorNat();
	_tope = 0;
}

template <class T>
void ColaPrioridadAcotada<T>::Insertar(const T& x, const nat p)
{
	int hole = ++_tope;
	while (hole > 1 && _comp.EsMayor((_pqueue[hole / 2])->GetPrioridad(), p))
	{
		_pqueue[hole] = _pqueue[hole / 2];
		hole /= 2;
	}
	_pqueue[hole] = new NodoCP<T>(x, p);
}

template <class T>
T ColaPrioridadAcotada<T>::BorrarMin()
{
	T min = (_pqueue[1])->GetElemento();
	_pqueue[1] = _pqueue[_tope];
	_tope = _tope - 1;
	//filtrado descendente
	nat hole = 1, hijoMenor,padre;
	bool salir = false;
	
	while ((hole*2) + 1 <=_tope)
	{
		//hijos
		hole *= 2;
		//menor de los hijos
		hijoMenor = hole;
		if (_comp.EsMenor((_pqueue[hole + 1])->GetPrioridad(), (_pqueue[hole])->GetPrioridad()))
			hijoMenor = hole + 1;
		
		padre = hijoMenor / 2;
		//swap con el padre
		_pqueue[0] = _pqueue[padre];
		_pqueue[padre] = _pqueue[hijoMenor];
		_pqueue[hijoMenor] = _pqueue[0];
		
		hole = hijoMenor;
	}
	return min;
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
	return (this == nullptr) || this->_tope == 0;
}

#endif