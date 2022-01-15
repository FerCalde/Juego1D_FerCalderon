// Juego1D_FerCalderon_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "Juego1D_FerCalderon_2022.h"

using namespace std;


int main()
{

	MyTimerManager* ptrTimerManager = new MyTimerManager();
	ptrTimerManager->StartCounter();

	CInputManager::CreateSingleton();
	LogicManager::CreateSingleton();
	RenderEngine::CreateSingleton();

	LogicManager::GetInstance().InitLogic();
	RenderEngine::GetInstance().InitRender();
	
	while (LogicManager::GetInstance().m_GameManager->isPlayerAlive) // Controlling a request to terminate an application.
	{
		LogicManager::GetInstance().LogicSlot(*ptrTimerManager);
		RenderEngine::GetInstance().RenderSlot(ptrTimerManager->GetFPSRate(), ptrTimerManager->GetLogicCurrentTime(), ptrTimerManager->GetTime());
	}

	// End app.
	// Cambiar color texto! (GAME OVER)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "\n\nEND GAME!\n";

	RenderEngine::GetInstance().ShutdownRender();
	LogicManager::GetInstance().ShutdownLogic();


	delete ptrTimerManager;
	ptrTimerManager = nullptr;

}

