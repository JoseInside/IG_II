#include "Disco.h"


Disco::Disco(GLfloat iR, GLfloat oR, GLfloat sli, GLfloat sta)
{
	_iR = iR;
	_oR = oR;
	_sli = sli;
	_sta = sta;
}


Disco::~Disco()
{
}
void Disco::dibuja(){

	gluDisk(obj, _iR, _oR, _sli, _sta);
}
