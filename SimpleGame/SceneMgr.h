#pragma once
class SceneMgr
{
public:
	int x = rand()%500;
	int y = rand()%500;

	SceneMgr();

	void add();
	void update();

	~SceneMgr();
};

