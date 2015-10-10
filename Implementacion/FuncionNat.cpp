#ifndef FUNCIONCLIENTECI_CPP
#define FUNCIONCLIENTECI_CPP
#include "FuncionNat.h"

FuncionNat::FuncionNat(const nat& numeroPrimo)
{
	_primo = numeroPrimo;
}

nat FuncionNat::CodigoDeHash(const nat &num) const
{
	return num % _primo;
}

#endif