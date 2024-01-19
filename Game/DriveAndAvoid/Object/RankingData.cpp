#include"RankingData.h"
#include<stdio.h>
#include<string.h>

RankingData::RankingData()
{
	for (int i = 0; i < 6; i++)
	{
		score[i] = NULL;
		rank[i] = NULL;
		for (int j = 0; j < 15; j++)
		{
			name[i][j] = '/0';
		}
	}

}

RankingData::~RankingData()
{

}

//初期化処理
void RankingData::Initialize()
{
	//ランキングデータの読み込み
	FILE* fp = nullptr;

	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/ranking_date.csv", "r");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/ranking_date.csvが開けませんでした/n");
	}

	//対象ファイルから読み込む
	for (int i = 0; i < 5; i++)
	{
		fscanf_s(fp, "%6d,%2d,%[^,],/n", &score[i], &rank[i], name[i], 15);
	}

	//ファイルクローズ
	fclose(fp);

	//末尾データの設定
	score[5] = 0;
	rank[5] = 0;
	name[5][0] = '/n';
}

//終了処理
void RankingData::Finalize()
{

}

//データ設定処理
void RankingData::SetRankingData(int score, const char* name)
{
	this->score[5] = score;
	strcpy_s(this->name[5], name);

	SortData();
}

//スコア取得処理
int RankingData::GetScore(int value) const
{
	return score[value];
}

//ランク取得処理
int RankingData::GetRank(int value) const
{
	return rank[value];
}

//名前取得処理
const char* RankingData::GetName(int value) const
{
	return name[value];
}

//データ入れ替え処理
void RankingData::SortData()
{
	//選択法ソートを使用し、降順で入れ替える
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] <= score[j])
			{
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;

				char but[15] = {};
				strcpy_s(but, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], but);
			}
		}
	}

	//順位を整列させる
	for (int i = 0; i < 5; i++)
	{
		rank[i] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] > score[j])
			{
				rank[j]++;
			}
		}
	}

	//ランキングデータの書き込み
	FILE* fp = nullptr;

	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/ranking_date.csv", "w");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/ranking_date.csvが開けませんでした/n");
	}

	//対象ファイルに書き込み
	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d,%d,%s,/n", score[i], rank[i], name[i]);
	}

	//ファイルクローズ
	fclose(fp);
}

