#include "LogicManager.h"
#include "..\..\Juego1D_FerCalderon_2022.h"

//Forward Declaration de m_instance 
//LogicManager* LogicManager::m_instance = nullptr;

Entity* LogicManager::FindGameObjectOfTag(Entity::ETagEntity _tagFinder)
{
	for (Entity* currentEntity : m_entitiesList)
	{
		if (!currentEntity->IsActive())
		{

			return (currentEntity->HasTag(_tagFinder)) ? currentEntity : nullptr;
			break;
		}

	}
	return nullptr;
}

void LogicManager::InitLogic()
{
	InitGameObjects();
	m_GameManager = new CGameManagerInfo;
}

void LogicManager::InitGameObjects()
{
	int iEntityID = 0;

	Entity* auxNewEntity = nullptr;

	//INIT PLAYER ENTITY
	auxNewEntity=new Player();
	auxNewEntity->SetID(iEntityID);

	auxNewEntity->AddComponent(new CMP_Transform);//SIEMPRE LO PRIMERO!
	auxNewEntity->AddComponent(new CMP_Collider);
	auxNewEntity->AddComponent(new CMP_InputController);
	auxNewEntity->AddComponent(new CMP_Render);
	auxNewEntity->AddComponent(new CMP_Shooter);
		//Set Initial Vars
	float auxVel = 10;
	float auxPos = 15;
	char auxSymbol = 'X';

	auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
	auxNewEntity->FindComponent<CMP_Transform>()->SetVelInit(auxVel);
	auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
	auxNewEntity->SetTag(Entity::ETagEntity::Player);

	auxNewEntity->ActivateEntity();

	m_entitiesList.push_back(auxNewEntity);
	iEntityID++;

	//INIT ENEMIES ENTITIES
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		auxNewEntity = new CEnemy();
		auxNewEntity->AddComponent(new CMP_Transform);
		auxNewEntity->AddComponent(new CMP_Collider);
		auxNewEntity->AddComponent(new CMP_Render);
		//Set Initial Vars
		auxVel = 10;
		auxPos = 0;
		auxSymbol = '*';

		auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
		auxNewEntity->FindComponent<CMP_Transform>()->SetMoveDir(1);
		auxNewEntity->FindComponent<CMP_Transform>()->SetVelInit(auxVel);
		auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
		auxNewEntity->SetID(iEntityID);
		auxNewEntity->SetTag(Entity::ETagEntity::Enemy);

		auxNewEntity->DesactivateEntity();

		m_entitiesList.push_back(auxNewEntity);
		iEntityID++;

	}

	//INIT BULLETS ENTITIES
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		auxNewEntity = new CBullet();
		auxNewEntity->AddComponent(new CMP_Transform);
		auxNewEntity->AddComponent(new CMP_Collider);
		auxNewEntity->AddComponent(new CMP_Render);

		auxVel = 10;
		auxPos = 0;
		auxSymbol = '8';

		auxNewEntity->FindComponent<CMP_Transform>()->SetPos(auxPos);
		auxNewEntity->FindComponent<CMP_Transform>()->SetVelInit(auxVel);
		auxNewEntity->FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
		auxNewEntity->SetID(iEntityID);
		auxNewEntity->SetTag(Entity::ETagEntity::Bullet);
		auxNewEntity->DesactivateEntity();

		m_entitiesList.push_back(auxNewEntity);
		iEntityID++;
	}

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

	//SpawnEnemy(_fFixedTick);

}

void LogicManager::UpdateMapEntityPositions(Entity*& currentEntity)
{
	if (currentEntity->IsActive()) //En caso de estar activado
	{
		if (currentEntity->FindComponent<CMP_Render>() != NULL) //En caso de tener un componente Render
		{

			int auxEntityPos = currentEntity->FindComponent<CMP_Transform>()->GetPos().x; //La posicion del entity guardado para sobreescribir su index en el mapa
			RenderEngine::GetInstance().GetMap()->ptrMyBoard[auxEntityPos] = currentEntity->FindComponent<CMP_Render>()->GetSymbol(); //Cargo el simbolo de la entidad en la posicion que tenga en el mundo

		}
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

	delete m_GameManager;
	m_GameManager = nullptr;
	/*
	ShutdownTextures();*/
}

void LogicManager::SpawnEnemy(const float& _fFixedTick)
{
	m_TimeSpawn += _fFixedTick;
	if (m_TimeSpawn >= m_TimeSpawn_MAX)
	{
		//PUEDO CAMBIAR ESTE CODIGO POR LA FUNC FINDGAMEOBJECTOFTAG
		for (size_t i = 0; i < LogicManager::GetInstance().m_entitiesList.size(); i++)
		{
			if (!LogicManager::GetInstance().m_entitiesList[i]->IsActive())
			{
				if (LogicManager::GetInstance().m_entitiesList[i]->HasTag(Entity::ETagEntity::Enemy))
				{

					LogicManager::GetInstance().m_entitiesList[i]->FindComponent<CMP_Transform>()->SetPos(0);
					LogicManager::GetInstance().m_entitiesList[i]->FindComponent<CMP_Transform>()->SetMoveDir(1);

					vec2 auxVel = LogicManager::GetInstance().m_entitiesList[i]->FindComponent<CMP_Transform>()->GetVelInit();
					LogicManager::GetInstance().m_entitiesList[i]->FindComponent<CMP_Transform>()->SetVel(auxVel);


					LogicManager::GetInstance().m_entitiesList[i]->ActivateEntity();
					break;
				}
			}
		}

		m_TimeSpawn = 0;
	}
}
