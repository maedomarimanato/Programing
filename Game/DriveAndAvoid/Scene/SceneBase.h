#pragma once

//�V�[�����
enemy eSceneType
{
	E_TITLE,
	E_MAIN,
	E_HELP,
	E_RANKING_DISP,
	E_RANKING_INPUT,
	E_RESULT,
	E_END
};

//���V�[���N���X
class SceneBase
{
public:
	SceneBase(){}
	virtual~SceneBase(){}

	//����������
	virtual void Initialize(){}
	//�X�V����
	virtal eSceneType Update()
	{
		return GetNowScene();
	}
	//�`�揈��
	virtal void Draw() const{}
	//�I��������
	virtal void Finalize(){}

	//���݂̃V�[�������擾
	virtal eSceneType getNpwScene() const = 0;
};