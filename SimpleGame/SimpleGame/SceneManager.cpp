#include "stdafx.h"
#include "SceneManager.h"

int k = 0;


SceneManager::SceneManager(int width, int height)
{
	g_Renderer = new Renderer(width, height);
	//texCharacter = g_Renderer->CreatePngTexture("./Resource/ogong.png");
	windowW = width;
	windowH = height;

	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		obj[i] = NULL;
	}
}

void SceneManager::drawObject()
{
	g_Renderer->DrawSolidRect(0, 0, 0, windowW, 0, 0, 0, 1);
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		if (obj[i] != NULL)
		{
			g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a);
			//g_Renderer->DrawTexturedRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, texCharacter);
			/*
			if (obj[i]->obj_type == OBJECT_BUILDING)
			{
			g_Renderer->DrawTexturedRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, texCharacter);
			}
			else
			{
			g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a);
			}
			*/
		}
	}
}

int SceneManager::addObject(float x, float y, int type)
{
	if (k > 10)
	{
		cout << "slots are full \n";
		return -1;
	}
	for (int i = 0; i < MAX_OBJECT; i++)
	{
		if (obj[i] == NULL)
		{
			obj[i] = new Object(x, y, type);
			if (obj[i]->obj_type == OBJECT_CHARACTER)
			{
				++k;
			}
			return i;
			cout << "오브젝트 생성" << endl;
		}
	}
	//slots are full
	cout << "slots are full \n";
	return -1;
}

int SceneManager::addBullet(float x, float y, int type)
{
	for (int i = 0; i < MAX_OBJECT; i++)
	{
		if (obj[i] == NULL)
		{
			obj[i] = new Object(x, y, type);
			return i;
			cout << "총알 생성" << endl;
		}
	}
	//slots are full
	cout << "총알 꽉참";
	return -1;
}

void SceneManager::collision()
{
	int colCheck = 0;
	for (int i = 0; i < MAX_OBJECT; i++)
	{
		colCheck = 0;
		if (obj[i] != NULL)
		{
			for (int j = 0; j < MAX_OBJECT; j++)
			{
				if (i == j)
					continue;
				if (obj[j] != NULL)
				{
					if ((obj[i]->ob_x - (obj[i]->ob_size / 2) <= obj[j]->ob_x + (obj[j]->ob_size / 2) && obj[i]->ob_y - (obj[i]->ob_size / 2) <= obj[j]->ob_y + (obj[j]->ob_size / 2)) &&
						(obj[i]->ob_x + (obj[i]->ob_size / 2) >= obj[j]->ob_x - (obj[j]->ob_size / 2) && obj[i]->ob_y + (obj[i]->ob_size / 2) >= obj[j]->ob_y - (obj[j]->ob_size / 2)))
					{
						//건물에 캐릭터가 부딪힐경우
						if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_CHARACTER)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
						}
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_CHARACTER)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
						}

						//건물에서 총알 발사 자신에게 안맞게
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_BULLET)
						{
							colCheck = 0;
						}
						else if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_BULLET)
						{
							colCheck = 0;
						}

						//캐릭터에서 화살 발사 자신에게 안맞게
						else if (obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->obj_type == OBJECT_ARROW)
						{
							colCheck = 0;
						}
						else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->obj_type == OBJECT_ARROW)
						{
							colCheck = 0;
						}

						//캐릭터가 총알에 맞았을때
						else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->obj_type == OBJECT_BULLET)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
						}
						else if (obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->obj_type == OBJECT_BULLET)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
						}

						//빌딩이 화살에 맞았을때
						else if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_ARROW)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
						}
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_ARROW)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
						}

						else
						{
							colCheck++;
						}
					}
				}
			}
			if (colCheck > 0)
			{
				obj[i]->color_r = 100;
				obj[i]->color_g = 0;
				obj[i]->color_b = 0;
			}
			else if (colCheck == 0)
			{
				if (obj[i]->obj_type == OBJECT_CHARACTER)
				{
					obj[i]->color_r = 100;
					obj[i]->color_g = 100;
					obj[i]->color_b = 100;
				}
				else if (obj[i]->obj_type == OBJECT_BUILDING)
				{
					obj[i]->color_r = 100;
					obj[i]->color_g = 100;
					obj[i]->color_b = 0;
				}
				else if (obj[i]->obj_type == OBJECT_ARROW)
				{
					obj[i]->color_r = 0;
					obj[i]->color_g = 100;
					obj[i]->color_b = 0;
				}
			}
		}
	}
}

void SceneManager::deleteObj(int ob)
{
	if (obj[ob] != NULL)
	{
		delete obj[ob];
		obj[ob] = NULL;
	}
}

void SceneManager::updateObj(float elapseT)
{
	collision();
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		if (obj[i] != NULL)
		{
			if (obj[i]->GetLife() < 0.0001f || obj[i]->GetLifeTime() < 0.0001f)
				//if (obj[i]->GetLife() < 0.0001f)
			{
				cout << "die" << endl;
				if (obj[i]->obj_type == OBJECT_CHARACTER)
				{
					--k;
				}
				deleteObj(i);
			}
			else
			{
				obj[i]->update(elapseT);
				if (obj[i]->obj_type == OBJECT_BUILDING)
				{
					if (obj[i]->bulletTime > 0.5f)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_BULLET);
						obj[i]->bulletTime = 0;
					}
				}

				else if (obj[i]->obj_type == OBJECT_CHARACTER)
				{
					if (obj[i]->bulletTime > 0.5f)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_ARROW);
						obj[i]->bulletTime = 0;
					}
				}
			}
		}
	}
}

SceneManager::~SceneManager()
{
}