#pragma once
#include <iostream>
#include "MapElement.h"

class EmptyBox : public MapElement {

public:

	EmptyBox(Coordinates coordinates);
	void Draw() override;
};