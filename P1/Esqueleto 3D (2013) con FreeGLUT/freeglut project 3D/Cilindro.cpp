#include "Cilindro.h"


Cilindro::Cilindro(GLfloat rtop, GLfloat rbase, GLfloat h, GLfloat sli, GLfloat sta)
{
	_rtop = rtop;
	_rbase = rbase;
	_h = h;
	_sli = sli;
	_sta = sta;
}


Cilindro::~Cilindro()
{
}
void Cilindro::dibuja(){

	gluCylinder(obj, _rtop, _rbase, _h, _sli, _sta);


}
