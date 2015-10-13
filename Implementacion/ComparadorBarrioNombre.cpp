#ifndef COMPARADORBARRIONOMBRE_CPP
#define COMPARADORBARRIONOMBRE_CPP
#include "ComparadorBarrioNombre.h"
#include "ComparadorCadena.h"

CompRetorno ComparadorBarrioNombre::Comparar(const Barrio& b1, const Barrio& b2) const {
	Comparador<Cadena> cmp = new ComparadorCadena();
	if (cmp.SonIguales ( b1.ObtenerNombreBarrio() , b2.ObtenerNombreBarrio()))
	{
		return IGUALES;
	}
	else if (cmp.EsMenor(b1.ObtenerNombreBarrio(), b2.ObtenerNombreBarrio()))
	{
		return MENOR;
	}
	else if (cmp.SonDistintos(b1.ObtenerNombreBarrio(), b2.ObtenerNombreBarrio()))
	{
		return DISTINTOS;
	}
	else
	{
		return MAYOR;

	}
}
#endif 