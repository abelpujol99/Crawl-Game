#include "JsonSaver.h"

void JsonSaver::SaveToJson(Json::Value jsonValue, std::string path) {
	std::ofstream* jsonWriteFile = new std::ofstream(path, std::ifstream::binary);
	if (!jsonWriteFile->fail())
	{
		*jsonWriteFile << jsonValue;
		jsonWriteFile->close();
	}
}