#pragma once
#include "ObjetoCuadrico.h"
class DiscoParcial: public ObjetoCuadrico
{
private:
	GLfloat _iR, _oR, _stA, _swA;
	GLUquadric* _pD;
public:
	DiscoParcial(GLUquadric* pD, GLfloat iR, GLfloat oR, GLfloat stA, GLfloat swA);
	~DiscoParcial();

	void dibuja();
};

