﻿#pragma once

enum class SceneName
{
	Title, Select, Main, Processor, Result
};

struct GameData
{
	Optional<FilePath> path = none;
	int core_num = 3;
};

using App = SceneManager<SceneName, GameData>;
