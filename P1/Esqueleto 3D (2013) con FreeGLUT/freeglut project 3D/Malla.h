#pragma once
#include "Objeto3D.h"
#include "Cara.h"

class Malla: public Objeto3D
{

public:
	Malla(int nV, int nN, int nC, PV3D** v, PV3D** n, Cara** c);
	Malla() {};
	~Malla();

	virtual void dibuja();

	int getNumeroVertices() { return numVertices; }
	int getNumeroNormales() { return numNormales; }
	

	bool line = false;

protected:

	int numVertices;
	PV3D** vertice;
	int numNormales; //=numCaras, frecuentemente
	PV3D** normal;
	int numCaras;
	Cara** cara;

	PV3D* vertActual;
	PV3D* vertSiguiente;

};
