#pragma once
#include "CommonInclude.h"

namespace pa
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L, 
		Z, X, C, V, B, N, M,
		End
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;// 어떤 키가 들어오는지
			eKeyState state; // 해당키에 눌려져있는지
			bool bPressed; // 눌렸으면 참
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) {	return mKeys[(UINT)code].state == eKeyState::Down;}
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		// eKeyState mState = eKeyState::Up; // 0 1 2 
		static std::vector<Key> mKeys;
	};
}
