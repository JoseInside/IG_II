#pragma once
#include "ObjetoCompuesto.h"
#include "ObjetoCuadrico.h"
#include "Esfera.h"
#include "Cilindro.h"

class Arbol: public ObjetoCompuesto
{
public:
	enum tipo { ABETO, ROBLE, PINO, ALAMO };

	Arbol(tipo t, PV3D* v, GLfloat h, GLfloat tam);
	~Arbol();

protected:
	tipo _t;
	GLfloat _h, _tam;
	void creaArbol(PV3D v);
};

