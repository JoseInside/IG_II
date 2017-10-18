#include "Disco.h"


Disco::Disco(GLUquadric* d, GLfloat iR, GLfloat oR)
{
	_d = d;
	_iR = iR;
	_oR = oR;
}


Disco::~Disco()
{
}
void Disco::dibuja(){

	gluDisk(_d, _iR, _oR, 30, 30);
}
