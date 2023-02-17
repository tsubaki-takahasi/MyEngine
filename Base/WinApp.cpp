#include "WinApp.h"
LRESULT WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W����
	switch (msg)
	{
	case WM_DESTROY://�E�B���h�E���j�����ꂽ

		PostQuitMessage(0);// OS�ɑ΂��āA�A�v���̏I����`����
		return 0;

	}
	return DefWindowProc(hwnd, msg, wparam, lparam);//�W���̏������s��
}
void WinApp::Initialize()
{

	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;//�R�[���o�b�N�֐��̎w��
	w.lpszClassName = _T("DirectXTest");//�A�v���P�[�V�����N���X��(�K���ł����ł�)
	w.hInstance = GetModuleHandle(0);//�n���h���̎擾
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&w);//�A�v���P�[�V�����N���X(���������̍�邩���낵������OS�ɗ\������)
	
	RECT wrc = { 0,0,window_width, window_height };
	//�֐����g���ăE�B���h�E�̃T�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	hwnd = CreateWindow(w.lpszClassName,//�N���X���w��
	_T("DX12Test"),//�^�C�g���o�[�̕���
	WS_OVERLAPPEDWINDOW,//�^�C�g���o�[�Ƌ��E��������E�B���h�E
	CW_USEDEFAULT,//�\��x���W��OS�ɂ��C��
	CW_USEDEFAULT,//�\��y���W��OS�ɂ��C��
	wrc.right - wrc.left,//�E�B���h�E��
	wrc.bottom - wrc.top,//�E�B���h�E��
	nullptr,//�e�E�B���h�E�n���h��
	nullptr,//���j���[�n���h��
	w.hInstance,//�Ăяo���A�v���P�[�V�����n���h��
	nullptr);//�ǉ��p�����[�^�[

	ShowWindow(hwnd, SW_SHOW);

}

void WinApp::Update()
{

}

void WinApp::Finalize()
{
	//�E�B���h�E�N���X�̓o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);
}

bool WinApp::ProcessMessage()
{
	MSG msg{};
	//�E�B���h�E���b�Z�[�W����
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	if (msg.message == WM_QUIT)
	{
		return true;
	}

	return false;
}