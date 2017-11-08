#include "stdafx.h"
#include "Object.h"
#include <math.h>


Object::Object(float x, float y, int name)
{
	if (name == OBJECT_BUILDING)
	{
		m_x = 0;
		m_y = 0;
		m_size = 50;
		m_color[0] = 100;
		m_color[1] = 100;
		m_color[2] = 0;
		m_color[3] = 200;

		m_life = 500.0f;
		m_vX = 0;
		m_vY = 0;
	}
	if (name == OBJECT_ARROW)
	{
		m_x = 0;
		m_y = 0;
		m_size = 50;
		m_color[0] = 100;
		m_color[1] = 100;
		m_color[2] = 0;
		m_color[3] = 0;

		m_life = 500.0f;
		m_vX = 0;
		m_vY = 0;
	}
	if (name == OBJECT_BULLET)
	{
		m_x = 0;
		m_y = 0;
		m_size = 50;
		m_color[0] = 100;
		m_color[1] = 100;
		m_color[2] = 0;
		m_color[3] = 0;

		m_life = 500.0f;
		m_vX = 0;
		m_vY = 0;
	}
	if (name == OBJECT_CHARACTER)
	{
		m_x = x;
		m_y = y;
		m_vX = 200.f *(((float)rand() / (float)RAND_MAX) - 0.5f);
		m_vY = 200.f *(((float)rand() / (float)RAND_MAX) - 0.5f);

		m_size = 10;
		m_color[0] = 1;
		m_color[1] = 1;
		m_color[2] = 1;
		m_color[3] = 1;

		m_life = 100.f;
		m_lifeTime = 500000.f;
	}
}


Object::~Object()
{
	
}


void Object::Update(float elapsedTime)
{
	float elapsedTimeInSecond = elapsedTime / 1000.f;

	m_x = m_x + m_vX * elapsedTimeInSecond;
	m_y= m_y + m_vY * elapsedTimeInSecond;

	if (m_x > 250)
	{
		m_vX = -m_vX;
	}

	if (m_x < -250)
	{
		m_vX = -m_vX;
	}

	if (m_y > 250)
	{
		m_vY = -m_vY;
	}

	if (m_y < -250)
	{
		m_vY = -m_vY;
	}

	if (m_life > 0.f)
	{
		m_life -= 0.5f;
	}

	if (m_lifeTime > 0.f)
	{
//		m_lifeTime -= elapsedTimeInSecond;
	}
}

float Object::GetLife()
{
	return m_life;
}

float Object::GetLifeTime()
{
	return m_lifeTime;
}
