#include "paGameObject_Red.h"

namespace pa
{
	GameObject_red::GameObject_red()
	{
	}

	GameObject_red::~GameObject_red()
	{
	}

	void GameObject_red::Update()
	{

		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObject_red::LateUpdate()
	{
	}

	void GameObject_red::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 255));

		//�Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HBRUSH oldPen = (HBRUSH)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, 900 + mX, 500 + mY, 1000 + mX, 600 + mY);	

		SelectObject(hdc, oldBrush); 		//�ٽ� ��� �����귯���� ����
		DeleteObject(redBrush);				//�Ķ� �귯�� ����
		DeleteObject(redPen);
	}
}