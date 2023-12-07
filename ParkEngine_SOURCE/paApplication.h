#pragma once
#include "paGameObject.h"

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

		// �÷��̾�
		GameObject mPlayer;
	};
}

