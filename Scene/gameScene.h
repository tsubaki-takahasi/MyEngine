#pragma once
#include "DirectXCommon.h"

#include "Sprite.h"

#include "Camera.h"
#include "Light.h"
#include "Model.h"
#include "Object3d.h"

class GameScene
{

public:

	GameScene();
	~GameScene();

	void Initalize();

	void Update();

	void Draw();

	

private:
	DirectXCommon* dxCommon_ = nullptr;

	Sprite* sprite_ = nullptr;
	Sprite* sprite2_ = nullptr;


	Camera* camera_ = nullptr;
	Light* light_ = nullptr;

	Model* modelEnemy_ = nullptr;
	Object3d* objEnemy_ = nullptr;
};