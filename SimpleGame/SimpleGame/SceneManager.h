#pragma once
#include "Renderer.h"
#include "Object.h"

class SceneManager
{
public:
	SceneManager(int width, int height);
	~SceneManager();

	void updateObj(float elapseT);
	void drawObject();
	int addObject(float x, float y, int type, int team);
	int addBullet(float x, float y, int type, int team);

	void collision();
	void deleteObj(int ob);

	Object *obj[MAX_OBJECT];
	//Object *bullet[MAX_OBJECT];
	Renderer *g_Renderer;

	int windowW;
	int windowH;
	int Ogong;
	int Vegeta;
};

