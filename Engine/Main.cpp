#include <Windows.h>

#include "Core/Window.h"
#include "Render/Renderer.h"
#include "Core/Engine.h"

// â�� ���õ� �޽����� ó���ϴ� �ݹ��Լ�,
LRESULT CALLBACK WindowProc(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
{
    // �޽��� ó��.
    switch (message)
    {
        // â�� �����Ǹ� �����.
        case WM_DESTROY:
            // �� �� ���α׷� ���� �޽����� �߻�.
            PostQuitMessage(0);
            return (0);
    }

    // �⺻ �޽��� ó��.
    return DefWindowProc(handle, message, wparam, lparam);
}

using namespace Blue;

// â ��� �� �� ���� �Լ�(Entry Point)
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,           // ���α׷��� �ּ�, ���α׷� ��ü�� �ν��Ͻ�
    _In_opt_ HINSTANCE hPrevInstance,   // ������ �Ⱦ�. ȣȯ ������ ���� �ʿ�(���� window)
    _In_ LPSTR lpCmdLine,               // 
    _In_ int nShowCmd                   //
)
{
#pragma region 
//    // â ����.
//    // Register the window class.
//
//    // â�� ����� Ŭ���� �̸�.
//    const wchar_t* className = TEXT("Sample Window Class");
//
//    // â ������ �ʿ��� ���� ����ü.
//    WNDCLASS wc = { };
//
//    // �޽��� ó���� ���� �ݹ� ����.
//    wc.lpfnWndProc = WindowProc;
//
//    // ���α׷� �ּ�����.
//    wc.hInstance = hInstance;
//
//    // â ������ ����� Ŭ���� �̸� ����.
//    wc.lpszClassName = className;
//
//    // Ŭ���� ���.
//    if (!RegisterClass(&wc))
//    {
//        // ���� �޽��� Ȯ��.
//        //auto error = GetLastError();
//
//        // �޽��� ���.
//        // #1 - ���â(Output) �̿�.
//        OutputDebugStringA("Failed to register a window class\n");
//
//
//        // #2 - �޽��� �ڽ� �̿�.
//        MessageBoxA(nullptr, "Failed to register a window class", "��/��", /MB_OK);
//
//        // ������ ����.
//        __debugbreak();
//    }
//
//    // â�� ���� ũ��.
//    unsigned int width = 1280;
//    unsigned int height = 800;
//    // Ÿ��Ʋ�ٿ� ���� �͵��� ȭ���� �����ϰ� �ֽ��ϴ�.
//    // �̷��͵��� ����ؼ� ȭ�� ũ�⸦ ������ �� �ֽ��ϴ�.
//    // fullhd? ���� ������(�̹��� ����) �б��ϰ� �ٽ� ����.
//    // âũ�⿡ ���� �޶����� ����.
//
//    // ȭ�� ��� ��ġ ����.
//    unsigned int positionX = ((GetSystemMetrics(SM_CXSCREEN) - /width) / /2);
//    unsigned int positionY = ((GetSystemMetrics(SM_CYSCREEN) - /height) / /2);
//
//    // â ũ�� ����.
//    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>//(height) };
//    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
//
//    // â ũ�� �缳��.
//    unsigned int windowWidth = rect.right - rect.left;
//    unsigned int windowHeight = rect.bottom - rect.top;
//    // �̷��� �ϸ� ���������� ����ϴ� ������ ���� ������ ũ�Ⱑ �˴ϴ�.
//    HWND hwnd = CreateWindow(
//        className,                          // Window class
//        TEXT("Blue Engine Demo"),           // Window text
//        WS_OVERLAPPEDWINDOW,                // Window style
//        // Size and position
//        positionX,                      // x
//        positionY,                      // y
//        windowWidth,                          // �ʺ�
//        windowHeight,                         // ����
//        nullptr,        // Parent window    // â �ȿ� â�� ����
//        nullptr,        // Menu             \// �޴��� â�ȿ� ����.
//        hInstance,      // Instance handle
//        nullptr          // Additional application data
//    );
//
//    if (hwnd == nullptr)
//    {
//        // #1 - ���â(Output) �̿�.
//        OutputDebugStringA("Failed to create a window class\n");
//
//
//        // #2 - �޽��� �ڽ� �̿�.
//        MessageBoxA(nullptr, "Failed to create a window class", "����", //MB_OK);
//
//        // ������ ����.
//        __debugbreak();
//    }
//
//    // â ���̱�.
//    ShowWindow(hwnd, SW_SHOW);
//
//    // â �޽��� ������Ʈ.
//    UpdateWindow(hwnd);
#pragma endregion main window create to windowclass

#pragma region
       // // â����.
   // Window window(
   //     1280, 800, 
   //     TEXT("Engine Demo"), 
   //     hInstance, WindowProc
   //);


   //// ������ ����.
   //Renderer renderer(window.Width(), window.Height(), window.Handle());

   // // �޽��� ó�� ����.
   // MSG msg = {};

   // // ����
   // while (msg.message != WM_QUIT)
   // {
   //     // â�� �޽����� ���� �� ����.
   //     if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
   //     {
   //         // �޽��� ����.
   //         TranslateMessage(&msg);

   //         // �޽��� ����.
   //         DispatchMessage(&msg);
   //     }
   //     // â�� �޽����� ���� �� �ٸ� �۾� ó��.
   //     else
   //     {
   //         // ���� ����.
   //         renderer.Draw();
   //     }
   // }
#pragma endregion beforeAllCode

    Engine engine(1280, 800, TEXT("Engine Demo"), hInstance);

    return (0);
}