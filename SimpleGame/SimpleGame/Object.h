#pragma once
class Object
{

public:
	int change = 1;
	float x, y, z, size, r, g, b, a ,velo, vecX, vecY;
	Object();

	Object(float x, float y, float z, float size, float r, float g, float b, float a, float velo, float vecX, float vecY);
	
	void update();


	~Object();
};

