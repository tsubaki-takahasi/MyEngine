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

//�֐��̃v���g�^�C�v�錾
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


	//�Q�[�����[�v
	while (true)
	{

		fps->FpsControlBegin();
		if (winApp->ProcessMessage())
		{
			//�Q�[�����[�v�𔲂���
			break;
		}
		//��������DirectX���t���[������


		//�`��O����
		dxCommon->preDraw();


		//�`��㏈��
		dxCommon->postDraw();


		fps->FpsControlEnd();
		//�����܂�DirectX���t���[������
	}
	//windowAPI�̏I������
	winApp->Finalize();
	//���͉��
	delete winApp;


	return 0;
}

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg) {
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂���,�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}