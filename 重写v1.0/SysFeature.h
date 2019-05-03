#pragma once
#include<Windows.h>

//****************************************
//****************************************

class _Cursor {
private:
	COORD coord;
	CONSOLE_CURSOR_INFO CursorInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	/* 隐藏光标 */
	bool hide();
	/* 显示光标 */
	bool show();
	/* 设置光标位置 */
	bool set(short x, short y);
};

extern _Cursor Cursor;

//****************************************
//****************************************

class _Screen {
private:
	HWND hwnd;
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
	SMALL_RECT rect;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	/* 设置标题 */
	bool title(const char *str);
	/* 隐藏滚动条 */
	bool HideScrollBar();
	/* 全屏化 */
	bool full();
	/* 窗口化 */
	bool window();
};

extern _Screen Screen;