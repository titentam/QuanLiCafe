#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>


using namespace std;

int main() {
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();

	data.xuatFileDsDoUong(cout);
	cout << endl;
	data.xuatFileDsNhanvien(cout);
	return 0;
}