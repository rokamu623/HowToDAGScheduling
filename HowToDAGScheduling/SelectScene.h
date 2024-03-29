﻿#pragma once
#include <Siv3D.hpp>
#include "SceneName.h"
#include "BGMManager.h"
#include "SEManager.h"
#include "DAGJsonPackage.h"
#include "SEManager.h"

// 各ステージの選択肢GUI
class Stage
{
private:
	FilePath _path;
	String _name;
	int _core_num;

	Point _pos;
	Quad _body;
	bool _over;
	Font _font;
	int _scroll;

	Triangle _up_tri;
	Triangle _down_tri;

public:
	Stage() {};
	Stage(FilePath path, Point pos);

	// クリック用当たり判定
	Quad body();
	void update();
	void draw() const;

	// 選ばれたステージの情報ファイルを返す
	FilePath path();
	// 選択したプロセッサコア数を返す
	int core_num(){ return _core_num; };
};

class SelectScene :public App::Scene
{
private:
	Array<Stage> _stages;

	Point _result_button_pos;
	Point _real_time_pos;

	bool _real_time_mode;
public:
	SelectScene(const InitData& init);

	void update() override;
	void draw() const override;
};

