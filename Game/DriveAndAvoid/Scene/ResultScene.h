#pragma once

#include"SceneBase.h"

class Resultscene : public SceneBase
{
private:
	int back_ground; //”wŒi‰æ‘œ
	int score; //ƒXƒRƒA
	int enemy_count[3]; //“G‚ÌƒJƒEƒ“ƒg
	int enemy_image[3]; //“G‰æ‘œ

public:
	ResultScene();
	virtual ~RankinginputScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;

private:
	void ReadResultData();
};