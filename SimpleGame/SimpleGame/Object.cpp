#include "stdafx.h"

Object::Object(float x, float y, int type, int team)
{
	bulletTime = 0;
	charTime = 0;

	if (type == OBJECT_BUILDING && team == 1)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 50;
		color_r = 100;
		color_g = 50;
		color_b = 0;
		color_a = 1;
		ob_vecX = 0;
		ob_vecY = 0;
		life = 500;
		life_time = 50000;
		obj_type = OBJECT_BUILDING;
		Team = 1;
	}
	else if (type == OBJECT_BUILDING && team == 2)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 50;
		color_r = 100;
		color_g = 50;
		color_b = 0;
		color_a = 1;
		ob_vecX = 0;
		ob_vecY = 0;
		life = 500;
		life_time = 50000;
		obj_type = OBJECT_BUILDING;
		Team = 2;
	}

	if (type == OBJECT_CHARACTER && team == 1)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 10;
		color_r = 1;
		color_g = 0;
		color_b = 0;
		color_a = 1;
		ob_vecX = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 1000;
		obj_type = OBJECT_CHARACTER;
		Team = 1;
	}
	else if (type == OBJECT_CHARACTER && team == 2)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 10;
		color_r = 0;
		color_g = 0;
		color_b = 1;
		color_a = 1;
		ob_vecX = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 300.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 1000;
		obj_type = OBJECT_CHARACTER;
		Team = 2;
	}

	if (type == OBJECT_BULLET && team == 1)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 1;
		color_g = 0;
		color_b = 0;
		color_a = 1;
		ob_vecX = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 20;
		life_time = 1500;
		obj_type = OBJECT_BULLET;
		Team = 1;
	}
	else if (type == OBJECT_BULLET && team == 2)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 0;
		color_g = 0;
		color_b = 1;
		color_a = 1;
		ob_vecX = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 600.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 20;
		life_time = 1500;
		obj_type = OBJECT_BULLET;
		Team = 2;
	}

	if (type == OBJECT_ARROW && team == 1)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 0.5;
		color_g = 0.2;
		color_b = 0.7;
		color_a = 1;
		ob_vecX = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 500;
		obj_type = OBJECT_ARROW;
		Team = 1;
	}
	else if (type == OBJECT_ARROW && team == 2)
	{
		ob_x = x;
		ob_y = y;
		ob_z = 0;
		ob_size = 2;
		color_r = 1;
		color_g = 1;
		color_b = 0;
		color_a = 1;
		ob_vecX = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		ob_vecY = 100.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		life = 10;
		life_time = 500;
		obj_type = OBJECT_ARROW;
		Team = 2;
	}
}

void Object::update(float elapsedTime)
{
	float elapTime = elapsedTime / 1000.f;
	bulletTime += elapTime;

	float elapTimeChar = elapsedTime / 1000.f;
	charTime += elapTimeChar;

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

	if (ob_y > 400)
	{
		ob_vecY = -ob_vecY;
	}

	if (ob_y < -400)
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
