#pragma once
#include<string>
#include<fstream>
#include<conio.h>
#include"DuLieu.h"
#include<Windows.h>
using namespace std;

class Menu
{
public:
	void br(int line);
	void pre(int tab);
	void span(int space);
	void loadingbar();
	void wellcome();
	void menu_quanli();
	void menu_phucvu();
	string nhapmk();
	void danhNhap(string& tk, string& mk);
	int checkTK(DuLieu& data, const string& tk, const string& mk, const int& opt);
	void main_menu(DuLieu& data);
};

