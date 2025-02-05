#pragma once

// DirectX11 헤더.
#include <d3d11.h>
#include <dxgi.h>

#include "../Core/Type.h"

namespace Blue
{
	// 그래픽카드에서 처리하는 일 / 리소스 를 관리하는 클래스.
	// RHI(상용엔진들은 이런 표현을 많이 씀 Render Hardware Interface)
	class Renderer
	{
		public:
			Renderer(uint32 width, uint32 height, HWND window);
			~Renderer();

			// 그리기 함수.
			void Draw();
		private:
			// 리소스.
			// 장치류.
			ID3D11Device* device = nullptr;			// 리소스 생성 목적.
			ID3D11DeviceContext* context = nullptr;
			IDXGISwapChain* swapChain = nullptr;	// 프론트버퍼, 백버퍼.

			// 버퍼.
			ID3D11RenderTargetView* renderTargetView = nullptr;

			// 뷰포트.
			D3D11_VIEWPORT viewport;

			// @Temp: 임시.
			// 정점 버퍼 (정점 정보를 전달하는 데 사용함).
			ID3D11Buffer* vertexBuffer = nullptr;

			// 인덱스 버퍼 (정점을 조립할 때 정점의 순서를 전달).
			ID3D11Buffer* indexBuffer = nullptr;

			// 입력 레이아웃.
			ID3D11InputLayout* inputlayout = nullptr;

			// 쉐이더 객체.
			ID3D11VertexShader* verteShader = nullptr;
			ID3D11PixelShader* pixelShader = nullptr;

	};
}