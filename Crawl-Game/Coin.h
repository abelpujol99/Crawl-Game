#pragma once
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include"DropLootable.h"

class DropLootable;

class Coin : public DropLootable {

private:

	int _points;

public:

	Coin();
	~Coin();
	int GetPoints();
	void Draw() override;
};