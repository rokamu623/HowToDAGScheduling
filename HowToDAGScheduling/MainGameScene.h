﻿#pragma once
#include <Siv3D.hpp>
#include "DAG.h"
#include "SchedGrid.h"
#include "Compiler.h"
#include "DAGJsonPackage.h"
#include "SceneName.h"
#include "BGMManager.h"
#include "SEManager.h"

class MainGameScene : public App::Scene
{
protected:
	DAG _dag;
	SchedGrid _grid;
	Compiler _compiler;

	bool _compile_flag;

	DrawableText _stage_title;

	Point _home_button_pos;

public:
	MainGameScene(const InitData& init);

	void update() override;
	void draw() const override;
};

class NormalGameScene : public MainGameScene
{
private:

public:
	NormalGameScene(const InitData& init) :MainGameScene(init) {};
};

class ProcessorGameScene : public MainGameScene
{
private:

public:
	ProcessorGameScene(const InitData& init) :MainGameScene(init) { Print << U"ok"; };
};
