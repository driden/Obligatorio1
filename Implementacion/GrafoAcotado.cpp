#ifndef GRAFOACOTADO_CPP
#define GRAFOACOTADO_CPP
#include "GrafoAcotado.h"
#include "ColaDinamica.h"
#include "ColaPrioridadAcotada.h"

template <class T>
GrafoAcotado<T>::GrafoAcotado(Puntero<Set<T>> &vertices, Comparador<T> comp)
{
	_comparador = comp;

	nat size = vertices->Tamanio();
	_vertices = Array<T>(size);

	//guardo los vertices en un array para que sea mas facil acceder a ellos
	Iterador<T> iter = vertices->ObtenerIterador();
	iter.Reiniciar();
	for (nat i = 0; i < size; i++)
	{
		_vertices[i] = iter.ElementoActual();
		iter.Avanzar();
	}

	_matrizAdyacencia = Array<Array<nat>>(size);
	//inicializo matriz en 0 (no hay aristas)
	for (nat x = 0; x < size; x++)
		_matrizAdyacencia[x] = Array<nat>(size, 0);
}

template <class T>
bool GrafoAcotado<T>::InsertarArista(T& origen, T& destino, nat peso)
{
	bool insertada = false;

	nat filaOrigen = IndiceElemento(origen), colDestino = IndiceElemento(destino);

	if (_matrizAdyacencia[filaOrigen][colDestino] == 0)
	{
		_matrizAdyacencia[filaOrigen][colDestino] = peso;
		insertada = true;
	}

	return insertada;
}

template <class T>
nat GrafoAcotado<T>::AdyacenteConMenorCosto(nat previo, Array<bool> conocido, Array<nat> costo, Array<int> anterior, Puntero<ColaPrioridad<nat>> pq)
{
	nat menorCosto = INT_MAX;
	nat menorPosicion = INT_MAX;

	for (nat i = 0; i < _vertices.ObtenerLargo(); i++)
	{
		//salteo los ciclos
		if (previo == i)
			continue;

		//si hay arista
		nat pesoArista = _matrizAdyacencia[previo][i];
		//solo adyacentes tienen peso > 0
		if (pesoArista > 0)
		{
			costo[i] = costo[previo] + pesoArista;
			anterior[i] = previo;
			//busco el vertice de menor costo
			if (!conocido[i])
			{			
				pq->Insertar(i, costo[i]);
			}
			else if (conocido[i] && (pesoArista + costo[previo]) < menorCosto)
			{				
				menorCosto = costo[i];
				menorPosicion = i;
				//borro el vertice i de la cola y 
				//lo vuelvo a ingresar con prioridad
				pq->ActualizarPrioridad(i, menorCosto);
			}
		}
	}
	if (menorPosicion != INT_MAX)
		conocido[menorPosicion] = true;
	return menorPosicion;
}

template <class T>
void GrafoAcotado<T>::ImprimirCaminoMasCorto(nat v_origen, nat v_destino, Array<int> anterior)
{
	if (v_origen != v_destino)
		ImprimirCaminoMasCorto(v_origen, anterior[v_destino], anterior);
	cout << v_destino << " ";
}

template <class T>
bool GrafoAcotado<T>::HayCamino(nat v_origen, nat v_destino, Array<int> anterior)
{
	bool hay = true;
	if (v_origen != v_destino)
		hay = HayCamino(v_origen, anterior[v_destino], anterior) && hay;
	return hay;
}

template <class T>
bool GrafoAcotado<T>::CaminoMasCorto(T& origen, T& destino)
{
	nat vOrigen = IndiceElemento(origen),
		vDestino = IndiceElemento(destino),
		ady = 0;

	//Estructura
	Array<bool> conocido = Array<bool>(_vertices.Largo, false);
	Array<nat> costo = Array<nat>(_vertices.Largo, INT_MAX);
	Array<int> anterior = Array<int>(_vertices.Largo, -1);


	Comparador<nat> comp = new ComparadorNat();
	Puntero<ColaPrioridad<nat>> pq = new ColaPrioridadAcotada<nat>(_vertices.Largo);

	//vertice, peso
	pq->Insertar(vOrigen, 0);
	//arranco con el elemento que me interesa y esta en el origen
	conocido[vOrigen] = true;
	costo[vOrigen] = 0;

	nat verticeActual;
	while (!pq->EstaVacia())
	{
		verticeActual = pq->BorrarMin();
		conocido[verticeActual] = true;
		AdyacenteConMenorCosto(verticeActual, conocido, costo, anterior, pq);

	}
	if (HayCamino(vOrigen, vDestino, anterior))
	{
		ImprimirCaminoMasCorto(vOrigen, vDestino, anterior);
		return true;
	}
	else
	{
		return false;
	}

}

template <class T>
bool GrafoAcotado<T>::SubgrafoRecubridorCostoMinimo()
{
	return false;
}

template <class T>
T GrafoAcotado<T>::VerticeEnIndice(const nat i)
{
	return _vertices[i];
}

template <class T>
nat GrafoAcotado<T>::IndiceElemento(const T& elem)
{
	nat i = 0;

	while (_comparador.SonDistintos(_vertices[i], elem))	i++;

	return i;
}
#endif
