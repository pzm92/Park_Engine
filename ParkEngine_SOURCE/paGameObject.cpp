#include "paGameObject.h"
#include "paInput.h"

namespace pa
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{//RIGHT = 0, DOWN, LEFT, UP
		if (mode == 1)
		{
			if (timer > 4.0f) timer = 0.0f;
			timer += 0.0001f;
			if(timer >= 0.0f && timer < 1.0f) mX += 0.1f;
			else if (timer >= 1.0f && timer < 2.0f) mY += 0.1f;
			else if (timer >= 2.0f && timer < 3.0f) mX -= 0.1f;
			else if (timer >= 3.0f && timer < 4.0f) mY -= 0.1f;	
		}
		else
		{
			if (Input::GetKey(eKeyCode::A))
			{
				mX -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::D))
			{
				mX += 0.01f;
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mY -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mY += 0.01f;
			}
		}		
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//�Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HBRUSH oldPen = (HBRUSH)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush); 		//�ٽ� ��� �����귯���� ����
		DeleteObject(blueBrush);			//�Ķ� �귯�� ����
		DeleteObject(redPen);
	}
}