#include "DoHoa.h"

void DoHoa::textColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

void DoHoa::gotoxy(int x, int y)
{
	HANDLE hConoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConoleOutput, Cursor_an_Pos);
}
