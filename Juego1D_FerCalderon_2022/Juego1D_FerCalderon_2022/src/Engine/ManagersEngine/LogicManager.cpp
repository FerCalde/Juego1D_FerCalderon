#include "LogicManager.h"
#include "..\..\Juego1D_FerCalderon_2022.h"

//Forward Declaration de m_instance 
//LogicManager* LogicManager::m_instance = nullptr;

void LogicManager::InitLogic()
{
	InitGameObjects();
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
void LogicManager::InitGameObjects()
{
	int iEntityID = 0;

	Entity* auxNewEntity = new Player();
	auxNewEntity->SetID(iEntityID);

	auxNewEntity->AddComponent(new CMP_Transform);
	auxNewEntity->AddComponent(new CMP_Collider);
	auxNewEntity->AddComponent(new CMP_InputController);
	auxNewEntity->AddComponent(new CMP_Render);
	//auxNewEntity->AddComponent(new CMP_Shooter);

	//auxNewEntity->AddComponent(new CMP_Transform);
	float auxVel = 10;
	float auxPos = 15;
	char auxSymbol = 'X';

	auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
	auxNewEntity->FindComponent<CMP_Transform>()->SetVel(auxVel);
	auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
	auxNewEntity->ActivateEntity();

	m_entitiesList.push_back(auxNewEntity);
	iEntityID++;

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		auxNewEntity = new CEnemy();
		auxNewEntity->AddComponent(new CMP_Transform);
		auxNewEntity->AddComponent(new CMP_Collider);
		auxNewEntity->AddComponent(new CMP_Render);

		auxVel = 10;
		auxPos = 0;
		auxSymbol = '*';

		auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
		auxNewEntity->FindComponent<CMP_Transform>()->SetVel(auxVel);
		auxNewEntity->FindComponent<CMP_Transform>()->SetMoveDir(1);
		auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
		auxNewEntity->SetID(iEntityID);
		auxNewEntity->DesactivateEntity();

		m_entitiesList.push_back(auxNewEntity);
		iEntityID++;

	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		auxNewEntity = new CBullet();
		auxNewEntity->AddComponent(new CMP_Transform);
		auxNewEntity->AddComponent(new CMP_Collider);
		auxNewEntity->AddComponent(new CMP_Render);

		auxVel = 0;
		auxPos = 0;
		auxSymbol = 'o';

		auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
		auxNewEntity->FindComponent<CMP_Transform>()->SetVel(auxVel);
		auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
		auxNewEntity->SetID(iEntityID);
		auxNewEntity->DesactivateEntity();

		m_entitiesList.push_back(auxNewEntity);
		iEntityID++;
	}
}

void LogicManager::ShutdownLogic()
{

	for (auto& _currentEntity : m_entitiesList)
	{
		delete _currentEntity;
		_currentEntity = nullptr;
	}
	m_entitiesList.clear();
	/*
	ShutdownTextures();*/
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
	RenderEngine::GetInstance().GetMap()->SetCleanMap(); //Seteo el mapa limpio para reiniciar las posiciones que eran ocupadas por entidades

	for (auto& entity : m_entitiesList)
	{
		if (entity->IsActive())
		{
			entity->Slot(_fFixedTick);

			UpdateMapEntityPositions(entity); //Comunicacion LogicEntityPosition con RenderMap
		}

	}

	SpawnEnemy(_fFixedTick);


}
void LogicManager::SpawnEnemy(const float& _fFixedTick)
{
	m_TimeSpawn += _fFixedTick;
	if (m_TimeSpawn >= m_TimeSpawn_MAX)
	{
		for (size_t i = 0; i < LogicManager::GetInstance().m_entitiesList.size(); i++)
		{
			if (!LogicManager::GetInstance().m_entitiesList[i]->IsActive())
			{
				LogicManager::GetInstance().m_entitiesList[i]->ActivateEntity();
				break;
			}
		}

		m_TimeSpawn = 0;
	}
}
void LogicManager::UpdateMapEntityPositions(Entity*& currentEntity)
{

	//char* auxLogicMap = RenderEngine::GetInstance().GetMap()->ptrMyBoard;
	//Forma posiblemente mas segura, crear auxiliar char[] para no sobreescribir las variables de otros scripts. Llamar a funcion de 
	// RenderEngine::UpdateMapPositions.
	//RenderEngine::GetInstance().ClearScene(); //Limpio pantalla (?)



	if (currentEntity->IsActive()) //En caso de estar activado
	{
		if (currentEntity->FindComponent<CMP_Render>() != NULL) //En caso de tener un componente Render
		{
			//TODO: Cambiar color texto! (GAME OVER(?))
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12);


			int auxEntityPos = currentEntity->FindComponent<CMP_Transform>()->GetPos().x; //La posicion del entity guardado para sobreescribir su index en el mapa
			RenderEngine::GetInstance().GetMap()->ptrMyBoard[auxEntityPos] = currentEntity->FindComponent<CMP_Render>()->GetSymbol(); //Cargo el simbolo de la entidad en la posicion que tenga en el mundo

		}
	}

}

