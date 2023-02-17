#include "gameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initalize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	//input_ = Input::GetInstance();
	camera_ = new Camera(WinApp::window_width, WinApp::window_height);
	// �J���������_���Z�b�g
	camera_->SetTarget({ 0, 1, 0 });
	// 3D�I�u�W�F�N�g�ɃJ�������Z�b�g
	Object3d::SetCamera(camera_);
	//���C�g����
	light_ = Light::Create();
	//���C�g�F��ݒ�
	light_->SetLightColor({ 1,1,1 });
	//3D�I�u�W�F�N�g�Ƀ��C�g���Z�b�g
	Object3d::SetLight(light_);


	Sprite::LoadTexture(1, L"Resources/kuribo-.jpg");
	Sprite::LoadTexture(2, L"Resources/mario.jpg");
	sprite_ = Sprite::Create(1, { 10.0f,0.0f });

	
	sprite2_ = Sprite::Create(2, { 300.0f,500.0f });
	sprite2_->SetIsFlipY(true);

	modelEnemy_ = Model::CreateFromOBJ("enemy");
	objEnemy_ = Object3d::Create();
	
	objEnemy_->SetModel(modelEnemy_);
	objEnemy_->SetColor({ 1,1,1,0.7f });
	//modelskydome_ = Model::CreateFromOBJ("sphere");
	//skydome_ = Object3d::Create();
	////���f�����Z�b�g
	//skydome_->SetModel(modelskydome_);
	//skydome_->SetPosition({ -5,0,-10 });



	//modelPlayer_ = Model::CreateFromOBJ("sphere");
	//player_ = Object3d::Create();
	////���f�����Z�b�g
	//player_->SetModel(modelPlayer_);
	//player_->SetPosition({ 6,0,0 });

	//modelGround_ = Model::CreateFromOBJ("Wall");
	//ground_ = Object3d::Create();
	//ground_->SetModel(modelGround_);
	//ground_->SetPosition({0,-5,0});
	//ground_->SetScale({ 1,0.1f,0.1f });

	//changeSphere = Model::CreateFromOBJ("skydome");
	//
	////���̍��W���v���C���[�ɒu������
	//sphere.center = XMVectorSet(0,5,0,1);
	//sphere.radius = 1.0f;

	////���ʂ̍��W�̒u������
	//plane.normal = XMVectorSet(0,1,0,0);
	//plane.distance = 0.0f;
}

void GameScene::Update()
{
	/*moveY = XMVectorSet(0,0.1f,0,0);
	if (isDown == true)
	{
		Down();
	}
	if (isUp == true)
	{
		Up();
	}

	bool isHit = Collision::CheckSphere2Plane(sphere, plane);
	if (isHit)
	{
		player_->SetColor({1,0,0,1});
	}
	else
	{
		player_->SetColor({1,1,1,1});
	}*/
	
	camera_->Update();

	objEnemy_->Update();

	light_->Update();
}

void GameScene::Draw()
{
#pragma region �w�i�X�v���C�g�`��
	// �w�i�X�v���C�g�`��O����
	Sprite::PreDraw(dxCommon_->GetCommandList());
	// �w�i�X�v���C�g�`��

	
	/// <summary>
	/// �����ɔw�i�X�v���C�g�̕`�揈����ǉ��ł���
	/// </summary>

	// �X�v���C�g�`��㏈��
	Sprite::PostDraw();
#pragma endregion

#pragma region 3D�I�u�W�F�N�g�`��
	//// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(dxCommon_->GetCommandList());

	//// 3D�I�u�W�F�N�g�̕`��
	objEnemy_->Draw();

	///// <summary>
	///// ������3D�I�u�W�F�N�g�̕`�揈����ǉ��ł���
	///// </summary>

	//// 3D�I�u�W�F�N�g�`��㏈��
	Object3d::PostDraw();
#pragma endregion

#pragma region �O�i�X�v���C�g�`��
	// �O�i�X�v���C�g�`��O����
	Sprite::PreDraw(dxCommon_->GetCommandList());

	/// <summary>
	/// �����ɑO�i�X�v���C�g�̕`�揈����ǉ��ł���
	/// </summary>
	/*sprite_->Draw();
	sprite2_->Draw();*/
	//
	// �X�v���C�g�`��㏈��
	Sprite::PostDraw();

#pragma endregion
}


