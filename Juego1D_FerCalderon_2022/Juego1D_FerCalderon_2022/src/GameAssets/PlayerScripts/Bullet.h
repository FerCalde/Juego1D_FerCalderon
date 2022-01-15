#pragma once
#include "PlayerEntity.h"

class CBullet : public Entity
{
public:
	CBullet(){}
	~CBullet(){}

	void SetInstigator(Entity* _instigator) { m_Instigator = _instigator; }
	Entity* GetInstigator() { return m_Instigator; }

private:
	Entity* m_Instigator = nullptr;
};