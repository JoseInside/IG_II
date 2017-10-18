#pragma once
#include "Objeto3D.h"
class Malla: public Objeto3D
{
protected:

	int numVertices;
	PV3D** vertice;
	int numNormales; //=numCaras, frecuentemente
	PV3D** normal;
	int numCaras;
	

	PV3D* vertActual;
	PV3D* vertSiguiente;
public:
	Malla(int nV, int nN, int nC, PV3D** v, PV3D** n);
	Malla() {};
	~Malla();

	virtual void dibuja();

	int getNumeroVertices() { return numVertices; }
	int getNumeroNormales() { return numNormales; }
	

	bool line = false;


};
