#pragma once
#include "paGameObject.h"
#include "paGameObject_Red.h"

namespace pa
{
	class Application
	{
	public:
		Application() ;
		~Application();

		void Initialize(HWND mHwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// 플레이어
		GameObject mPlayer;
		GameObject* mComputer;
		GameObject_red mPlayer_red;
	};
}

