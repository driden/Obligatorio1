#ifndef COMPARADORCLIENTECI_H
#define COMPARADORCLIENTECI_H

#include "Cliente.h"

class ComparadorClienteCI : public Comparacion<Cliente>
{
public:
	CompRetorno Comparar(const Cliente& t1, const Cliente& t2) const override;
};

#endif
