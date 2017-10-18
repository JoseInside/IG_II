#pragma once
#include "ObjetoCuadrico.h"
class Disco: public ObjetoCuadrico
{
private:
	GLfloat _iR, _oR;
	GLUquadric* _d;
public:
	Disco(GLUquadric* d, GLfloat iR, GLfloat oR);
	~Disco();

	void dibuja();
};

