#pragma once

#include"SceneBase.h"

class HelpScene : public SceneBase
{
private:
	int background_image;//”wŒi‰æ‘œ

public:
	HelpScene();
	virtual~HelpScene();

	virtual void Initialize() overrids;
	virtual eSceneType Update() overrids;
	virtual void Draw() const overrids;
	virtual void Finalize() overrids;

	virtual eSceneType GetNowScene() const overrids;
};