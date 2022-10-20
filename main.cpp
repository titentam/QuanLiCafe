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
	Menu a;
	//a.loadingbar();
	a.main_menu();
	//a.nhapmk();
	//NhanVienPhucVu nvpv = (data.getNvPhucVu())[0];
	//NhanVienQuanLi nvql = (data.getNvQuanLi())[0];
	//Vector<DoUong> menu = data.getDoUong();
	//
	//
	//
	//
	////nvql.menuQuanLi(data);
	//nvpv.menuPhucvu(data);
	//

	return 0;
}
