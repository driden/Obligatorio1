#ifndef HASHIMP_H
#define HASHIMP_H
#include "TablaHash.h"
#include "Array.h"
#include "Tupla.h"
#include "Lista.h"
#include "FuncionHash.h"
#include "Utilidades.h"
#include "Comparador.h"

template <class Clave, class Valor>
class HashImp : public TablaHash<Clave, Valor>
{
private:
	//HASH ABIERTO
	Array<Puntero<Lista<Valor>>> _hash;
	Puntero<FuncionHash<Clave>> _funcionHash;
	nat _largo;	
public:
	~HashImp(){}
	HashImp<Clave, Valor>(int const MAX_NUMBER, Puntero<FuncionHash<Clave>> funcion, Comparador<Valor> comp);
	/* CONSTRUCTORAS */
	void Agregar(const Clave& c, const Valor& v) override;
	void Borrar(const Clave& c) override;
	/* PREDICADOS */
	bool EstaVacia() const override;
	bool EstaLlena() const override;
	bool Pertenece(const Clave& c) const override;
	/* SELECTORAS */
	bool Obtener(const Clave& c, Valor& v) const override;
	nat Largo() const override;
	
};
#endif
#include "HashImp.cpp"