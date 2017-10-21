#pragma once
#include "ObjetoCuadrico.h"
class Disco: public ObjetoCuadrico
{
private:
	GLfloat _iR, _oR, _sli, _sta;
public:
	Disco(GLfloat iR, GLfloat oR, GLfloat sli, GLfloat sta);
	~Disco();

	void dibuja();
};

