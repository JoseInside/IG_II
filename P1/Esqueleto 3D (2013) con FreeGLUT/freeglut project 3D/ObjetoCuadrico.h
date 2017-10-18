#pragma once
#include "Objeto3D.h"
class ObjetoCuadrico: public Objeto3D
{
protected:
	GLUquadric* _o;
public:
	ObjetoCuadrico();
	virtual~ObjetoCuadrico();
};

