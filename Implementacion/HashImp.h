#pragma once
#include "TablaHash.h"


template <class Clave, class Valor>
class HashImp
{
public:
	/* CONSTRUCTORAS */
	virtual void Agregar(const Clave& c, const Valor& v);
	virtual void Borrar(const Clave& c);
	/* PREDICADOS */
	virtual bool EstaVacia() const;
	virtual bool EstaLlena() const;
	virtual bool Pertenece(const Clave& c) const;
	/* SELECTORAS */
	virtual bool Obtener(const Clave& c, Valor& v) const;
	virtual nat Largo() const;
};
