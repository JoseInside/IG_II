#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	hijos = new Objeto3D*[1000000];
	numHijos = 0;
}


ObjetoCompuesto::~ObjetoCompuesto()
{
}

void ObjetoCompuesto::introduceObjeto(Objeto3D* obj) {
	hijos[numHijos] = obj;
	numHijos++;
}
void ObjetoCompuesto::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->matriz->getM);
	for (int i = 0; i<numHijos; i++)
		hijos[i]->dibuja();
	glPopMatrix();
}
