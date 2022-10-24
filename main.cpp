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

	//data.thongKe();
	/*NhanVienQuanLi a = (data.getNvQuanLi())[0];
	a.timKiemNV(data);*/
	Menu m;
	m.main_menu(data);

	return 0;
}
