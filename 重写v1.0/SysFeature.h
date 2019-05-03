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
	/* ���ع�� */
	bool hide();
	/* ��ʾ��� */
	bool show();
	/* ���ù��λ�� */
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
	/* ���ñ��� */
	bool title(const char *str);
	/* ���ع����� */
	bool HideScrollBar();
	/* ȫ���� */
	bool full();
	/* ���ڻ� */
	bool window();
};

extern _Screen Screen;