#ifndef FUNCIONIMP_H
#define FUNCIONIMP_H
#include "HashImp.h"
#include "Cliente.h"


class FuncionClienteCI : FuncionHash<Cliente>
{
public:
	FuncionClienteCI(const nat &numeroPrimo);
	nat CodigoDeHash(const Cliente &cliente) const;
};
#endif
#include "FuncionImp.cpp"

