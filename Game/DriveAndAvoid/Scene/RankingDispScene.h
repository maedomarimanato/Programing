#pragma once

#include"SceneBase.h"
#include"../Object/RankingData.h"

class RankingDispScene : public SceneBase
{
private:

private:
	int background_image; //�w�i�摜
	RankingData* ranking; //�����L���O���

public:
	RankingDispScene();
	virtual~RankingDispScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;
};
