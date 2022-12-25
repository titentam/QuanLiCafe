#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include"menu.h"

using namespace std;

int main() {
	DuLieu data;
	Menu a;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	Menu m;
	m.wellcome();
	a.br(1);
	a.pre(10);
	m.main_menu(data);
	
	
	return 0;
}
