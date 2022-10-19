#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>
#include<conio.h>
#include<Windows.h>



using namespace std;

int main() {
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	//data.xuatFileDsDoUong(cout);
	cout << endl;

	Vector<DoUong> &menu = data.getDoUong();
	
	NhanVienPhucVu tam = (data.getNvPhucVu())[0];
	Vector<DoUong> dsdouong;
	Vector<int> sl;
	// 12
	// tim do uong co ma 12 -> them dsdouong , them -> soluong
	dsdouong.push_back(menu[2]);
	sl.push_back(70);

	dsdouong.push_back(menu[3]);
	sl.push_back(80);

	dsdouong.push_back(menu[5]);
	sl.push_back(50);

	tam.lamDoUong(data, dsdouong, sl);
	tam.xuatBill(cout, dsdouong, sl);
	//data.xuatFileDsDoUong(cout);
	/*ofstream f;
	string t = "TAM\\ti\\tamtentoi.txt";
	f.open(t, ios::out);
	tam.xuatBill(f, dsdouong, sl);
	f.close();*/

	

	return 0;
}