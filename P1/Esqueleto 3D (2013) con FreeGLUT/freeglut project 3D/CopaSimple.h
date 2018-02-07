#pragma once
#include "ObjetoCompuesto.h"
#include "Arbol.h"

class CopaSimple : public ObjetoCompuesto
{
public:
	CopaSimple(Arbol::tipo t, GLfloat tam, PV3D v, PV3D rot, GLfloat _h);
	virtual ~CopaSimple();
	
};

