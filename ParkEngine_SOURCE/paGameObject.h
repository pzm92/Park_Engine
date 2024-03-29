#pragma once
#include "CommonInclude.h"


enum eAIRoad
{
	RIGHT = 0, DOWN, LEFT, UP	
};

namespace pa
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(int mode) { this->mode = mode; }
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;

		int mode = 0;
		float timer = 0.0f;
		eAIRoad ai;
	};
}

