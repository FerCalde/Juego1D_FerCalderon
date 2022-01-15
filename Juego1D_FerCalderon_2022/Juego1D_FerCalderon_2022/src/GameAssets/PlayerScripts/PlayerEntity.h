#pragma once

#include"..\EntityComponentSystem\Components.h"
#include "..\EntityComponentSystem\EntityAndComponent.h"

class Player : public Entity
{
public:
	Player()
	{
	/*	Component* auxT = new CMP_Transform;
		AddComponent(auxT);

		auxT = new CMP_Collider;
		AddComponent(auxT);

		auxT = new CMP_Render;
		AddComponent(auxT);


		auxT = nullptr;*/
	}
		~Player() {}
};