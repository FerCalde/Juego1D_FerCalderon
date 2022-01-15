#pragma once
#include "ISingleton.h"
#include <Windows.h>

#define KEYBOARD_J 'J'
#define KEYBOARD_L 'L'
#define KEYBOARD_A 'A'
#define KEYBOARD_D 'D'

typedef unsigned char Key;


class CInputManager :public ISingleton< CInputManager>
{
private:
	~CInputManager(){}

public :

	bool IsKeyPressed(Key _key)
	{
		return GetAsyncKeyState(_key) & 0x8000;
	}


};