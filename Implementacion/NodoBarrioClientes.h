#ifndef adas
#define asda
#include <Puntero.h>
#include "Cliente.h"
#include "AVL.h"
#include "Barrio.h"
#include "AVLImp.h"

class NodoBarrioClientes
{
private:
	Barrio _barrio;
	Puntero<AVL<Cliente>> _clientes;



public:

	NodoBarrioClientes(Barrio barrio)
	{
		this->_barrio = barrio;
		Comparador<Cliente> comp = new Comparador<Cliente>();
		this->_clientes = new AVLImp<Cliente>(comp);
		
	}




};




#endif
