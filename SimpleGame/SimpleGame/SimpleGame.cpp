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

void RenderScene(void)
{
	DWORD startTime = timeGetTime();
	DWORD elapsedTime = startTime - prevTime;
	prevTime = startTime;

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	//obj->update(elapsedTime);
	//g_Renderer->DrawSolidRect(obj->ob_x,obj->ob_y,obj->ob_z,obj->ob_size,obj->color_r,obj->color_g,obj->color_b,obj->color_a);
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
			scM->addObject(x-250,-y+250, OBJECT_CHARACTER);
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
	glutInitWindowSize(500, 500);
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

	scM = new SceneManager(500, 500);
	scM->addObject(0, 0, OBJECT_BUILDING);
	prevTime = timeGetTime();

	glutMainLoop();

	delete scM;

    return 0;
}

