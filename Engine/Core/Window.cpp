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
        // â ����.
    // Register the window class.

        // â ������ �ʿ��� ���� ����ü.
        WNDCLASS wc = { };

        // �޽��� ó���� ���� �ݹ� ����.
        wc.lpfnWndProc = messageProcedure;

        // ���α׷� �ּ�����.
        wc.hInstance = instance;

        // â ������ ����� Ŭ���� �̸� ����.
        wc.lpszClassName = className.c_str();

        // Ŭ���� ���.
        if (!RegisterClass(&wc))
        {
            // ���� �޽��� Ȯ��.
            //auto error = GetLastError();

            // �޽��� ���.
            // #1 - ���â(Output) �̿�.
            OutputDebugStringA("Failed to register a window class\n");


            // #2 - �޽��� �ڽ� �̿�.
            MessageBoxA(nullptr, "Failed to register a window class", "����", MB_OK);

            // ������ ����.
            __debugbreak();
        }

        // ȭ�� ��� ��ġ ����.
        unsigned int positionX = ((GetSystemMetrics(SM_CXSCREEN) - width) / 2);
        unsigned int positionY = ((GetSystemMetrics(SM_CYSCREEN) - height) / 2);

        // â ũ�� ����.
        RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

        // â ũ�� �缳��.
        unsigned int windowWidth = rect.right - rect.left;
        unsigned int windowHeight = rect.bottom - rect.top;
        // �̷��� �ϸ� ���������� ����ϴ� ������ ���� ������ ũ�Ⱑ �˴ϴ�.
        this->handle = CreateWindow(
            className.c_str(),                          // Window class
            title.c_str(),           // Window text
            WS_OVERLAPPEDWINDOW,                // Window style
            // Size and position
            positionX,                      // x
            positionY,                      // y
            windowWidth,                          // �ʺ�
            windowHeight,                         // ����
            nullptr,        // Parent window    // â �ȿ� â�� ����
            nullptr,        // Menu             \// �޴��� â�ȿ� ����.
            instance,      // Instance handle
            nullptr          // Additional application data
        );

        if (this->handle == nullptr)
        {
            // #1 - ���â(Output) �̿�.
            OutputDebugStringA("Failed to create a window class\n");


            // #2 - �޽��� �ڽ� �̿�.
            MessageBoxA(nullptr, "Failed to create a window class", "����", MB_OK);

            // ������ ����.
            __debugbreak();
        }

        // â ���̱�.
        ShowWindow(this->handle, SW_SHOW);

        // â �޽��� ������Ʈ.
        UpdateWindow(this->handle);
	}

	Window::~Window()
	{
        // Ŭ���� ��� ����.
        UnregisterClass(className.c_str(), instance);
	}

	void Window::SetWidthHeight(uint32 width, uint32 height)
	{
		this->width = width;
		this->height = height;
	}
}