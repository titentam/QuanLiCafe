#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>


using namespace std;

int main() {
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	

	NhanVienQuanLi nvql;
	nvql = (data.getNvQuanLi())[0];

	nvql.xemDsNV(data);
	
	nvql.themNV(data, { "01asdad","Tam Ten Toi","8123712738127","tamcute","12312h",2 });
	cout << endl;
	nvql.xemDsNV(data);
	
	nvql.xemDsDoUong(data);
	DoUong ncdua(1, "Nuoc dua", 10000, 100, "Nuoc trai cay");
	nvql.themMon(data, ncdua);
	cout << endl;
	cout << "tamngu";
	data.xuatFileDsNhanvien(cout);
	return 0;
}