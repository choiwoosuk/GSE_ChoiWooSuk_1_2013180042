#include "stdafx.h"
#include "Object.h"
#include <cstdlib>
#include "ctime"

Object::Object()
{
	x = 0;
	y = 0;
	z = 0;
	size = 20;
	spd = 1;
	r = 1;
	g = 1;
	b = 1;
	a = 1;
	vecx = 1;
	vecy = -1;
	colck = false;
	life = 50;
	life_time = 100;
}

void Object::Update()
{
	x = x + spd*vecx;
	if (x >= 250)
		vecx = -vecx;
	else if (x< -250)
		vecx = -vecx;
	y = y + spd*vecy;
	if (y >= 250)
		vecy = -vecy;
	else if (y< -250)
		vecy = -vecy;

	if (colck)
	{
		r = 1;
		g = 0;
		b = 0;
	}
	else if(!colck)
	{
		r = 1;
		g = 1;
		b = 1;
	}
}

void Object::DeleteObject(Object *a[])
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (life <= 0)
		{
			delete(&a[i]);
		}
	}
}

Object::~Object()
{
}