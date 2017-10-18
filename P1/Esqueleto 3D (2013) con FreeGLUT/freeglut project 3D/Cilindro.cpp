#include "Cilindro.h"


Cilindro::Cilindro(GLUquadric* c, GLfloat rtop, GLfloat rbase, GLfloat h)
{
	_c = c;
	_rtop = rtop;
	_rbase = rbase;
	_h = h;
}


Cilindro::~Cilindro()
{
}
void Cilindro::dibuja(){

	gluCylinder(_c, _rtop, _rbase, _h, 30, 30);


}
