#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"

class GameMainScene : public SceneBase
{
private:
	int high_score; //�n�C�X�R�A
	int back_ground; //�w�i�摜
	int barrier_image; //�o���A�摜
	int miileage; //���s����
	int enemy_image[3];//�G�摜
	int enemy_count[3]; //�ʂ�߂����G�J�E���g
	Player* player; //�v���C���[
	Enemy** enemy; //�G

public:
	GameMainScene();
	virtual~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;

private:
	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	//�����蔻��
	bool IsHitCheck(Player* p, Enemy* p);
};

