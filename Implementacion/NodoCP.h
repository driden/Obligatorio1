#ifndef NODOCP_H
#define NODOCP_H
typedef unsigned int nat;

template <class T>
class NodoCP
{
	private:
	// Menor prioridad = Mayor Urgencia
	T _element;
	nat _prioridad;

	public:
	~NodoCP(){}

	NodoCP(T e, nat p)
	{
		_element = e;
		_prioridad = p;
	}

	const T& GetElemento() const;
	const nat GetPrioridad() const;
	void SetElemento(const T &e);
	void SetPrioridad(const nat p);
};
#endif
#include "NodoCP.cpp"