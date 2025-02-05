#include <Windows.h>

#include "Core/Window.h"
#include "Render/Renderer.h"
#include "Core/Engine.h"

// 창에 관련된 메시지를 처리하는 콜백함수,
LRESULT CALLBACK WindowProc(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
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

using namespace Blue;

// 창 모드 할 때 메인 함수(Entry Point)
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,           // 프로그램의 주소, 프로그램 전체의 인스턴스
    _In_opt_ HINSTANCE hPrevInstance,   // 이제는 안씀. 호환 유지를 위해 필요(옛날 window)
    _In_ LPSTR lpCmdLine,               // 
    _In_ int nShowCmd                   //
)
{
#pragma region 
//    // 창 생성.
//    // Register the window class.
//
//    // 창에 사용할 클래스 이름.
//    const wchar_t* className = TEXT("Sample Window Class");
//
//    // 창 생성에 필요한 설정 구조체.
//    WNDCLASS wc = { };
//
//    // 메시지 처리를 위한 콜백 전달.
//    wc.lpfnWndProc = WindowProc;
//
//    // 프로그램 주소전달.
//    wc.hInstance = hInstance;
//
//    // 창 생성에 사용할 클래스 이름 전달.
//    wc.lpszClassName = className;
//
//    // 클래스 등록.
//    if (!RegisterClass(&wc))
//    {
//        // 오류 메시지 확인.
//        //auto error = GetLastError();
//
//        // 메시지 출력.
//        // #1 - 출력창(Output) 이용.
//        OutputDebugStringA("Failed to register a window class\n");
//
//
//        // #2 - 메시지 박스 이용.
//        MessageBoxA(nullptr, "Failed to register a window class", "오/류", /MB_OK);
//
//        // 종단점 설정.
//        __debugbreak();
//    }
//
//    // 창의 가로 크기.
//    unsigned int width = 1280;
//    unsigned int height = 800;
//    // 타이틀바와 같은 것들이 화면을 차지하고 있습니다.
//    // 이런것들을 고려해서 화면 크기를 조정할 수 있습니다.
//    // fullhd? 기존 프레임(이미지 한장) 패기하고 다시 생성.
//    // 창크기에 따라 달라지기 때문.
//
//    // 화면 가운데 위치 설정.
//    unsigned int positionX = ((GetSystemMetrics(SM_CXSCREEN) - /width) / /2);
//    unsigned int positionY = ((GetSystemMetrics(SM_CYSCREEN) - /height) / /2);
//
//    // 창 크기 조정.
//    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>//(height) };
//    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
//
//    // 창 크기 재설정.
//    unsigned int windowWidth = rect.right - rect.left;
//    unsigned int windowHeight = rect.bottom - rect.top;
//    // 이렇게 하면 실제적으로 사용하는 공간이 내가 설정한 크기가 됩니다.
//    HWND hwnd = CreateWindow(
//        className,                          // Window class
//        TEXT("Blue Engine Demo"),           // Window text
//        WS_OVERLAPPEDWINDOW,                // Window style
//        // Size and position
//        positionX,                      // x
//        positionY,                      // y
//        windowWidth,                          // 너비
//        windowHeight,                         // 높이
//        nullptr,        // Parent window    // 창 안에 창이 가능
//        nullptr,        // Menu             \// 메뉴도 창안에 있음.
//        hInstance,      // Instance handle
//        nullptr          // Additional application data
//    );
//
//    if (hwnd == nullptr)
//    {
//        // #1 - 출력창(Output) 이용.
//        OutputDebugStringA("Failed to create a window class\n");
//
//
//        // #2 - 메시지 박스 이용.
//        MessageBoxA(nullptr, "Failed to create a window class", "오류", //MB_OK);
//
//        // 종단점 설정.
//        __debugbreak();
//    }
//
//    // 창 보이기.
//    ShowWindow(hwnd, SW_SHOW);
//
//    // 창 메시지 업데이트.
//    UpdateWindow(hwnd);
#pragma endregion main window create to windowclass

#pragma region
       // // 창생성.
   // Window window(
   //     1280, 800, 
   //     TEXT("Engine Demo"), 
   //     hInstance, WindowProc
   //);


   //// 렌더러 생성.
   //Renderer renderer(window.Width(), window.Height(), window.Handle());

   // // 메시지 처리 루프.
   // MSG msg = {};

   // // 루프
   // while (msg.message != WM_QUIT)
   // {
   //     // 창에 메시지가 들어올 떄 실행.
   //     if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
   //     {
   //         // 메시지 번역.
   //         TranslateMessage(&msg);

   //         // 메시지 전달.
   //         DispatchMessage(&msg);
   //     }
   //     // 창에 메시지가 없을 때 다른 작업 처리.
   //     else
   //     {
   //         // 엔진 루프.
   //         renderer.Draw();
   //     }
   // }
#pragma endregion beforeAllCode

    Engine engine(1280, 800, TEXT("Engine Demo"), hInstance);

    return (0);
}