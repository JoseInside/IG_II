#include "Esfera.h"


Esfera::Esfera(GLfloat r, GLfloat sli, GLfloat sta) : ObjetoCuadrico()
{
	_r = r;
	_sli = sli;
	_sta = sta;
}


Esfera::~Esfera()
{
}

void Esfera::dibuja(){

	glPushMatrix();
	glMultMatrixf(this->matriz->getM());
	glColor3f(this->color->getX(), this->color->getY(), this->color->getZ());
	gluSphere(obj, _r, _sli, _sta);
	glPopMatrix();
}
