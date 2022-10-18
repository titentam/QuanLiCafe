#pragma once
#include"Vector.cpp"
#include"NhanVienQuanLi.h"
#include"NhanVienPhucVu.h"
#include"DoUong.h"
#include<iostream>
#include<string>

#include<fstream>

using namespace std;
                 
class NhanVienQuanli;
class NhanVienPhucVu;
class DoUong;

class DuLieu
{
private:
	Vector<NhanVienQuanLi> nvql;
	Vector<NhanVienPhucVu> nvpv;
	Vector<DoUong> douong;
	Vector<Vector<Vector<int>>> doanhThu; // nam/thang/ngay
public:
	DuLieu();

	void docFileDsNhanVien();
	void docFileDsDoUong();
	Vector<DoUong>& getDoUong();
	Vector<NhanVienPhucVu>& getNvPhucVu();
	Vector<NhanVienQuanLi>& getNvQuanLi();
	void xuatFileDsNhanvien(ostream& out);
	void xuatFileDsDoUong(ostream& out);
	
};

