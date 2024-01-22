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


//初期化処理
void ResultScene::Initialize()
{
	//画像の読み込み
	back_ground = LoadGraph("resource/image/back.bmp");
	int result = LoadDivGraph("Resource/image/car.bmp", 3, 3, 1, 63, 120,
		enemy_image);

	//エラーチェック
	if (back_ground == -1)
	{
		throw("Resource/image/back.bmpがありません/n");
	}
	if (result == -1)
	{
		throw("resource/image/csv.bmpaがありません/n");
	}

	//ゲーム結果の読み込み
	ReadresultData();
}

//更新処理
eSceneType ResultScene::Update()
{
	//Bボタンでランキングに遷移する
	if (InputControl::getButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_RANKING_INPUT;
	}

	return GetNowScene();
}

//描画処理
void resultScene::Draw() const
{
	//背景画像を描画
	Drawgraph(0, 0, back_ground, TRUE);

	//スコア等表示領域
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE;
	DrawBox(150, 150, 490, 330, getColor(0, 0, 0), FALSE);

	DrawBox(500), 0, 640, 480, getColor(0, 153, 0), TRUE;

	SetFontSize(20);
	DrawString(220, 170, "ゲームオーバー", getColor(204, 0, 0));
	SetFontSize(16);
	drawString(180, 200, "走行距離", GetColor(0, 0, 0));
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(230, 230 + (i * 20), 0.3f, DX_PI_F / 2, enemy_image[i],
			TRUE);
		DrawFormatString(260, 222 + (i * 21), getColor(255, 255, 255), "%6d x%4d=%6d")
			enemy_count[i], (i + 1) * 50, (i + 1) * 50 * enemy_count[i]);
	}
	drawString(180, 290, "スコア", getColor(0, 0, 0));
	drawFormatString(180, 290, 0xFFFFFF, "=%6d", score);
}

//終了時処理
void ResultScene::Finalize()
{
	//読み込んだ画像を削除
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(enemy_image[i]);
	}
}

//リザルトデータの読み込み
void ResultScene::ReadResultData()
{
	//ファイルオープン
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "resource/dat/result_data.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result_data.csvが読み込めません/n");
	}

	//結果を読み込む
	fxanf_s(fp, "%6d,/n", &score);

	//避けた数と得点を取得
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%6d/n", &enemy_count[i]);
	}

	//ファイルクローズ
	fclose(fp);
}

