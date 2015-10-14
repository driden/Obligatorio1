#ifndef COMPARADORNODOBARRIOCLIENTES_H
#define COMPARADORNODOBARRIOCLIENTES_H

#include "ComparadorBarrioNombre.h"
#include "NodoBarrioClientes.h"

class ComparadorNodoBarrioClientes : public Comparacion<NodoBarrioClientes>
{
	CompRetorno Comparar(const NodoBarrioClientes& t1, const NodoBarrioClientes& t2) const override;
};
#endif
