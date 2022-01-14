#include "Components.h"



#pragma region CMP_Transform
CMP_Transform::CMP_Transform()
{
	ptrNewPosMsg = new NewPosMsg(GetPos());
}

CMP_Transform::~CMP_Transform()
{
	delete ptrNewPosMsg;
	ptrNewPosMsg = nullptr;
}

void CMP_Transform::Slot(const float& _elapsed)
{
	UpdatePosition(_elapsed); 
	ptrNewPosMsg->SetNewPos(GetPos()); 
	m_CmpOwner->SendMsg(ptrNewPosMsg); 
}

void CMP_Transform::RecibirMsg(Message* _msgType)
{
	NewPosMsg* auxPosMsg = dynamic_cast<NewPosMsg*>(_msgType);
	if (auxPosMsg) 
	{ 
		SetPos(auxPosMsg->GetNewPos());
	}

	NewVelMsg* auxVelMsg = dynamic_cast<NewVelMsg*>(_msgType);
	if (auxVelMsg)
	{
		SetVel(auxVelMsg->GetNewVel());
	}
}
#pragma endregion

#pragma region CMP_Collider

CMP_Collider::CMP_Collider()
{
	ptrCollisionMsg = new CollisionMsg(false, -1);
	ptrLimitCollisionMsg = new LimitWorldCollMsg();
}

CMP_Collider::~CMP_Collider()
{
	delete ptrCollisionMsg;
	ptrCollisionMsg = nullptr;

	delete ptrLimitCollisionMsg;
	ptrLimitCollisionMsg = nullptr;
}

bool CMP_Collider::IsColliding(Entity* _otherEntity)
{
	/*LogicManager::GetInstance();

	float dist = (GetRadius() + LogicManager::GetInstance()->m_entitiesList[_otherEntity->GetID()]->FindComponent<CMP_Collider>()->GetRadius())
		* (GetRadius() + LogicManager::GetInstance()->m_entitiesList[_otherEntity->GetID()]->FindComponent<CMP_Collider>()->GetRadius());

	if (this->m_CmpOwner != _otherEntity)
	{
		if (vlen2(GetPos() - LogicManager::GetInstance()->m_entitiesList[_otherEntity->GetID()]->FindComponent<CMP_Transform>()->GetPos()) <= dist)
		{
			return true;
		}
	}*/

	return false;

	
}

void CMP_Collider::Slot(const float& _elapsed)
{
	

	/*for (auto& _otherEntity : LogicManager::GetInstance()->m_entitiesList)
	{
		if (IsColliding(_otherEntity))
		{
			ptrCollisionMsg->SetCollision(true);
			ptrCollisionMsg->SetIndex(_otherEntity->GetID());

			m_CmpOwner->SendMsg(ptrCollisionMsg);
			break;
		}
	}

	m_CmpOwner->SendMsg(ptrLimitCollisionMsg);*/
}

void CMP_Collider::RecibirMsg(Message* _msgType)
{
	//CollisionMsg* collisionMsg = dynamic_cast<CollisionMsg*>(_msgType);
	//if (collisionMsg)
	//{
	//	if (collisionMsg->GetCollision())
	//	{

	//		EntCollisionMsg* auxEntColMsg = new EntCollisionMsg();
	//		m_CmpOwner->SendMsg(auxEntColMsg);

	//		//Optimizacion
	//		delete auxEntColMsg;
	//		auxEntColMsg = nullptr;

	//		
	//	}
	//	else
	//	{
	//		NewPosMsg* auxPosMsg = new NewPosMsg(GetPos());
	//		m_CmpOwner->SendMsg(auxPosMsg);
	//		
	//		//Optimizacion
	//		delete auxPosMsg;
	//		auxPosMsg = nullptr;
	//	}
	//}

	//EntCollisionMsg* auxEntColMsg = dynamic_cast<EntCollisionMsg*>(_msgType);
	//if (auxEntColMsg)
	//{
	//	NewVelMsg* auxVelMsg = new NewVelMsg();
	//	m_CmpOwner->SendMsg(auxVelMsg);

	//	//Optimizacion
	//	delete auxVelMsg;
	//	auxVelMsg = nullptr;
	//}

	//LimitWorldCollMsg* auxLimitCollMsg = dynamic_cast<LimitWorldCollMsg*>(_msgType);
	//if (auxLimitCollMsg)
	//{
	//	if ((GetPos().x > auxLimitCollMsg->GetLimitWidth()) || (GetPos().x < 0))
	//	{
	//		NewVelMsg* auxVelMsg = new NewVelMsg();
	//		m_CmpOwner->SendMsg(auxVelMsg);

	//		//Optimizacion
	//		delete auxVelMsg;
	//		auxVelMsg = nullptr;
	//	}
	//	if ((GetPos().y > auxLimitCollMsg->GetLimitHeight()) || (GetPos().y < 0))
	//	{
	//		NewVelMsg* auxVelMsg = new NewVelMsg();
	//		m_CmpOwner->SendMsg(auxVelMsg);

	//		//Optimizacion
	//		delete auxVelMsg;
	//		auxVelMsg = nullptr;
	//	}
	//}
}
#pragma endregion



#pragma region CMP_Render
//void CMP_Render::SetGfxSprite(const GLuint& _gfxSprite)
//{
//	m_gfx = _gfxSprite;
//}

#pragma endregion

void CMP_Render::SetSymbol(char _objectSymbol)
{
	m_symbolObject = _objectSymbol;
}

char CMP_Render::GetSymbol() const
{
	return m_symbolObject;
}
