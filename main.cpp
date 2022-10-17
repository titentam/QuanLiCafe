#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>


using namespace std;

int main() {
	// hahahaha
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();

	data.xuatFileDsDoUong(cout);
	cout << endl;
	cout << "tamngu";
	data.xuatFileDsNhanvien(cout);
	return 0;
}