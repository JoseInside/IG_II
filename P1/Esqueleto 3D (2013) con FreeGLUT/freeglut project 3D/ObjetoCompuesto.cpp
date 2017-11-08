#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	hijos = new Objeto3D*[1000000];
	numHijos = 0;
}


ObjetoCompuesto::~ObjetoCompuesto()
{
	/*for (int i = 0; i < numHijos; ++i)
		delete hijos[i];*/

}

void ObjetoCompuesto::introduceObjeto(Objeto3D* obj) {
	hijos[numHijos] = obj;
	numHijos++;
}

void ObjetoCompuesto::dibuja() {
	
	if (this->isActive()) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(this->matriz->getM());
		for (int i = 0; i < numHijos; i++)
			hijos[i]->dibuja();
		glPopMatrix();
	}
}
