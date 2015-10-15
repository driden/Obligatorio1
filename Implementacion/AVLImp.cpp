#ifndef AVLIMP_CPP
#define AVLIMP_CPP

#include <algorithm> //max
#include <iomanip>   
#include "AVLImp.h"
#include "AVLIteracion.h"


using namespace std;

template <class T>
void AVLImp<T> ::Vacio() {
	_root = NULL;
}

template <class T>
void AVLImp<T>::Insertar(const T &x) {
	if (_root != NULL) {
		Insertar(x, _comparador, _root);
	}
	else {
		_root = new NodoAVL<T>();
		_root->SetDato(x);
		_root->SetIzq(NULL);
		_root->SetDer(NULL);
		_root->SetHeight(0);
	}
}

template<class T>
void AVLImp<T> ::Insertar(const T &x, const Comparador<T> &cmp, Puntero<NodoAVL<T>> &root)
{
	if (root == NULL)
	{
		root = new NodoAVL<T>();
		root->SetDato(x);
		root->SetIzq(NULL);
		root->SetDer(NULL);
		root->SetHeight(0);
	}
	else if (cmp.EsMenor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetIzq());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp.EsMenor(x, root->GetIzq()->GetDato()))
			{
				RotacionSimpleIzq(root);
			}
			else
			{
				RotacionDobleIzq(root);				
			}
		}
	}
	else if (cmp.EsMayor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetDer());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp.EsMenor(x, root->GetDer()->GetDato()))
			{
				RotacionSimpleDer(root);
			}
			else
			{
				RotacionDobleDer(root);
			}
		}
	}
	root->SetHeight(max(GetHeight(root->GetDer()), GetHeight(root->GetIzq())) + 1);
}

template<class T>
void AVLImp<T> ::RotacionSimpleIzq(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL) {
		Puntero<NodoAVL<T>>  k1 = root->GetIzq();
		if (k1 != NULL)
		{
			root->GetIzq() = k1->GetDer();
			k1->GetDer() = root;
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k1->SetHeight(max(GetHeight(k1->GetIzq()), GetHeight(k1->GetDer())) + 1);
			//faltaba terminar de enganchar el arbol!
			root = k1;

		}
	}
}

template<class T>
void AVLImp<T> ::RotacionSimpleDer(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL) {
		Puntero<NodoAVL<T>> k2 = root->GetDer();
		if (k2 != NULL) {
			root->GetDer() = k2->GetIzq();
			k2->GetIzq() = root;
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k2->SetHeight(max(GetHeight(k2->GetIzq()), GetHeight(k2->GetDer())) + 1);
			//faltaba terminar de enganchar el arbol!
			root = k2;
		}
	}
}

template<class T>
void AVLImp<T> ::RotacionDobleIzq(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleDer(root->GetIzq());
	RotacionSimpleIzq(root);
}

template<class T>
void AVLImp<T> ::RotacionDobleDer(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleIzq(root->GetDer());
	RotacionSimpleDer(root);
}
template<class T>
int AVLImp<T>::GetHeight(Puntero<NodoAVL<T>> nodo) const {
	return (nodo == NULL) ? -1 : nodo->GetHeight();
}

template <class T>
Comparador<T> AVLImp<T>::GetComparador() const {
	return _comparador;
}

template <class T>
nat AVLImp<T>::Contar()
{
	return Contar(_root);
}

template <class T>
nat AVLImp<T>::Contar(Puntero<NodoAVL<T>> tree)
{
	
	if (tree == nullptr)
	{
		return 0;
	} else
	{	
		return  1 + Contar(tree->GetDer()) + Contar(tree->GetIzq());
	}
}

template <class T>
T& AVLImp<T>::Recuperar(const T& x, const Puntero<NodoAVL<T>> tree)
{
	if (_comparador.EsMayor(x, tree->GetDato()))
	{
		return Recuperar(x, tree->GetDer());

	} else if (_comparador.EsMenor(x, tree->GetDato()))
	{
		return Recuperar(x, tree->GetIzq());
	} else
	{
		return tree->GetDato();
	}
}

template <class T>
Iterador<T> AVLImp<T>::ObtenerIterador() const
{
	return new AVLIteracion<T>(_root);
}

template <class T>
void AVLImp<T>::SetComparador(const Comparador<T> &cmp) {
	_comparador = cmp;
}
/**** Predicado ****/
// retorna true si el árbol es vacío
template<class T>
bool AVLImp<T>::EsVacio() const {
	return _root == NULL;
}

template<class T>
const T& AVLImp<T>::Raiz() const {
	return _root->GetDato();
}

template<class T>
bool AVLImp<T>::Existe(const T &x) const {
	return true;
}

template<class T>
void AVLImp<T>::Borrar(const T &x) {}

#endif // !AVLIMP_CPP