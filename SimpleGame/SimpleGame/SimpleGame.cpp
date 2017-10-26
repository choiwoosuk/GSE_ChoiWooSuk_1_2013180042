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

#include "Renderer.h"
#include "Object.h"
#include <cstdlib>
#include "ctime"
#include "SceneMngr.h"

bool mousech = true;

Renderer *g_Renderer = NULL;
Object b[MAX_OBJECTS_COUNT];
SceneMngr *SM = NULL;

void RenderScene(void)
{
	DWORD currTime = timeGetTime();
	SM->RenderScene(b);
}

void Idle(void)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		b[i].Update();
	}
	SM->Collide(b);
	
	SM->RenderScene(b);
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			if (mousech)
				mousech = false;
			else if (!mousech)
				mousech = true;
		}
	}
	SM->RenderScene(b);
}

void KeyInput(unsigned char key, int x, int y)
{
	SM->RenderScene(b);
}

void SpecialKeyInput(int key, int x, int y)
{
	SM->RenderScene(b);
}

int main(int argc, char **argv)
{
	
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		SM->Add(b, i);
	}

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	
	g_Renderer = new Renderer(500, 500);

	if (!g_Renderer->IsInitialized())
	{
		cout << "Renderer could not be initialized.. \n";
	}
	
	SM = new SceneMngr();
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

