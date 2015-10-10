#ifndef HASHIMP_H
#define HASHIMP_H
#include "TablaHash.h"
#include "Array.h"
#include "Tupla.h"
#include "AVL.h"
#include "FuncionHash.h"

template <class Clave, class Valor>
class HashImp
{
private:
	//HASH ABIERTO
	Array<Tupla<Clave, AVL<Valor>>> _hash;
	FuncionHash<nat> _funcionHash;
public:
	HashImp<Clave, Valor>(int const MAX_NUMBER);
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
#endif
#include "HashImp.cpp"