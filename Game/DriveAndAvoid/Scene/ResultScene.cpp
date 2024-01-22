#include"ResultScene.h"
#include"../Object/RankingData.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

ResultScene::ResultScene() : back_ground(NULL), score(0)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

ResultScene::~ResultScene()
{

}


//����������
void ResultScene::Initialize()
{
	//�摜�̓ǂݍ���
	back_ground = LoadGraph("resource/image/back.bmp");
	int result = LoadDivGraph("Resource/image/car.bmp", 3, 3, 1, 63, 120,
		enemy_image);

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/image/back.bmp������܂���/n");
	}
	if (result == -1)
	{
		throw("resource/image/csv.bmpa������܂���/n");
	}

	//�Q�[�����ʂ̓ǂݍ���
	ReadresultData();
}

//�X�V����
eSceneType ResultScene::Update()
{
	//B�{�^���Ń����L���O�ɑJ�ڂ���
	if (InputControl::getButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_RANKING_INPUT;
	}

	return GetNowScene();
}

//�`�揈��
void resultScene::Draw() const
{
	//�w�i�摜��`��
	Drawgraph(0, 0, back_ground, TRUE);

	//�X�R�A���\���̈�
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE;
	DrawBox(150, 150, 490, 330, getColor(0, 0, 0), FALSE);

	DrawBox(500), 0, 640, 480, getColor(0, 153, 0), TRUE;

	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", getColor(204, 0, 0));
	SetFontSize(16);
	drawString(180, 200, "���s����", GetColor(0, 0, 0));
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(230, 230 + (i * 20), 0.3f, DX_PI_F / 2, enemy_image[i],
			TRUE);
		DrawFormatString(260, 222 + (i * 21), getColor(255, 255, 255), "%6d x%4d=%6d")
			enemy_count[i], (i + 1) * 50, (i + 1) * 50 * enemy_count[i]);
	}
	drawString(180, 290, "�X�R�A", getColor(0, 0, 0));
	drawFormatString(180, 290, 0xFFFFFF, "=%6d", score);
}

//�I��������
void ResultScene::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(enemy_image[i]);
	}
}

//���U���g�f�[�^�̓ǂݍ���
void ResultScene::ReadResultData()
{
	//�t�@�C���I�[�v��
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "resource/dat/result_data.csv", "r");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���ǂݍ��߂܂���/n");
	}

	//���ʂ�ǂݍ���
	fxanf_s(fp, "%6d,/n", &score);

	//���������Ɠ��_���擾
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%6d/n", &enemy_count[i]);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}

