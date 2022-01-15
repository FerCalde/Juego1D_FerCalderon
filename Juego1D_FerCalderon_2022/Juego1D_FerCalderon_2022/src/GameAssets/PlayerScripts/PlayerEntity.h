#pragma once

#include "..\EntityComponentSystem\EntityAndComponent.h"
#include"..\EntityComponentSystem\Components.h"


class CMP_Collider;
class CMP_Render;
class CMP_Transform;

class Player : public Entity
{
public:
	Player() 
	{
		SetAlive(true);
		SetTag(Entity::ETagEntity::Player);
		m_eTagIgnore = Entity::ETagEntity::Bullet;
		/*Component* auxT = new CMP_Transform;
		AddComponent(auxT);

		auxT = new CMP_Collider;
		AddComponent(auxT);

		auxT = new CMP_Render;
		AddComponent(auxT);

		float auxVel = 10;
		float auxPos = 15;
		char auxSymbol = 'X';

		FindComponent<CMP_Transform>()->SetPos(auxPos);
		FindComponent<CMP_Transform>()->SetVel(auxVel);
		FindComponent<CMP_Render>()->SetSymbol(auxSymbol);
		ActivateEntity();

		auxT = nullptr;*/
	}
	~Player() {}

	bool isAlive = true;
	void SetAlive(bool _isAlive) { isAlive = _isAlive; }
	bool GetIsAlive() { return isAlive; }
};