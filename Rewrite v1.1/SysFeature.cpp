#include"SysFeature.h"

bool _Cursor::hide() {
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool _Cursor::show() {
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = true;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool _Cursor::set(short x, short y) {
	coord = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

_Cursor Cursor;

bool _Screen::title(const char *str) {
	return SetConsoleTitle(LPCSTR(str));
}

bool _Screen::HideScrollBar() {
	GetConsoleScreenBufferInfo(handle, &ScreenBufferInfo);
	rect = ScreenBufferInfo.srWindow;
	coord = { rect.Right + 1,rect.Bottom + 1 };
	//SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rect);
	return SetConsoleScreenBufferSize(handle, coord);
}

bool _Screen::full() {
	coord = { 0,0 };
	return SetConsoleDisplayMode(handle, CONSOLE_FULLSCREEN_MODE, &coord);
}

bool _Screen::window() {
	coord = { 0,0 };
	return SetConsoleDisplayMode(handle, CONSOLE_WINDOWED_MODE, &coord);
}

_Screen Screen;