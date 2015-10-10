#ifndef FUNCIONNAT_H
#define FUNCIONNAT_H
#include "FuncionHash.h"

class FuncionNat : FuncionHash<nat>
{
private:
	nat _primo;
public:
	FuncionNat(const nat &numeroPrimo);
	nat CodigoDeHash(const nat &num) const override;
};
#endif


