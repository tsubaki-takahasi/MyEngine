#include "DirectXCommon.h"
#include "WinApp.h"
#include "FPS.h"
void DebugOutputFormatString(const char* format, ...) {
#ifdef _DEBUG
	va_list valist;
	va_start(valist, format);
	vprintf(format, valist);
	va_end(valist);
#endif
}

//関数のプロトタイプ宣言
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	OutputDebugStringA("Hello DirectX!!\n");
	//FPS
	FPS* fps = new FPS;
	fps->SetFrameRate(60);

	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;

	winApp = new WinApp();
	winApp->Initialize();


	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(winApp);


	//ゲームループ
	while (true)
	{

		fps->FpsControlBegin();
		if (winApp->ProcessMessage())
		{
			//ゲームループを抜ける
			break;
		}
		//ここからDirectX毎フレーム処理


		//描画前処理
		dxCommon->preDraw();


		//描画後処理
		dxCommon->postDraw();


		fps->FpsControlEnd();
		//ここまでDirectX毎フレーム処理
	}
	//windowAPIの終了処理
	winApp->Finalize();
	//入力解放
	delete winApp;


	return 0;
}

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対して,アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}