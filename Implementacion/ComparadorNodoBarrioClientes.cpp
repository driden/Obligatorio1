#ifndef COMPARADORNODOBARRIOCLIENTES_CPP
#define COMPARADORNODOBARRIOCLIENTES_CPP

#include "ComparadorBarrioNombre.h"
#include "ComparadorNodoBarrioClientes.h"

CompRetorno ComparadorNodoBarrioClientes::Comparar(const NodoBarrioClientes& t1, const NodoBarrioClientes& t2) const
{
	Comparador<Barrio> cmpBarrio = new ComparadorBarrioNombre();
	Barrio b1 = t1.GetBarrio();
	Barrio b2 = t2.GetBarrio();
	
	if (cmpBarrio.EsMayor(b1, b2))
		return MAYOR;

	if (cmpBarrio.EsMenor(b1, b2))
		return MENOR;
	if (cmpBarrio.SonIguales(b1, b2))
		return IGUALES;

	return DISTINTOS;
}
#endif
