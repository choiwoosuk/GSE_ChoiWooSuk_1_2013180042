#pragma once
class Object
{

public:
<<<<<<< HEAD
	int change = 1;
	float x, y, z, size, r, g, b, a ,velo, vecX, vecY;
	Object();

	Object(float x, float y, float z, float size, float r, float g, float b, float a, float velo, float vecX, float vecY);
	
	void update();


=======
<<<<<<< HEAD
	float x, y, z, size, r, g, b, a ,velo, vecX, vecY;
	Object(float x, float y, float z, float size, float r, float g, float b, float a, float velo, float vecX, float vecY);
	void update();
=======
	float x, y, z, size, r, g, b, a;
	Object(float x, float y, float z, float size, float r, float g, float b, float a);
>>>>>>> 2b28763255150fb4e7e2b929db0573b1a75e2374
>>>>>>> f3b9eebab11e6386f8da67cc14a86976a8b07e81
	~Object();
};

