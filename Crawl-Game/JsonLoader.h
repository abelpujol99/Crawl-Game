#pragma once
#include "json/json.h"
#include "Player.h"
#include <iostream>
#include <fstream>
class JsonLoader {
public:
	void LoadPlayerFromJson(Player& player, std::string path);
};