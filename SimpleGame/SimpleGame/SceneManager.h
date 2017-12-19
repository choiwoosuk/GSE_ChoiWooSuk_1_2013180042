#pragma once
#include "Renderer.h"
#include "Object.h"
#include "Sound.h"

class SceneManager
{
public:
	SceneManager(int width, int height);
	~SceneManager();

	void updateObj(float elapseT);
	void drawObject();
	int addObject(float x, float y, int type, int team);
	int addBullet(float x, float y, int type, int team);
	void shake();

	void collision();
	void deleteObj(int ob);

	Object *obj[MAX_OBJECT];
	//Object *bullet[MAX_OBJECT];
	Renderer *g_Renderer;
	Sound *m_sound;

	int windowW;
	int windowH;
	int Ogong;
	int Vegeta;
	int Bg;
	int Player;
	int Enemy;
	int Particle;
	int Particle2;
	int Rain;
	int soundBG;
};