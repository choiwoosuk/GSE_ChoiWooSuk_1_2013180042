#include "stdafx.h"

Object::Object(float x, float y, int type)
{
	bulletTime = 0;

	if (type == OBJECT_BUILDING)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 50;
		color_r = 100;
		color_g = 50;
		color_b = 0;
		color_a = 0;
		ob_vecX = 0;
		ob_vecY = 0;
		life = 500;
		life_time = 50000;
		obj_type = OBJECT_BUILDING;
	}
	if (type == OBJECT_CHARACTER)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 10;
		color_r = 100;
		color_g = 100;
		color_b = 100;
		color_a = 0;
		ob_vecX = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 10;
		obj_type = OBJECT_CHARACTER;
	}
	if (type == OBJECT_BULLET)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 100;
		color_g = 0;
		color_b = 0;
		color_a = 0;
		ob_vecX = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 20;
		life_time = 1;
		obj_type = OBJECT_BULLET;
	}
	if (type == OBJECT_ARROW)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 0;
		color_g = 100;
		color_b = 0;
		color_a = 0;
		ob_vecX = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 5;
		obj_type = OBJECT_ARROW;
	}
}

void Object::update(float elapsedTime)
{
	float elapTime = elapsedTime / 1000.f;
	
	bulletTime += elapTime;

	ob_x = ob_x + ob_vecX*elapTime;
	ob_y = ob_y + ob_vecY*elapTime;
	if (ob_x > 250)
	{
		ob_vecX = -ob_vecX;
	}
	if (ob_x < -250)
	{
		ob_vecX = -ob_vecX;
	}

	if (ob_y > 250)
	{
		ob_vecY = -ob_vecY;
	}

	if (ob_y < -250)
	{
		ob_vecY = -ob_vecY;
	}
	if (life_time > 0.f)
	{
		life_time -= elapTime;
		//cout << life_time << "," << elapTime << endl;
	}
	/*
	if (life > 0.f)
	{
		life -= 0.5f;
	}
	*/
}

float Object::GetLife()
{
	return life;
}

float Object::GetLifeTime()
{
	return life_time;
}

Object::~Object()
{
}
