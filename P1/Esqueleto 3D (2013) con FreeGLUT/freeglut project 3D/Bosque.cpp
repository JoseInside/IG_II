#include "Bosque.h"
#include <time.h>

Bosque::Bosque() : ObjetoCompuesto()
{
	creaBosque();
	
}


Bosque::~Bosque()
{
}


void Bosque::creaBosque() {

	srand(time(0));
	
	//FÓRMULA MÁXIMO Y MÍNIMO:
	///rand()%(max-min + 1) + min;

	for (int i = 0; i < 4; ++i) {
		int randX = rand() % 21 - 10;	// rango -10, 10
		int randZ = rand() % 21 - 10;	// rango -10, 10
		PV3D* newPos = new PV3D(randX, 0, randZ, 0);

		//bool encontrado = false;
		int cont = 0;

		/*while (cont < numHijos) {
			if (hijos[cont]->matriz->getM() == newPos->matriz->getM()) { //FALTA ESTO
				//buscar rango de nuevo
				randX = rand() % 21 - 10;	// rango -10, 10
				randZ = rand() % 21 - 10;	// rango -10, 10
				newPos->setPoints(randX, 0, randZ);
				cont = 0;
			}
			else {
				cont++;
			}
		}*/

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
		//probabilidad 0.25 type arbol
		arbolGenerico = new Arbol(tipo, newPos, _h, _tam);
		this->introduceObjeto(arbolGenerico);
	}
}