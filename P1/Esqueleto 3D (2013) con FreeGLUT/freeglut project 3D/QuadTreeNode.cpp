#include "QuadTreeNode.h"


QuadTreeNode::QuadTreeNode(int x, int z, GLfloat size)
{
	_x = x;
	_z = z;
	s = size;
}


QuadTreeNode::~QuadTreeNode()
{
}

void QuadTreeNode::build(){
	
	if (this->numberAsteroidsIntersected() <= 1)
		this->addIntersectingAsteroidsToList();
	else {
		SWChild = new QuadTreeNode(SWCornerX, SWCornerZ, size / 2.0);
		NWChild = new QuadTreeNode(SWCornerX, SWCornerZ - size / 2.0,
			size / 2.0);
		NEChild = new QuadTreeNode(SWCornerX + size / 2.0, SWCornerZ - size / 2.0, size / 2.0);
		SEChild = new QuadTreeNode(SWCornerX + size / 2.0, SWCornerZ,
			size / 2.0);
		SWChild->build();
		NWChild->build();
		NEChild->build();
		SEChild->build();
	}
}

void QuadTreeNode::draw(int x1, int z1, int x2, int z2, int x3, int z3, int x4, int z4){
	
	if (checkQuadrilateralsIntersection()) {
		//Se chequea si el cuadrado del nodo interseca el frustum; si no, no se hace nada
		if (SWChild == NULL) { // El nodo es hoja
			std::list<Arbol>::iterator treeListIterator;
			treeListIterator = treeList.begin();

			while (treeListIterator != treeList.end()) {
				treeListIterator->dibuja();
				treeListIterator++;
			}
		}
		else {
			SWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NWChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			NEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
			SEChild->draw(x1, z1, x2, z2, x3, z3, x4, z4);
		}
	}
}