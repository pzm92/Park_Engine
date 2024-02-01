#include "paApplication.h"
#include "paInput.h"
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
		mPlayer_red.SetPosition(0.0f, 0.0f);

		mComputer = new GameObject(1);
		mComputer->SetPosition(0.0f, 0.0f);

		Input::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{		 
		Input::Update();

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer_red.Render(mHdc);
		mComputer->Render(mHdc);
	}
}
