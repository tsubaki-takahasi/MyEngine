#pragma once
#include "DirectXCommon.h"

#include "Sprite.h"


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

	
};