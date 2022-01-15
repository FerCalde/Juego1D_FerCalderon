// Juego1D_FerCalderon_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/ManagersEngine/InputManager.h"
#include "Engine/ManagersEngine/LogicManager.h"
#include "Engine/ManagersEngine/RenderManager.h"
#include "Engine/ManagersEngine/TimerManager.h"

#include "Juego1D_FerCalderon_2022.h"

using namespace std;


//struct myMap
//{
//	const int ROWS = 30;
//	const int COLUMNS = 3;
//
//	char* ptrMyBoard = nullptr;
//
//	myMap() 
//	{
//		InitDefaultMap();
//	}
//	myMap(const int _mapSize) : ROWS(_mapSize)
//	{
//		InitDefaultMap();
//	}
//
//	void InitDefaultMap()
//	{
//		ptrMyBoard = new char[ROWS];
//		for (int i = 0; i < ROWS; i++)
//		{
//			ptrMyBoard[i] = '_';
//		}
//		ptrMyBoard[ROWS - 1] = '\0';
//	}
//	/*char myboard[ROWS][COLUMNS] = { {'O',	'X',	'O'},
//									{'K',	'X',	'X'},
//									{'X',	'O',	'O'},
//	};*/
//};


int main()
{

	MyTimerManager* ptrTimerManager = new MyTimerManager();
	ptrTimerManager->StartCounter();

	CInputManager::CreateSingleton();
	LogicManager::CreateSingleton();
	RenderEngine::CreateSingleton();



	LogicManager::GetInstance().InitLogic();
	RenderEngine::GetInstance().InitRender();

	/*LogicManager::GetInstance().InitLogic();
	RenderEngine::GetInstance().InitRender();*/

	/*LogicManager* ptrLogicManager = LogicManager::GetInstance();
	RenderEngine* ptrRenderManager = RenderEngine::GetInstance();

	ptrLogicManager->InitLogic();
	ptrRenderManager->InitRender();*/
	
	while (true) // Controlling a request to terminate an application.
	{
		
		LogicManager::GetInstance().LogicSlot(*ptrTimerManager);
		RenderEngine::GetInstance().RenderSlot(ptrTimerManager->GetFPSRate(), ptrTimerManager->GetLogicCurrentTime(), ptrTimerManager->GetTime());
		

		
	
	}

	// End app.

	LogicManager::GetInstance().ShutdownLogic();
	RenderEngine::GetInstance().ShutdownRender();
	//ptrLogicManager->ShutdownLogic();
	//ptrRenderManager->ShutdownRender();

	delete ptrTimerManager;
	ptrTimerManager = nullptr;















	/*cout << "\nNow the tic tac toe board is: \n";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;
	}

	cout << "\n'X' wins!";*/


	std::cout << "Hello World!\n";
}

