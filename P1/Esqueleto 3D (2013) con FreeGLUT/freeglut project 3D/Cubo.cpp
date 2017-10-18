#include "Cubo.h"


Cubo::Cubo(GLfloat a)
{
	_a = a;
}


Cubo::~Cubo()
{
}
void Cubo::dibuja(){

	glutSolidCube(_a);
	glutWireCube(_a);

}