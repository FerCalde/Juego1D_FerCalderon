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

	//if (this->m_CmpOwner != _otherEntity)
	//{
	//	if (vlen2(GetPos() - LogicManager::GetInstance()->m_entitiesList[_otherEntity->GetID()]->FindComponent<CMP_Transform>()->GetPos()) <= dist)
	//	{
	//		return true;
	//	}
	//}


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







void CMP_InputController::Slot(const float& _elapsed)
{
	CheckInput();
}

void CMP_InputController::CheckInput()
{
	if (CInputManager::GetInstance().IsKeyPressed(KEYBOARD_A))
	{
		m_CmpOwner->FindComponent<CMP_Transform>()->SetMoveDir(-1);
	}
	else if (CInputManager::GetInstance().IsKeyPressed(KEYBOARD_D))
	{
		m_CmpOwner->FindComponent<CMP_Transform>()->SetMoveDir(1);
	}
	else
	{
		m_CmpOwner->FindComponent<CMP_Transform>()->SetMoveDir(0);
	}
}

void CMP_Shooter::Slot(const float& _elapsed)
{
	// Chequear si ha pasado el tiempo entre disparos
	if (true)//)m_fTimeUntilNextAttack == 0.f)
	{
		// Comprobar si se ha pulsado alguna tecla asignada al disparo
		int iDirection = 0;
		if (CInputManager::GetInstance().IsKeyPressed(KEYBOARD_J))
		{
			iDirection = -1;
		}
		else if (CInputManager::GetInstance().IsKeyPressed(KEYBOARD_L))
		{
			iDirection = 1;
		}
		// En caso de detectar input, spawnear bala
		if (iDirection != 0)
		{
			//SpawnBullet(iDirection);
			// Una vez spawneada, cambiar variable contador para empezar la cuenta atras
			//m_fTimeUntilNextAttack = m_fTimeBetweenAttacks;
		}
	}
	else
	{
		// Cuenta atras
		/*m_fTimeUntilNextAttack -= _elapsed;
		if (m_fTimeUntilNextAttack < 0.f)
			m_fTimeUntilNextAttack = 0.f;*/
	}


}
