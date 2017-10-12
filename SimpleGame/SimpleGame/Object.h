#pragma once
class Object
{

public:
	float x, y, z, size, r, g, b, a ,velo, vecX, vecY;
	Object(float x, float y, float z, float size, float r, float g, float b, float a, float velo, float vecX, float vecY);
	void update();
	~Object();
};

