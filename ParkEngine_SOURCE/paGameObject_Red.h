#pragma once
#include "CommonInclude.h"

namespace pa
{
	class GameObject_red
	{
	public:
		GameObject_red();
		~GameObject_red();

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
	};
}

