#include "CopaDoble.h"
#include "Cilindro.h"
#include "Esfera.h"
#include <iostream>

CopaDoble::CopaDoble(Arbol::tipo t, GLfloat tam, PV3D v, PV3D rot, GLfloat _h) : ObjetoCompuesto()
{
	switch (t) {

	case Arbol::tipo::PINO:
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, tam, 30, 30));	//DOS CONOS
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, tam, 30, 30));
		hijos[0]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(0, _h + 2, 0);
		hijos[0]->matriz->traslada(&v);
		hijos[0]->matriz->rota(&rot, 90);
		v.setPoints(0, _h + 3, 0);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	case Arbol::tipo::ALAMO:
		this->introduceObjeto(new Esfera(tam, 30, 30));				
		this->introduceObjeto(new Esfera(tam - 0.5, 30, 30));
		hijos[0]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO

		v.setPoints(-0.5, _h, 0.5);
		hijos[0]->matriz->traslada(&v);
		hijos[0]->matriz->rota(&rot, 90);
		v.setPoints(0.5, _h, -0.5);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	default:
		std::cout << "ERROR TIPO" << std::endl;
	}
}


CopaDoble::~CopaDoble()
{
}
