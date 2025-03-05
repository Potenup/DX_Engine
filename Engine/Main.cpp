#include "Core/Engine.h"
#include <iostream>

//#include "Math/Vector2.h"

using namespace Blue;

// â ���� �� �� ���� �Լ�(Entry Point).
//int WINAPI WinMain(
//    _In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPSTR lpCmdLine,
//    _In_ int nShowCmd)
//{
//    // ���� ���� �� ����.
//    Engine engine(1280, 800, TEXT("Engine Demo"), hInstance);
//    engine.Run();
//
//    return 0;
//}

#include "Render/Texture.h"
#include "Core/Common.h"
#include <typeinfo>
#include <Shader/Shader.h>
#include <Shader/TextureMappingShader.h>

//template<typename T, typename std::enable_if<std::is_base_of<Shader, T>::value>::type* = nullptr>
//void TestClass()
//{
//	std::boolalpha(std::cout);
//	std::cout << typeid(T).name() << std::endl;
//	std::cout << std::is_base_of<Shader, T>::value << std::endl;
//}

int main()
{

	//TestClass<Engine>(); // ������ ������ ���� ������ �Լ�,
	//Texture texture("T_coord.png"); //text �ڵ�
	Engine engine(1280, 800, TEXT("Engine Demo"), GetModuleHandle(nullptr));
	engine.Run();
}
