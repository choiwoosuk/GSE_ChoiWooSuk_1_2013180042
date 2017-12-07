#include "stdafx.h"
#include "SceneManager.h"
#include "Sound.h"

//int k = 0;

SceneManager::SceneManager(int width, int height)
{
	g_Renderer = new Renderer(width, height);
	m_sound = new Sound();
	soundBG = m_sound->CreateSound("./Resource/bgm.mp3");
	Ogong = g_Renderer->CreatePngTexture("./Resource/ogong.png");
	Vegeta = g_Renderer->CreatePngTexture("./Resource/vegeta.png");
	Bg = g_Renderer->CreatePngTexture("./Resource/bg2.png");
	Player = g_Renderer->CreatePngTexture("./Resource/player.png");
	Enemy = g_Renderer->CreatePngTexture("./Resource/enemy.png");
	Particle = g_Renderer->CreatePngTexture("./Resource/part.png");
	Particle2 = g_Renderer->CreatePngTexture("./Resource/part2.png");
	windowW = width;
	windowH = height;

	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		obj[i] = NULL;
	}
	m_sound->PlaySound(soundBG, true, 0.5);
}

void SceneManager::drawObject()
{
	g_Renderer->DrawTexturedRect(0,0, 0,800, 1, 1, 1, 1, Bg, 0.9);
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		if (obj[i] != NULL)
		{
			if (obj[i]->obj_type == OBJECT_BUILDING && obj[i]->Team == 1)
			{
				g_Renderer->DrawTexturedRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, Ogong, 0.1);
				g_Renderer->DrawSolidRectGauge(obj[i]->ob_x, obj[i]->ob_y - 30, obj[i]->ob_z, 35, 5, 1, 0, 0, obj[i]->color_a, (obj[i]->life / 500), 0.01);
			}
			else if (obj[i]->obj_type == OBJECT_BUILDING && obj[i]->Team == 2)
			{
				g_Renderer->DrawTexturedRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, Vegeta, 0.1);
				g_Renderer->DrawSolidRectGauge(obj[i]->ob_x, obj[i]->ob_y + 30, obj[i]->ob_z, 35, 5, 0, 0, 1, obj[i]->color_a, (obj[i]->life / 500), 0.01);
			}
			else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[i]->Team == 1)
			{
				//g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, obj[i]->level);
				g_Renderer->DrawTexturedRectSeq(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, Enemy, obj[i]->ani, 0, 6, 1, obj[i]->level);
				g_Renderer->DrawSolidRectGauge(obj[i]->ob_x, obj[i]->ob_y + 15, obj[i]->ob_z, 35, 5, 1, 0, 0, obj[i]->color_a, (obj[i]->life / 10), 0.01);
			}
			else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[i]->Team == 2)
			{
				//g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, obj[i]->level);
				g_Renderer->DrawTexturedRectSeq(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, Player, obj[i]->ani, 0, 6, 1, obj[i]->level);
				g_Renderer->DrawSolidRectGauge(obj[i]->ob_x, obj[i]->ob_y + 15, obj[i]->ob_z, 35, 5, 0, 0, 1, obj[i]->color_a, (obj[i]->life / 10), 0.01);
			}
			else if (obj[i]->obj_type == OBJECT_BULLET && obj[i]->Team == 1)
			{
				g_Renderer->DrawParticle(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, 1, 1, 1, obj[i]->color_a, -obj[i]->ob_vecX/200, -obj[i]->ob_vecY / 200,Particle,obj[i]->part);
				g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, obj[i]->level);
			}
			else if (obj[i]->obj_type == OBJECT_BULLET && obj[i]->Team == 2)
			{
				g_Renderer->DrawParticle(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, 1, 1, 1, obj[i]->color_a, -obj[i]->ob_vecX / 200, -obj[i]->ob_vecY / 200, Particle2, obj[i]->part);
				g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, obj[i]->level);
			}
			else
			{
			g_Renderer->DrawSolidRect(obj[i]->ob_x, obj[i]->ob_y, obj[i]->ob_z, obj[i]->ob_size, obj[i]->color_r, obj[i]->color_g, obj[i]->color_b, obj[i]->color_a, obj[i]->level);
			}
		}
	}
	g_Renderer->DrawText(-50, 0, GLUT_BITMAP_HELVETICA_18, 0, 0, 0, "Dead or Alive");
}

int SceneManager::addObject(float x, float y, int type, int team)
{
	/*
	if (k > 10)
	{
		cout << "slots are full \n";
		return -1;
	}
	*/

	for (int i = 0; i < MAX_OBJECT; i++)
	{
		if (obj[i] == NULL)
		{
			obj[i] = new Object(x, y, type, team);

			/*
			if (obj[i]->obj_type == OBJECT_CHARACTER)
			{
				++k;
			}
			*/
			return i;
			cout << "오브젝트 생성" << endl;
		}
	}
	//slots are full
	cout << "slots are full \n";
	return -1;
}

int SceneManager::addBullet(float x, float y, int type, int team)
{
	for (int i = 0; i < MAX_OBJECT; i++)
	{
		if (obj[i] == NULL)
		{
			obj[i] = new Object(x, y, type, team);
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
						//건물에 상대편 캐릭터가 부딪힐경우
						if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->Team != obj[j]->Team)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
							g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
						}
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->Team != obj[i]->Team)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
							//g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
						}

						//건물에서 총알 발사 상대편 진영에 맞게
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_BULLET && obj[j]->Team != obj[i]->Team)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
							g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
						}
						else if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_BULLET && obj[i]->Team != obj[j]->Team)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
							//g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
						}

						//캐릭터가 총알에 맞았을때
						else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->obj_type == OBJECT_BULLET && obj[i]->Team != obj[j]->Team)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
						}
						else if (obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->obj_type == OBJECT_BULLET && obj[j]->Team != obj[i]->Team)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
						}

						//캐릭터가 화살에 맞았을때
						else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->obj_type == OBJECT_ARROW && obj[i]->Team != obj[j]->Team)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
						}
						else if (obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->obj_type == OBJECT_ARROW && obj[j]->Team != obj[i]->Team)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
						}

						//빌딩이 화살에 맞았을때
						else if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_ARROW && obj[i]->Team != obj[j]->Team)
						{
							obj[i]->life = obj[i]->life - obj[j]->life;
							obj[j]->life = 0;
							colCheck++;
							g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
							//cout << obj[i]->life << endl;
						}
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_ARROW && obj[j]->Team != obj[i]->Team)
						{
							obj[j]->life = obj[j]->life - obj[i]->life;
							obj[i]->life = 0;
							colCheck++;
							//g_Renderer->SetSceneTransform(10, 10, 1.1, 1.1);
						}
						/*
						//건물에 자기편 캐릭터가 부딪힐경우
						if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_CHARACTER && obj[i]->Team == obj[j]->Team)
						{
						colCheck = 0;
						}
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_CHARACTER && obj[j]->Team == obj[i]->Team)
						{
						colCheck = 0;
						}

						//건물에서 총알 발사 자신에게 안맞게
						else if (obj[j]->obj_type == OBJECT_BUILDING && obj[i]->obj_type == OBJECT_BULLET && obj[j]->Team == obj[i]->Team)
						{
						colCheck = 0;
						}
						else if (obj[i]->obj_type == OBJECT_BUILDING && obj[j]->obj_type == OBJECT_BULLET && obj[i]->Team == obj[j]->Team)
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

						else
						{
							colCheck++;
						}
						*/
					}
				}
			}
			/*
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
			*/
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
	g_Renderer->SetSceneTransform(0, 0, 1, 1);
	collision();
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		if (obj[i] != NULL)
		{
			if (obj[i]->GetLife() < 0.0001f || obj[i]->GetLifeTime() < 0.0001f)
			{
				//cout << "die" << endl;
				/*
				if (obj[i]->obj_type == OBJECT_CHARACTER)
				{
					--k;
				}
				*/
				deleteObj(i);
			}
			else
			{
				obj[i]->update(elapseT);
				if (obj[i]->obj_type == OBJECT_BUILDING && obj[i]->Team == 1)
				{
					if (obj[i]->bulletTime > BULLETTIME)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_BULLET,1);
						obj[i]->bulletTime = 0;
					}
				}
				else if (obj[i]->obj_type == OBJECT_BUILDING && obj[i]->Team == 2)
				{
					if (obj[i]->bulletTime > BULLETTIME)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_BULLET, 2);
						obj[i]->bulletTime = 0;
					}
				}

				else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[i]->Team == 1)
				{
					if (obj[i]->bulletTime > ARROWTIME)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_ARROW,1);
						obj[i]->bulletTime = 0;
					}
				}
				else if (obj[i]->obj_type == OBJECT_CHARACTER && obj[i]->Team == 2)
				{
					if (obj[i]->bulletTime > ARROWTIME)
					{
						addBullet(obj[i]->ob_x, obj[i]->ob_y, OBJECT_ARROW, 2);
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