#pragma once

#include"SceneBase.h"

class HelpScene : public Scene
{
private:
	int backraound_image;//”wŒi‰æ‘œ

public:
	HelpScene();
	virtual~HelpScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;
};