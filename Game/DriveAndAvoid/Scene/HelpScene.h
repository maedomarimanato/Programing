#pragma once

#include"SceneBase.h"

class HelpScene : public Scene
{
private:
	int backraound_image;//�w�i�摜

public:
	HelpScene();
	virtual~HelpScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;
};