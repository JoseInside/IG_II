#pragma once
#include "ObjetoCompuesto.h"
#include "Arbol.h"


class CopaDoble : public ObjetoCompuesto
{
public:
	CopaDoble(Arbol::tipo t, GLfloat tam, PV3D v, PV3D rot, GLfloat _h);
	virtual ~CopaDoble();
};

