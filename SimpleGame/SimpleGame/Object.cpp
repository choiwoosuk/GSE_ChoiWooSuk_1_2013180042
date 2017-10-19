#include "stdafx.h"
#include "Object.h"

<<<<<<< HEAD
Object::Object()
{

}

Object::Object(float x1, float y1, float z1, float size1, float r1, float g1, float b1, float a1, float velo1, float vecX1, float vecY1)
{
	x = x1;
=======
<<<<<<< HEAD
Object::Object(float x1, float y1, float z1, float size1, float r1, float g1, float b1, float a1, float velo1, float vecX1, float vecY1)
{
	x = x1;
=======
Object::Object(float dfg, float y1, float z1, float size1, float r1, float g1, float b1, float a1)
{
	x = dfg;
>>>>>>> 2b28763255150fb4e7e2b929db0573b1a75e2374
>>>>>>> f3b9eebab11e6386f8da67cc14a86976a8b07e81
	y = y1;
	z = z1;
	size = size1;
	r = r1;
	g = g1;
	b = b1;
	a = a1;
<<<<<<< HEAD

	velo = velo1;
	vecX = vecX1;
	vecY = vecY1;
}

void Object::update()
{
	x = x + change*vecX*velo;
	//x = x + 1;
=======
<<<<<<< HEAD
	velo = velo1;
	vecX = vecX1; 
	vecY = vecY1;
}

void Object:: update()
{
	x = x+vecX*velo;
	//x = x + 1;
}
=======
>>>>>>> f3b9eebab11e6386f8da67cc14a86976a8b07e81
}

>>>>>>> 2b28763255150fb4e7e2b929db0573b1a75e2374

Object::~Object()
{
}
