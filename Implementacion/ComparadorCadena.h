#pragma once
#include "Comparador.h"
#include "Cadena.h"

class ComparadorCadena : public Comparacion<Cadena>
{
	public:
	CompRetorno Comparar(const Cadena& t1, const Cadena& t2) const override;
};