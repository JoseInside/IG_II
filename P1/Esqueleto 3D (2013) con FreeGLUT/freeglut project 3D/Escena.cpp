#include "Escena.h"
#include "Coche.h"
#include <time.h>
#include <iostream>
#include "Arbol.h"
#include <math.h>

Escena::Escena() : ObjetoCompuesto()
{
	coche = new Coche();
	//bosque = new Bosque();
	collision = false;
	gameOver = false;
	numArboles = 0;
	creaEscena();

}


Escena::~Escena()
{
}

void Escena::creaEscena() {
	PV3D* v = new PV3D( 0, 0, 0, 0 );
	this->introduceObjeto(coche);
	this->hijos[0]->matriz->traslada(v);
	creaBosque();
}

void Escena::creaBosque() {
	
	srand(time(0));

	//FÓRMULA MÁXIMO Y MÍNIMO:
	///rand()%(max-min + 1) + min;

	for (int i = 1; i <= 4; ++i) {
		int randX = rand() % 21 - 10;	// rango -10, 10
		int randZ = rand() % 21 - 10;	// rango -10, 10
		PV3D* newPos = new PV3D(randX, 0, randZ, 0);

		//bool encontrado = false;
		int cont = 0;

		//probabilidad 0.25 type arbol
		int prob = rand() % 4 + 1;
		Arbol::tipo tipo;
		GLfloat _h, _tam;
		_h = rand() % 3 + 3;	//ALTURA DEL TRONCO (4 - 3)
								//_tam = rand() % 4 + 1;	//TAMAÑO DE LA COPA 
		switch (prob) {
		case 1:
			tipo = Arbol::ABETO;
			_tam = rand() % 3 + 2;	//TAMAÑO DE LA COPA (CILINDRO) (4 - 2)
			break;
		case 2:
			tipo = Arbol::ROBLE;
			_tam = rand() % 2 + 1;	//TAMAÑO DE LA COPA (ESFERA) (2 - 1)
			break;
		case 3:
			tipo = Arbol::PINO;
			_tam = rand() % 3 + 2;	//TAMAÑO DE LA COPA (CILINDRO) (4 - 2)
			break;
		case 4:
			tipo = Arbol::ALAMO;
			_tam = rand() % 2 + 1;	//TAMAÑO DE LA COPA (ESFERA) (2 - 1)
			break;
		}

		this->introduceObjeto(new Arbol(tipo, newPos, _h, _tam));
		this->hijos[i]->matriz->traslada(newPos);
		numArboles++;
	}

	for (int j = 0; j < numHijos; ++j)
		std::cout << this->hijos[j]->matriz->getPos().getX() << " " << this->hijos[j]->matriz->getPos().getZ() << "\n";
}

void Escena::movCoche(movType type) {
	
	if (!gameOver) {
		
		PV3D v(1, 0, 0, 0);

		switch (type) {
		case FOWARD:
			hijos[0]->matriz->traslada(&v);
			break;
		case BACKWARDS:
			v.setPoints(-1, 0, 0);
			hijos[0]->matriz->traslada(&v);
			break;
		case LEFT:
			v.setPoints(0, 1, 0);
			hijos[0]->matriz->rota(&v, angRot);
			break;
		case RIGHT:
			v.setPoints(0, 1, 0);
			hijos[0]->matriz->rota(&v, -angRot);
			break;
		}

		controlJuego();
	}
}

void Escena::controlJuego() {
	
	int cont = 1;
	
	if (numArboles == 0) {
		gameOver = true;
	}
	else {

		//COMPARAR POSICIÓN DEL COCHE CON CADA ÁRBOL CALCULANDO SU DISTANCIA
		//DISTANCIA = sqrt((x1 - y1)*(x1 - y1 ) + (x2 - y2)*(x2 - y2));
		//pow(x1 - x2, 2) + pow(y1 - y2, 2)
		collision = false;

		while (cont < numHijos && !collision) {
			if (hijos[cont]->isActive()) {
				if (sqrt((pow(hijos[cont]->matriz->getPos().getX() - hijos[0]->matriz->getPos().getX(), 2) +
					pow(hijos[cont]->matriz->getPos().getZ() - hijos[0]->matriz->getPos().getZ(), 2))) <= 1) {
					
					collision = true;
					this->hijos[cont]->changeActive();
					--numArboles;
					cont = 0;
					std::cout << "Collision! \n";
				}
			}
			//std::cout << numHijos << "\n";
			cont++;
		}
	}
}
Objeto3D* Escena::getCoche() {

	return hijos[0];
}