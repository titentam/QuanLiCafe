#pragma once
#include"NhanVien.h"
#include<string>
#include"DoUong.h"
#include"DuLieu.h"
#include<fstream>
#include<ctime>

class DuLieu;
class DoUong;
class NhanVienPhucVu: public NhanVien
{
	Vector<DoUong> dsDoUong;
	Vector<int> sl;
public:
	NhanVienPhucVu();
	NhanVienPhucVu(const string& maNv,
		const string& hoTen,
		const string& sdt,
		const string& TK,
		const string& MK,
		const float& hsl);
	void lamDoUong(DuLieu &data,const int&,const int&);
	void xuatBill(ostream& out);
	float getLuong(const int&);
};

