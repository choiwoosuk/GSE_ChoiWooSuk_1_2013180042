#include "stdafx.h"
#include "Object.h"

Object::Object()
{

}

Object::Object(float x1, float y1, float z1, float size1, float r1, float g1, float b1, float a1, float velo1, float vecX1, float vecY1)
{
	x = x1;
	y = y1;
	z = z1;
	size = size1;
	r = r1;
	g = g1;
	b = b1;
	a = a1;

	velo = velo1;
	vecX = vecX1;
	vecY = vecY1;
}

void Object::update()
{
	x = x + change*vecX*velo;
	//x = x + 1;
}


Object::~Object()
{
}
