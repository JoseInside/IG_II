#pragma once
#include "Arbol.h"
#include <iostream>
#include <list>

class QuadTreeNode
{
public:
	QuadTreeNode(int x, int z, GLfloat size);
	~QuadTreeNode();

	void build();
	void draw(int x1, int z1, int x2, int z2, int x3, int z3, int x4, int z4);

protected:

	int numberAsteroidsIntersected(){ return 0; };
	void addIntersectingAsteroidsToList(){};
	bool checkQuadrilateralsIntersection(){ return true; };

	int _x, _z;
	GLfloat s;	//Tamaño de la rejilla
	std::list<Arbol>treeList;
	QuadTreeNode *SWChild, *NWChild, *NEChild, *SEChild;

	int SWCornerX, SWCornerZ, size;
};

