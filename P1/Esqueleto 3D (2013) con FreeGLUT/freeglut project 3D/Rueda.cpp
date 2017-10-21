#include "Rueda.h"
#include "Cilindro.h"
#include "Disco.h"


Rueda::Rueda() : ObjetoCompuesto()
{
	this->introduceObjeto(new Cilindro(0.5f, 0.5f, 0.4f, 30, 30));	
	this->introduceObjeto(new Disco(0.0f, 0.5f, 30, 30));		
	this->color = new PV3D(0, 0, 0, 0);
}


Rueda::~Rueda()
{
}
/*
void Rueda::dibuja() {
	
	glPushMatrix();
	glMultMatrixf(this->matriz->getM());
	//gluCylinder(obj, 0.5f, 0.5f, 0.5f, 30, 30);
	
	glPopMatrix();
}*/