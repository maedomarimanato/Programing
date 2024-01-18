#pragma once

#include"SceneBase.h"
#include"../Object/RankingData.h"

class rankingInputScene : public SceneBase
{
private:
	int background_image; //�w�i�摜
	RankingData* ranking; //�����L���O���
	int score; //�X�R�A
	char name_num; //���O���͐�
	int cursor_x; //�J�[�\��x���W
	int cursor_y; //�J�[�\�������W

public:
	RankingInputScene();
	virtual~RankingInputScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids:
	virtual void Finalize() overrids;

	virtual eSeneType GetNowScene() const overrids;

private:
	//���O���͏���
	bool InputName();
};