#include "DiscoParcial.h"


DiscoParcial::DiscoParcial(GLUquadric* pD, GLfloat iR, GLfloat oR, GLfloat stA, GLfloat swA)
{
	_pD = pD;
	_iR = iR;
	_oR = oR;
	_stA = stA;
	_swA = swA;
}


DiscoParcial::~DiscoParcial()
{
}
void DiscoParcial::dibuja(){

	gluPartialDisk(_pD, _iR, _oR, _stA, _swA, 30, 30);
	
}
