#pragma once
class Object
{

public:
	float x, y, z, size, r, g, b, a,spd,vecx,vecy;
	float life, life_time;
	bool colck;
	Object();

	void Update();
	void DeleteObject(Object *a[]);

	~Object();
};

