#include "CopaSimple.h"
#include "Cilindro.h"
#include "Esfera.h"
#include <iostream>

CopaSimple::CopaSimple(Arbol::tipo t, GLfloat tam, PV3D v, PV3D rot, GLfloat _h) : ObjetoCompuesto()
{
	switch (t) {
		
		case Arbol::tipo::ABETO:
			this->introduceObjeto(new Cilindro(0.0f, 1.2f, tam, 30, 30));
			hijos[0]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
			
			v.setPoints(0, _h + 2, 0);
			hijos[0]->matriz->traslada(&v);
			hijos[0]->matriz->rota(&rot, 90);
			break;
		case Arbol::tipo::ROBLE:
			this->introduceObjeto(new Esfera(tam, 30, 30));
			hijos[0]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
			
			v.setPoints(0, _h, 0);
			hijos[0]->matriz->traslada(&v);
			hijos[0]->matriz->rota(&rot, 90);
			break;
		default:
			std::cout << "ERROR TIPO" << std::endl;
	}
}

CopaSimple::~CopaSimple()
{
}