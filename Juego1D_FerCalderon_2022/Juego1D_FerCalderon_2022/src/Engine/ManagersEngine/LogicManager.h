#pragma once
#include <vector>
#include "..\miscellaneous\vector2d.h"
#include "..\..\GameAssets\EnemyScripts\EnemyEntity.h"
#include "..\..\GameAssets\EntityComponentSystem\EntityAndComponent.h"
#include "..\..\GameAssets\PlayerScripts\PlayerEntity.h"
#include "ISingleton.h"
#include"RenderManager.h"
#include "TimerManager.h"

class LogicManager : public ISingleton<LogicManager>
{
private:
	//LogicManager() { }
	~LogicManager() {}
	


public:

	std::vector<Entity*> m_entitiesList; // creo el vector de Entidades

	void InitLogic();
	void ShutdownLogic();
	void LoadTextures();
	void ShutdownTextures();

	void LogicSlot(MyTimerManager& _timerManager);
	void LogicWorldSlot(const float& _fFixedTick);

	void UpdateMapEntityPositions(Entity*& currentEntity);

};








//class LogicManager
//{
//public:
//	static LogicManager* GetInstance()
//	{
//		if (m_instance == nullptr)
//		{
//			m_instance = new LogicManager;
//		}
//		return m_instance;
//	}
//
//	LogicManager() {}
//	static LogicManager* m_instance;
//
//
//public:
//
//	std::vector<Entity*> m_entitiesList; // creo el vector de Entidades
//
//
//
//	void InitLogic();
//	void ShutdownLogic();
//	void LoadTextures();
//	void ShutdownTextures();
//
//	void LogicSlot(MyTimerManager& _timerManager);
//	void LogicWorldSlot(const float& _fFixedTick);
//
//
//};



