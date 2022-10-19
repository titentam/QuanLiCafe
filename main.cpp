#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>
#include<conio.h>
#include<Windows.h>


using namespace std;



int main() {
	\
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	Vector<DoUong> menu = data.getDoUong();
	
	NhanVienPhucVu nvpv = (data.getNvPhucVu())[0];
	NhanVienQuanLi nvql = (data.getNvQuanLi())[0];
	nvql.menuQuanLi(data);
	
	
	return 0;
}