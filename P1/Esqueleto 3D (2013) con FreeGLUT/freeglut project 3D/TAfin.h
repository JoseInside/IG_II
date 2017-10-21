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
	GLfloat *getM() { return m; }

protected:
	GLfloat *m;
};

