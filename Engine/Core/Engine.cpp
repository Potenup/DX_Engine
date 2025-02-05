#include "Engine.h"
#include "Window.h"
#include "../Render/Renderer.h"

namespace Blue
{
	Engine* Engine::instance = nullptr;

	Engine::Engine(
		uint32 width,
		uint32 height,
		const std::wstring& title,
		HINSTANCE hInstance
	)
	{
		// 싱글톤 객체 값 설정.
		this->instance = this;

		// 창 객체 생성.
		this->window = std::make_shared<Window>(
			width, height, title, hInstance, WindowProc
		);

		// 렌더러 생성.
		this->renderer = std::make_shared<Renderer>(
			width, height, window->Handle()
		);
	}

	Engine::~Engine()
	{
	}

	void Engine::Run()
	{
		// 메시지 처리 루프.
		MSG msg = {};

		// 루프
		while (msg.message != WM_QUIT)
		{
			// 창에 메시지가 들어올 떄 실행.
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				// 메시지 번역.
				TranslateMessage(&msg);

				// 메시지 전달.
				DispatchMessage(&msg);
			}
			// 창에 메시지가 없을 때 다른 작업 처리.
			else
			{
				// 엔진 루프.
				renderer->Draw();
			}
		}
	}

	LRESULT Engine::WindowProc(
		HWND handle, 
		UINT message, 
		WPARAM wparam, 
		LPARAM lparam
	)
	{
		// 메시지 처리.
		switch (message)
		{
			// 창이 삭제되면 실행됨.
		case WM_DESTROY:
			// 이 때 프로그램 종료 메시지를 발생.
			PostQuitMessage(0);
			return (0);
		}

		// 기본 메시지 처리.
		return DefWindowProc(handle, message, wparam, lparam);
	}

	Engine& Engine::Get()
	{
		return (*instance);
	}
}