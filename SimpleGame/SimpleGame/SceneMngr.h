#pragma once
#include "Object.h"
#include "Renderer.h"
#define MAX_OBJECTS_COUNT 50

class SceneMngr
{
public:
	SceneMngr();
	~SceneMngr();
	Object a[MAX_OBJECTS_COUNT];

	void Add(Object a[], int index);
	void RenderScene(Object a[]);
	void Collide(Object a[]);
	void Update();

};
