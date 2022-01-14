#include "LogicManager.h"
#include "..\..\Juego1D_FerCalderon_2022.h"

//Forward Declaration de m_instance 
//LogicManager* LogicManager::m_instance = nullptr;

void LogicManager::InitLogic()
{
	//CreateSingleton();
	/*LogicManager* instanceLogicManager = LogicManager::GetInstance();
	LoadTextures();
	Entity* auxNewEntity = nullptr;
	for (unsigned int i = 0; i < NUM_BALLS; i++)
	{
		auxNewEntity = new Ball();

		vec2 auxPos(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		vec2 auxVel(vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED) * 10, CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED) * 10));
		float auxRadius(16.f);

		auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
		auxNewEntity->FindComponent<CMP_Transform>()->SetVel(auxVel);

		auxNewEntity->FindComponent<CMP_Collider>()->SetRadius(16.f);

		auxNewEntity->FindComponent<CMP_Render>()->SetGfxSprite(texsmallball);

		auxNewEntity->SetID(instanceLogicManager->id);

		instanceLogicManager->m_entitiesList.push_back(auxNewEntity);
		instanceLogicManager->id++;
	}
	auxNewEntity = nullptr;*/
}

void LogicManager::ShutdownLogic()
{

	/*for (auto& _currentEntity : m_entitiesList)
	{
		delete _currentEntity;
		_currentEntity = nullptr;
	}
	m_entitiesList.clear();

	ShutdownTextures();*/
}


void LogicManager::LoadTextures()
{

}

void LogicManager::ShutdownTextures()
{

}



void LogicManager::LogicSlot(MyTimerManager& _timerManager)
{
	_timerManager.InitSlotsToProcess();

	while (_timerManager.ProcessSlots()) // si elapsedTime es mayor o igual que fixedTick..
	{

		LogicWorldSlot(_timerManager.GetFixedTick());

		_timerManager.ElapsedFixedTick();
		//SYS_Sleep(16);
	}
}

void LogicManager::LogicWorldSlot(const float& _fFixedTick)
{
	for (auto& entity : m_entitiesList)
	{
		entity->Slot(_fFixedTick);
	}

	







}


