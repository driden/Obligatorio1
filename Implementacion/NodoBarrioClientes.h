#ifndef NODOBARRIOCLIENTES_H
#define NODOBARRIOCLIENTES_H

#include "Puntero.h"
#include "Cliente.h"
#include "Barrio.h"
#include "AVLImp.h"

class NodoBarrioClientes {
private:
	Barrio _barrio;
	Puntero<AVL<Cliente>> _clientes;

public:
	//~NodoBarrioClientes(){}

	NodoBarrioClientes(){}
	NodoBarrioClientes(Barrio barrio);

	Puntero<AVL<Cliente>> GetClientes();

	Barrio GetBarrio() const;
};

#endif