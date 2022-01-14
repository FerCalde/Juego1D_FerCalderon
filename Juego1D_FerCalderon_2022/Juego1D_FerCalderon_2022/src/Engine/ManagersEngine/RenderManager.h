#pragma once
#include<string>
#include "ISingleton.h"
#include "LogicManager.h"
#include "..\..\GameAssets\EntityComponentSystem\Components.h"
#include "..\miscellaneous/vector2d.h"


class RenderEngine // SINGLETON
{
public:
	static RenderEngine* GetInstance()
	{
		/*if (instance == nullptr)
		{
			RenderEngine* instance = new RenderEngine;
		}*/
		static RenderEngine* instance;
		return instance;
	}

private:
	RenderEngine() { }
	static RenderEngine* instance;

public:
	void InitRender();
	void RenderSlot(const float& _fps, const float& _elapsed, const float& _currentTime);
	void ShutdownRender();
};