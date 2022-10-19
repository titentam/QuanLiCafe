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
public:
	NhanVienPhucVu();
	NhanVienPhucVu(const string& maNv,
		const string& hoTen,
		const string& sdt,
		const string& TK,
		const string& MK,
		const float& hsl);
	void xemDsDoUong(DuLieu& data);
	void lamDoUong(DuLieu &data,const Vector<DoUong>& dsDoUong,const Vector<int>& sl);
	void xuatBill(ostream& out, const Vector<DoUong>& dsDoUong, const Vector<int>& sl);
	float getLuong(const int&);
	void menuPhucvu(DuLieu& data);
};

