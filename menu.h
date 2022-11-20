
#pragma once
#include<string>
#include<fstream>
#include<conio.h>
#include"DuLieu.h"
#include<Windows.h>
#include"DoHoa.h"
#include <limits>
using namespace std;

class Menu
{
public:
	static void ignoreLine();
	void br(int line);
	void pre(int tab);
	void span(int space);
	void loadingbar();
	void wellcome();
	void menu_quanli();
	void menu_quanliNV();
	void menu_quanliDoUong();
	void menu_phucvu();
	string nhapmk();
	void danhNhap(string& tk, string& mk);
	int checkTK(DuLieu& data, const string& tk, const string& mk, const int& opt);
	void main_menu(DuLieu& data);
	void menu_thongke();
	static int getInt();
	static float getFloat();
	static char getChar();
};

