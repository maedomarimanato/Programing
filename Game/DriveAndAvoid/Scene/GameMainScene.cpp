#include"GameMainScene.h"
#include"../Object/RankingDate.h"
#include"DxLib.h"
#include<math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL),
barrier_image(NULL),
mileage(0), player(nullptr),
enemy(nullptr)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

GameMainScene::~GameMainScene()
{

}

//����������
void GameMainScene::Initialize()
{
	//�����_�l����������
	ReadHighScore();

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/image/back.bmp");
	barrier_image = LoandGraph("Resource/image/barrier.pug");
	int result = LoandDivGraph("resource/image/car.bmp", 3, 3, 1, 63, 120,
		enemy_image);

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/image/back.bmp������܂���/n");
	}

	if (result == -1)
	{
		throw("Resource/image/barrier.pug������܂���/n");
	}

	//�I�u�W�F�N�g�̏�����
	player = new Player;
	enemy = new Enemy * [10];

	//�I�u�W�F�N�g�̏�����
	player -> Initialize();

	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}

}

//�X�V����
eSceneType GameMainScene::Update()
{
	//�v���C���[�̍X�V
	player->Update();

	//�ړ������̍X�V
	mileage += (int)player->getSpeed
	() + 5;

	//�G��������
	if (mileage / 20 % 100 == 0)
	{
		for (int i = ; i < 10; i++)
		{
			if (enemy[i] == nullptr)
			{
				int type = GetRand(3) % 3;
				enemy[i] = new Enemy(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
		}
	}

	//�G�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Udate(player->GetSpeed());

			//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
			if (enemy[i]->GetLoandion().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//�����蔻��̊m�F
			if (IsHitCheck(player, enemy[i]))
			{
				player->SetActive(false);
				player->DeceraseHp(-50.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	//�v���C���[�̔R�����̗͂�0�����Ȃ�A���U���g�ɓ]�ڂ���
	if (olayer->GetFuel() < 0.0f || player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw() const
{
	//�w�i�摜�̕`��
	DrawGraoh(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraoh(0, mileage % 480, back_ground, TRUE);

	//�G�̕`��
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//�v���C���[�̕`��
	player->Draw();

	//UI�̕`��
	player->Draw();

	//Ul�̕`��
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "�n�C�X�R�A");
	DrawFormatString(560,40,GetColor(255,255,255),"%08d",high_score):
	DrawFormatString(510, 80, GetColor(0, 0,0), "��������") :
		for(int i=0;i<3;i++)
		{
			DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE,
				FALSE);

			}
		}
	}
}