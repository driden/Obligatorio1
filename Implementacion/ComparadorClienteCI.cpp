#ifndef COMPARADORCLIENTE_CPP
#define COMPARADORCLIENTE_CPP

#include "ComparadorClienteCI.h"
#include "ComparadorNat.h"

#endif
CompRetorno ComparadorClienteCI::Comparar(const Cliente& t1, const Cliente& t2) const
{
	Comparador<nat> compNat = new ComparadorNat();

	if (compNat.EsMayor(t1.ObtenerCiCliente(), t2.ObtenerCiCliente()))
		return MAYOR;

	if (compNat.EsMenor(t1.ObtenerCiCliente(), t2.ObtenerCiCliente()))
		return MENOR;

	if (compNat.SonIguales(t1.ObtenerCiCliente(), t2.ObtenerCiCliente()))
		return IGUALES;

	return DISTINTOS;
}