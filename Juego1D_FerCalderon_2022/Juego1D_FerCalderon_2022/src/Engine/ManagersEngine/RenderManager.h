#pragma once
#include<string>
#include "ISingleton.h"
#include "LogicManager.h"
#include "..\..\GameAssets\EntityComponentSystem\Components.h"
#include "..\miscellaneous/vector2d.h"
#include <iostream>
#include <stdlib.h>

//class CMap;


struct myMap
{
	const int ROWS = 30;
	const int COLUMNS = 3;

	char* ptrMyBoard = nullptr;

	myMap()
	{
		InitDefaultMap();
	}
	myMap(const int _mapSize) : ROWS(_mapSize)
	{
		InitDefaultMap();
	}

	void InitDefaultMap()
	{
		ptrMyBoard = new char[ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			ptrMyBoard[i] = '_';
		}
		ptrMyBoard[ROWS - 1] = '\0';
	}

	
	/*char myboard[ROWS][COLUMNS] = { {'O',	'X',	'O'},
									{'K',	'X',	'X'},
									{'X',	'O',	'O'},
	};*/
};




class RenderEngine : public ISingleton<RenderEngine> // SINGLETON
{
private:
	~RenderEngine() { }

public:

	myMap* o_myMap=nullptr;
	const int WEIGHT_MAP = 50;

	void InitRender();
	void RenderSlot(const float& _fps, const float& _elapsed, const float& _currentTime);
	void ShutdownRender();

	void UpdateGameObjectPosition(Entity& _entityRenderToUpdate);

	inline void ClearScene()
	{
		system("CLS");
	}

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