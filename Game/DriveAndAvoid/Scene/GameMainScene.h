#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"

class GameMainScene : public SceneBase
{
private:
	int high_score; //ハイスコア
	int back_ground; //背景画像
	int barrier_image; //バリア画像
	int miileage; //走行距離
	int enemy_image[3];//敵画像
	int enemy_count[3]; //通り過ぎた敵カウント
	Player* player; //プレイヤー
	Enemy** enemy; //敵

public:
	GameMainScene();
	virtual~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;

private:
	//ハイスコア読み込み処理
	void ReadHighScore();
	//当たり判定
	bool IsHitCheck(Player* p, Enemy* p);
};

