﻿#pragma once
#include "CompileLog.h"
#include "Layout.h"

class DAG;
class DAGRealTime;


// スケジューリングの1コア1時間単位の枠
// グリッドの1マス
class Cell
{
private:
	int _core;
	int _time;

	Rect _body;
	bool _invalid;
	bool _assigned;

public:
	static Point CELL_SIZE;

	Cell() {};
	Cell(Point pos, Point offset);

	// 不正な配置をされているか（同じ時刻、コアに2ノード以上配置されているか）
	bool invalid();
	// 配置されたとき・外れたときの処理
	void assign(bool input);

	void draw() const;

	int core() { return _core; };
	int time() { return _time; };
	Rect body() { return _body; };
};


// スケジューリング、グリッド
class SchedGrid
{
private:
	// Cell クラスの2次元配列
	Grid<Cell> _cells;
	Rect _field;
	Rect _grid_rect;
	int _core_num;

	Line _x_axis, _y_axis;
	Array<Line> _y_sub_axises;

	Font _font;

public:
	SchedGrid();
	SchedGrid(int core_num, int time_limit);

	// コンパイル（結果計算）
	CompileLog compile(DAG dag);
	// コンパイル（結果計算）
	CompileLog compile(DAGRealTime dag);

	void draw() const;
	void draw_field() const { _field.draw(LAYOUT::FIELD_COLOR); };

	Grid<Cell> cells();
	int core_num() { return _core_num; };
};

