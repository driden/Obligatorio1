#pragma once
#include "ComparadorCadena.h"

CompRetorno ComparadorCadena::Comparar(const Cadena& t1, const Cadena& t2) const
{
	CompRetorno res;
	Cadena c1 = t1.Trim();
	Cadena c2 = t2.Trim();

	if (c1 == c2)
		res = IGUALES;
	else if (c1 < c2)
		res = MENOR;
	else if (c1 > c2)
		res = MAYOR;
	else
		res = DISTINTOS;
	return res;
}
