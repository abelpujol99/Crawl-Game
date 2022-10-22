#pragma once

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_SPACE 32
#define KB_ESCAPE 27

#define KB_A 97
#define KB_B 98
#define KB_C 99
#define KB_D 100
#define KB_E 101
#define KB_F 102
#define KB_G 103
#define KB_H 104
#define KB_I 105
#define KB_J 106
#define KB_K 107
#define KB_L 108
#define KB_M 109
#define KB_N 110
#define KB_O 111
#define KB_P 112
#define KB_Q 113
#define KB_R 114
#define KB_S 115
#define KB_T 116
#define KB_U 117
#define KB_V 118
#define KB_W 119
#define KB_X 120
#define KB_Y 121
#define KB_Z 122

#define KB_0 48
#define KB_1 49
#define KB_2 50
#define KB_3 51
#define KB_4 52
#define KB_5 53
#define KB_6 54
#define KB_7 55
#define KB_8 56
#define KB_9 57

static class ConsoleControl {
public:
	enum ConsoleColor {
		BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
		DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
	};

	static void SetColor(ConsoleColor ForeColor = WHITE, ConsoleColor BackColor = BLACK);
	static void SetPosition(short int x, short int y);
	static void Clear();
	static void ClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor);

	static void Wait(unsigned long milisecons);

	static int ReadNextKey();
	static int WaitForReadNextKey();
};

