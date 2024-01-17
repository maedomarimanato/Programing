#pragma once

#include"SceneBase.h"
#include"../Object/RankingData.h"

class RankingDispScene : public SceneBase
{
private:

private:
	int background_image; //”wŒi‰æ‘œ
	RankingData* ranking; //ƒ‰ƒ“ƒLƒ“ƒOî•ñ

public:
	RankingDispScene();
	virtual~RankingDispScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;
};
