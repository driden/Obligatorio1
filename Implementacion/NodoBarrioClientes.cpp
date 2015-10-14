#ifndef NODOBARRIOCLIENTES_CPP
#define NODOBARRIOCLIENTES_CPP
#include "NodoBarrioClientes.h"
#include "ComparadorClienteCI.h"


NodoBarrioClientes::NodoBarrioClientes(Barrio barrio)
{
	/*_barrio = barrio;
	Comparador<Cliente> comp = new ComparadorClienteCI();
	_clientes = new AVLImp<Cliente>(comp);*/
}

Puntero<AVL<Cliente>> NodoBarrioClientes::GetClientes()
{
	return _clientes;
}

Barrio NodoBarrioClientes::GetBarrio() const
{
	return _barrio;
}
#endif;