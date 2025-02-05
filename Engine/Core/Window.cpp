#include "Window.h"

namespace Blue
{
	Window::Window(
		uint32 width, 
		uint32 height, 
		const std::wstring& title, 
		HINSTANCE instance, 
		WNDPROC messageProcedure
	)
        : width(width), height(height), 
        title(title), instance(instance)
	{
        // 창 생성.
    // Register the window class.

        // 창 생성에 필요한 설정 구조체.
        WNDCLASS wc = { };

        // 메시지 처리를 위한 콜백 전달.
        wc.lpfnWndProc = messageProcedure;

        // 프로그램 주소전달.
        wc.hInstance = instance;

        // 창 생성에 사용할 클래스 이름 전달.
        wc.lpszClassName = className.c_str();

        // 클래스 등록.
        if (!RegisterClass(&wc))
        {
            // 오류 메시지 확인.
            //auto error = GetLastError();

            // 메시지 출력.
            // #1 - 출력창(Output) 이용.
            OutputDebugStringA("Failed to register a window class\n");


            // #2 - 메시지 박스 이용.
            MessageBoxA(nullptr, "Failed to register a window class", "오류", MB_OK);

            // 종단점 설정.
            __debugbreak();
        }

        // 화면 가운데 위치 설정.
        unsigned int positionX = ((GetSystemMetrics(SM_CXSCREEN) - width) / 2);
        unsigned int positionY = ((GetSystemMetrics(SM_CYSCREEN) - height) / 2);

        // 창 크기 조정.
        RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

        // 창 크기 재설정.
        unsigned int windowWidth = rect.right - rect.left;
        unsigned int windowHeight = rect.bottom - rect.top;
        // 이렇게 하면 실제적으로 사용하는 공간이 내가 설정한 크기가 됩니다.
        this->handle = CreateWindow(
            className.c_str(),                          // Window class
            title.c_str(),           // Window text
            WS_OVERLAPPEDWINDOW,                // Window style
            // Size and position
            positionX,                      // x
            positionY,                      // y
            windowWidth,                          // 너비
            windowHeight,                         // 높이
            nullptr,        // Parent window    // 창 안에 창이 가능
            nullptr,        // Menu             \// 메뉴도 창안에 있음.
            instance,      // Instance handle
            nullptr          // Additional application data
        );

        if (this->handle == nullptr)
        {
            // #1 - 출력창(Output) 이용.
            OutputDebugStringA("Failed to create a window class\n");


            // #2 - 메시지 박스 이용.
            MessageBoxA(nullptr, "Failed to create a window class", "오류", MB_OK);

            // 종단점 설정.
            __debugbreak();
        }

        // 창 보이기.
        ShowWindow(this->handle, SW_SHOW);

        // 창 메시지 업데이트.
        UpdateWindow(this->handle);
	}

	Window::~Window()
	{
        // 클래스 등록 해제.
        UnregisterClass(className.c_str(), instance);
	}

	void Window::SetWidthHeight(uint32 width, uint32 height)
	{
		this->width = width;
		this->height = height;
	}
}