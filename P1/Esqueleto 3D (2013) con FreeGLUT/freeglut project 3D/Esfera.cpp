#include "Esfera.h"


Esfera::Esfera(GLUquadric* e, GLfloat r)
{
	_r = r;
	_e = e;
}


Esfera::~Esfera()
{
}
void Esfera::dibuja(){

	gluSphere(_e, _r, 30, 30);

}
