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
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	Menu m;
	m.wellcome();
	m.loadingbar();
	//system("pause");
	m.main_menu(data);
	return 0;
}
