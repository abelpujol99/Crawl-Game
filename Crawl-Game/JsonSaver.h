#pragma once
#include "json/json.h"
#include <fstream>
#include <iostream>
class JsonSaver
{
public:
	void SaveToJson(Json::Value jsonValue, std::string path);
};

