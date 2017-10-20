#include "Cubo.h"


Cubo::Cubo(GLfloat tam)
{
	_tam = tam;
}


Cubo::~Cubo()
{
}
void Cubo::dibuja(){

	glutSolidCube(_tam);
	glutWireCube(_tam);

}