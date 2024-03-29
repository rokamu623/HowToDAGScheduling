﻿# include <Siv3D.hpp> // OpenSiv3D v0.6.6
# include "TitleScene.h"
# include "SelectScene.h"
# include "MainGameScene.h"
# include "ResultScene.h"
# include "SceneName.h"
# include "BGMManager.h"
# include "SEManager.h"

void Main()
{
	Scene::SetBackground(Palette::Lightgreen);
	Window::SetTitle(U"How To DAG Scheduling ?");

	// BGM・SEの初期化（ファイル読み込み）
	BGMManager::load();
	SEManager::load();

	// 各種シーンを登録
	// changeScene(SceneName::Hoge) でそのシーンに遷移
	App sceneMgr;
	sceneMgr.add<TitleScene>(SceneName::Title);
	sceneMgr.add<SelectScene>(SceneName::Select);
	sceneMgr.add<NormalGameScene>(SceneName::Main);
	sceneMgr.add<RealTimeGameScene>(SceneName::RealTime);
	sceneMgr.add<ResultScene>(SceneName::Result);

	while (System::Update())
	{
		// App::Scene を継承したクラスの .update() と .draw() を毎フレーム実行
		sceneMgr.update();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要です。
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/tutorial/
//
// Tutorial
// https://siv3d.github.io/tutorial/tutorial/
//
// Siv3D コミュニティへの参加（Discord などで気軽に質問や交流, 最新情報の入手ができます）
// https://siv3d.github.io/ja-jp/community/community/
//
// Siv3D User Community
// https://siv3d.github.io/community/community/
//
// 新機能の提案やバグの報告 | Feedback
// https://siv3d.github.io/ja-jp/develop/report/
//
// Sponsoring Siv3D
// https://github.com/sponsors/Reputeless
//
