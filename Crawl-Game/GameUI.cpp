#include "GameUI.h"
using namespace std;

#define GUI_POSITION_X 12
#define GUI_POSITION_Y 1

void GameUI::Draw(Player* player, int _posX)
{
	int posX = _posX + GUI_POSITION_X;
	int posY = GUI_POSITION_Y;

	ConsoleControl::SetPosition(posX, posY);
	cout << "Coins: " << player->GetInventory().GetCoins() << "       ";
	
	ConsoleControl::SetPosition(posX, posY + 1);
	cout << "Health: " << player->GetHealth() << "       ";
	;
	ConsoleControl::SetPosition(posX, posY + 2);
	cout << "Potions: " << player->GetInventory().GetPotionAmount() << "       ";

	ConsoleControl::SetPosition(posX, posY + 3);
	cout << "Weapon: " << player->GetCurrentWeapon().GetName() << "       ";

	ConsoleControl::SetPosition(posX, posY + 6);
	cout << "WASD: Move/Attack";

	ConsoleControl::SetPosition(posX, posY + 7);
	cout << "E: Heal";

	ConsoleControl::SetPosition(posX, posY + 8);
	cout << "Q: Swap Weapon";
}
