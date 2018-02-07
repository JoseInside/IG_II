#include "Arbol.h"
#include "CopaSimple.h"
#include "Esfera.h"
#include "Cilindro.h"
#include "CopaDoble.h"

Arbol::Arbol(tipo t, PV3D* v, GLfloat h, GLfloat tam) 
{
	_t = t;
	_h = h;
	_tam = tam;
	creaArbol(*v);
}


Arbol::~Arbol()
{
}


void Arbol::creaArbol(PV3D v) {

	PV3D rot(1, 0, 0, 0);

	//TRONCO	//h = 4.0f
	this->introduceObjeto(new Cilindro(0.45f, 0.35f, _h, 30, 30));		
	hijos[0]->setColor(0.545f, 0.271f, 0.075f);							//COLOR: MARRÓN
	//hijos[0]->matriz->traslada(&v);
	hijos[0]->matriz->rota(&rot, -90);

	switch (_t) {

		case ABETO:
			//UN CONO	//tam = 3.8f
			this->introduceObjeto(new CopaSimple(_t, _tam, v, rot, _h));
			break;
		case ROBLE:
			//UNA ESFERA	//tam = 1.5f
			this->introduceObjeto(new CopaSimple(_t, _tam, v, rot, _h));			
			break;
		case PINO:
			//DOS ESFERAS	//tam = 1.5f, 1.2f
			this->introduceObjeto(new CopaDoble(_t, _tam, v, rot, _h));
			break;
		case ALAMO:
			//DOS ESFERAS
			this->introduceObjeto(new CopaDoble(_t, _tam, v, rot, _h));
			break;
	}
	
}