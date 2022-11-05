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
	NhanVienQuanLi a = (data.getNvQuanLi())[0]; 
	a.menuQuanLi(data);
	return 0;
}
