#include "Arbol.h"


Arbol::Arbol(tipo t, PV3D* v, GLfloat h, GLfloat tam) : ObjetoCompuesto()
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

	//PV3D v(0, 0, 0, 0);
	PV3D rot(1, 0, 0, 0);
	//color = new PV3D(1.0f, 0.0f, 1.0f, 0);									
	
	this->introduceObjeto(new Cilindro(0.45f, 0.35f, _h, 30, 30));	//TRONCO	//h = 4.0f
	hijos[0]->setColor(0.545f, 0.271f, 0.075f);							//COLOR: MARRÓN
	hijos[0]->matriz->traslada(&v);
	hijos[0]->matriz->rota(&rot, -90);
	switch (_t) {
	case ABETO:
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, _tam, 30, 30));	//UN CONO	//tam = 3.8f
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(v.getX(), 7, v.getZ());
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	case ROBLE:
		this->introduceObjeto(new Esfera(_tam, 30, 30));				//UNA ESFERA	//tam = 1.5f
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(v.getX(), 5, v.getZ());
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	case PINO:
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, _tam, 30, 30));	//DOS CONOS
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, _tam, 30, 30));
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[2]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(v.getX(), 7, v.getZ());
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		v.setPoints(v.getX(), 8, v.getZ());
		hijos[2]->matriz->traslada(&v);
		hijos[2]->matriz->rota(&rot, 90);
		break;
	case ALAMO:
		this->introduceObjeto(new Esfera(_tam, 30, 30));				//DOS ESFERAS	//Tam = 1.5f, 1.2f
		this->introduceObjeto(new Esfera(_tam - 0.5, 30, 30));
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[2]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(v.getX() - 0.5, 5, v.getZ() + 0.5);
		//v.setPoints(-0.5, 5, 0.5);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		v.setPoints(v.getX() + 0.5, 5, v.getZ() - 0.5);
		//v.setPoints(0.5, 5, -0.5);
		hijos[2]->matriz->traslada(&v);
		hijos[2]->matriz->rota(&rot, 90);
		break;

	}

	
}