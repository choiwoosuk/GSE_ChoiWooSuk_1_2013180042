#include "stdafx.h"
#include "SceneMgr.h"
#include "Object.h"

SceneMgr::SceneMgr()
{
}

void SceneMgr::add()
{
	Object a[MAX_OBJECT_COUNT] = {Object(x,y,0,10,1,1,1,0,1,1,1)};
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		//Object* a[i] = new Object();
	}

}

void SceneMgr::update()
{

}

SceneMgr::~SceneMgr()
{
}