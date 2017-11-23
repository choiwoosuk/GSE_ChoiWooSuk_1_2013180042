/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"

#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Mmsystem.h"

#include "Renderer.h"
#include "Object.h"
#include "SceneManager.h"

//Renderer *g_Renderer = NULL;
//Object *obj = new Object();
SceneManager *scM = NULL;

bool Ldown = false;
DWORD prevTime = 0;

float timeCheck = 0;
float timeBoolCheck = 0;

bool timeBool = false;

void RenderScene(void)
{
	int x = rand() % 500 - 250;
	int y = rand() % 400;

	DWORD startTime = timeGetTime();
	DWORD elapsedTime = startTime - prevTime;
	prevTime = startTime;

	timeCheck = timeCheck + elapsedTime;
	timeBoolCheck = timeBoolCheck + elapsedTime;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClearDepth(1.f);

	// Renderer Test
	//obj->update(elapsedTime);
	//g_Renderer->DrawSolidRect(obj->ob_x,obj->ob_y,obj->ob_z,obj->ob_size,obj->color_r,obj->color_g,obj->color_b,obj->color_a);
	//cout << timeCheck/1000 << endl;
	if (timeCheck / 1000 > 3)
	{
		scM->addObject(x, y, OBJECT_CHARACTER, 1);
		timeCheck = 0;
	}
	if (timeBoolCheck / 1000 > 3)
	{
		timeBool = true;
		timeBoolCheck = 0;
	}
	scM->updateObj(elapsedTime);
	scM->drawObject();
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Ldown = true;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (Ldown == true)
		{
			if (-y + 400 > 0 && timeBool == true)
			{
				scM->addObject(x - 250, 0, OBJECT_CHARACTER, 2);
				timeBool = false;
			}
			else if(-y + 400 < 0 && timeBool == true)
			{
				scM->addObject(x - 250, -y + 400, OBJECT_CHARACTER, 2);
				timeBool = false;
			}
		}
		Ldown = false;
	}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 800);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	scM = new SceneManager(500, 800);
	scM->addObject(0, 350, OBJECT_BUILDING, 1);
	scM->addObject(-150, 300, OBJECT_BUILDING, 1);
	scM->addObject(150, 300, OBJECT_BUILDING, 1);

	scM->addObject(0, -350, OBJECT_BUILDING, 2);
	scM->addObject(-150, -300, OBJECT_BUILDING, 2);
	scM->addObject(150, -300, OBJECT_BUILDING, 2);

	prevTime = timeGetTime();

	glutMainLoop();

	delete scM;

    return 0;
}

