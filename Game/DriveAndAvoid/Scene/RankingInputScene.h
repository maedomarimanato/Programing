#pragma once

#include"SceneBase.h"
#include"../Object/RankingData.h"

class rankingInputScene : public SceneBase
{
private:
	int background_image; //背景画像
	RankingData* ranking; //ランキング情報
	int score; //スコア
	char name_num; //名前入力数
	int cursor_x; //カーソルx座標
	int cursor_y; //カーソルｙ座標

public:
	RankingInputScene();
	virtual~RankingInputScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override:
	virtual void Finalize() override;

	virtual eSeneType GetNowScene() const override;

private:
	//名前入力処理
	bool InputName();
};