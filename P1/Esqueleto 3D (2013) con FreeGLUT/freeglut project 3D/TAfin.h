#pragma once
#include "PV3D.h"

class TAfin
{
private:
	GLfloat * m;
public:
	TAfin();
	~TAfin();

	void traslada(PV3D* v);
	void postmultiplica(GLfloat* m1);
	GLfloat getM() { return *m; }
};

