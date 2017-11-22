#pragma once
#include <cstdlib>
class Object
{
public:
	Object(float x, float y, int type, int team);
	~Object();
	void update(float elapsedTime);

	float GetLife();
	float GetLifeTime();

	float ob_x;
	float ob_y;
	float ob_z;
	float ob_size;
	float color_r;
	float color_g;
	float color_b;
	float color_a;
	float ob_vecX;
	float ob_vecY;

	float life;
	float life_time;

	float bulletTime;
	float charTime;

	int obj_type;
	int Team;
};

