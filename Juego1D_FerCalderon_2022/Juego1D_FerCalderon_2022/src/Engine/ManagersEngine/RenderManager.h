#pragma once
#include<string>
#include "ISingleton.h"
#include "LogicManager.h"
#include "..\..\GameAssets\EntityComponentSystem\Components.h"
#include "..\miscellaneous/vector2d.h"
#include <iostream>

//class CMap;

class RenderEngine : public ISingleton<RenderEngine> // SINGLETON
{
private:
	~RenderEngine() { }

public:

	//CMap currentMap;

	void InitRender();
	void RenderSlot(const float& _fps, const float& _elapsed, const float& _currentTime);
	void ShutdownRender();
};


//
//class CMap
//{
//public:
//	CMap();
//	~CMap();
//
//	const int weight = 10;
//	char* boardMap;
//
//private:
//
//};
//
//CMap::CMap()
//{
//	boardMap = new char[weight];
//	for (int i = 0; i < weight; i++)
//	{
//		//board + i = '_';
//	}
//}
//
//CMap::~CMap()
//{
//}



//class CMapInfo
//{
//	const int m_height;
//	const int m_weight;
//	char m_mapBoardInfo[m_height][m_weight] = { {'O',	'X',	'O'},
//									{'K',	'X',	'X'},
//									{'X',	'O',	'O'},
//
//	}
//
//};