#pragma once

#include"SceneBase.h"

class Resultscene : public SceneBase
{
private:
	int back_ground; //�w�i�摜
	int score; //�X�R�A
	int enemy_count[3]; //�G�̃J�E���g
	int enemy_image[3]; //�G�摜

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