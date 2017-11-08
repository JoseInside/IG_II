#pragma once
#include "QuadTreeNode.h"

class QuadTree
{
public:
	QuadTree();
	~QuadTree();

	QuadTreeNode *header;


	void initialize(float x, float z, float s) {
		header = new QuadTreeNode(x, z, s);
		header->build();
	}

	void dibuja(int x1, int z1, int x2, int z2, int x3, int z3, int x4, int z4) {
		header->draw(x1, z1, x2, z2, x3, z3, x4, z4);
	}
};

