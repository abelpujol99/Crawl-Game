#include "JsonLoader.h"

void JsonLoader::LoadPlayerFromJson(Player& player, std::string path) {
	std::ifstream* jsonReadFile = new std::ifstream(path, std::ifstream::binary);
	if (!jsonReadFile->fail()) {

		Json::Value jsonValue;
		*jsonReadFile >> jsonValue;
		jsonReadFile->close();
		player = *Player::Parse(jsonValue);
	}
}