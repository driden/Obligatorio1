#ifndef COMPARADORBARRIONOMBRE_H
#define COMPARADORBARRIONOMBRE_H

#include "ComparadorBarrioNombre.h"
#include "Barrio.h"

class ComparadorBarrioNombre : public Comparacion<Barrio> {
public:
	CompRetorno Comparar(const Barrio& b1, const Barrio& b2) const override;
};

#endif 
