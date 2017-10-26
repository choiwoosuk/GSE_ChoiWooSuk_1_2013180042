#include "stdafx.h"
#include "iostream"
#include "SceneMngr.h"
#include "Object.h"
#include "cstdlib"
#include "ctime"
#include "Renderer.h"

Renderer *renderer = NULL;

float objx = rand() % 250;
float objy = rand() % 250;

SceneMngr::SceneMngr()
{
}


SceneMngr::~SceneMngr()
{
}

void SceneMngr::Add(Object a[], int index)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		a[i].x = rand() % 500 - 250;
		a[i].y = rand() % 500 - 250;
		a[i].spd = rand() % 5 + 1;
		a[i].vecx = rand() % 5-2.5;
		a[i].vecy = rand() % 5-2.5;
	}
}

void SceneMngr::Update()
{

}

void SceneMngr::RenderScene(Object a[])
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
		renderer->DrawSolidRect(a[i].x, a[i].y, a[i].z, a[i].size, a[i].r, a[i].g, a[i].b, a[i].a);

	//glutSwapBuffers();
}


void SceneMngr::Collide(Object a[])
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		for (int j = i+1; j < MAX_OBJECTS_COUNT; j++)
		{
			if ((a[i].x - (a[i].size / 2) <= a[j].x + (a[j].size / 2) &&
				a[i].y - (a[i].size / 2) <= a[j].y + (a[j].size / 2))&&
				(a[i].x + (a[i].size / 2) >= a[j].x - (a[j].size / 2) &&
				a[i].y + (a[i].size / 2) >= a[j].y - (a[j].size / 2)))
			{
				a[j].colck = true;
				a[i].colck = true;
			}
		}
	}
}
