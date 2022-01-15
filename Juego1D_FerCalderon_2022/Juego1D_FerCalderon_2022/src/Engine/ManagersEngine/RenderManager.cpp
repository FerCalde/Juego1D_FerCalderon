
#include "RenderManager.h"


//RenderEngine* RenderEngine::instance = nullptr;

void RenderEngine::InitRender()
{
	o_myMap = new myMap(WEIGHT_MAP);
}

void RenderEngine::ShutdownRender()
{
	delete o_myMap;
	o_myMap = nullptr;
}



void RenderEngine::RenderSlot(const float& _fps, const float& _elapsed, const float& _currentTime)
{
	ClearScene(); //Limpio la pantalla antes de pintar
	std::string mapString(RenderEngine::GetInstance().GetMap()->ptrMyBoard); //Cargo el mapa en una string
	std::cout << mapString << "\n" ;

	//std::cout << mapString << "\n" <<std::flush;
	//ClearScene();
	//LogicManager* instanceLogicManager = LogicManager::GetInstance();
	//// Render
	//glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.
	//// Render backgground
	//for (int i = 0; i <= SCR_WIDTH / 128; i++) {
	//	for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
	//		CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), instanceLogicManager->GetTexBK());
	//	}
	//}
	//// Render m_entitiesList
	//for (unsigned int i = 0; i < instanceLogicManager->m_entitiesList.size(); i++) {
	//	CORE_RenderCenteredSprite(instanceLogicManager->m_entitiesList[i]->FindComponent<CMP_Transform>()->GetPos(),
	//		vec2(instanceLogicManager->m_entitiesList[i]->FindComponent<CMP_Collider>()->GetRadius() * 2.f,
	//			instanceLogicManager->m_entitiesList[i]->FindComponent<CMP_Collider>()->GetRadius() * 2.f),
	//		instanceLogicManager->m_entitiesList[i]->FindComponent<CMP_Render>()->GetGfxSprite());
	//}
	// Text
	//int roundElapsed = static_cast<int>(_elapsed);
	//std::string s = std::to_string(_elapsed);
	//const char* logicCurrentTime = s.c_str();
	//int roundTime = static_cast<int>(_currentTime);
	//std::string s2 = std::to_string(roundTime);
	//const char* realCurrentTime = s2.c_str();
	//int roundFps = static_cast<int>(_fps);
	//std::string s3 = std::to_string(roundFps);
	//const char* currentFPS = s3.c_str();
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 60), "LOGIC TIME: ");
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 35), logicCurrentTime);
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 110), "REAL TIME");
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 85), realCurrentTime);
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 160), "CURRENT FPS");
	////FONT_DrawString(vec2(SCR_WIDTH / 2 + 5 * 15, 135), currentFPS);
	////// Exchanges the front and back buffers
	////SYS_Show();
}

void RenderEngine::UpdateRenderMapBoard(char* _auxLogicMap_)
{
	for (int i = 0; i < RenderEngine::GetInstance().WEIGHT_MAP
		; i++)
	{
		RenderEngine::GetInstance().GetMap()->ptrMyBoard[i] = _auxLogicMap_[i]; //Cargo el mapa auxiliar que envia el LogicManager cuando actualiza el mundo.
		
		
	}
}
