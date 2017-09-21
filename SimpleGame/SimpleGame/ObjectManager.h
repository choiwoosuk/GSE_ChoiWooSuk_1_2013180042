#pragma once

#include <iostream>

using namespace std;

class ObjectManager {
private:
	float ObjectXposition;
	float ObjectYposition;
	float ObjectZposition;

	float ObjectSize;

	float ObjectRed;
	float ObjectGreen;
	float ObjectBlue;
	float ObjectAlpha;

	float ObjectVolume;		//부피
	float ObjectWeight;		//무게


public:
	// 생성자를 통해 도형마다 좌표값 및 색상값을 설정하도록 함.


	//Rect
	ObjectManager(float x, float y, float z, float s, float r, float g, float b, float a) {
		ObjectXposition = x;
		ObjectYposition = y;
		ObjectZposition = z;
		ObjectSize = s;
		ObjectRed = r;
		ObjectGreen = g;
		ObjectBlue = b;
		ObjectAlpha = a;
	}

	//초기화?
	/*void ObjectRectInitialize(float x, float y, float z, float s, float r, float g, float b, float a)
	//{
	//	ObjectXposition = x;
	//	ObjectYposition = y;
	//	ObjectZposition = z;
	//	ObjectSize = s;
	//	ObjectRed = r;
	//	ObjectGreen = g;
	//	ObjectBlue = b;
	//	ObjectAlpha = a;
	};*/


	//Get함수부 
	float GetObjectXposition();
	float GetObjectYposition();
	float GetObjectZposition();

	float GetObjectSize();

	float GetObjectRed();
	float GetObjectGreen();
	float GetObjectBlue();
	float GetObjectAlpha();


	//소멸자
	~ObjectManager() {};

};