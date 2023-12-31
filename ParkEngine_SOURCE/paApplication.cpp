#include "paApplication.h"

namespace pa
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0.0f, 0.0f);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{		 
		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}
