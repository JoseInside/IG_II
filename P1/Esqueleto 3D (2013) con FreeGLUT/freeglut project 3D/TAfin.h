#pragma once
#include "PV3D.h"

class TAfin
{

public:
	TAfin();
	~TAfin();

	void traslada(PV3D* v);
	void postmultiplica(GLfloat* m1);
	void rota(PV3D* v, GLdouble angulo);
	//void colorea(PV3D* color);
	PV3D getPos() { return PV3D(m[12], m[13], m[14], 0); };
	GLfloat *getM() { return m; }

protected:
	GLfloat *m;
};

