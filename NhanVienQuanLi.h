#pragma once
#include "NhanVien.h"
#include"NhanVienPhucVu.h"
#include"DoUong.h"
#include"DuLieu.h"

class DuLieu;
class NhanVienPhucVu;
class NhanVienQuanLi : public NhanVien
{
public:
	// quan li nhan vien
	NhanVienQuanLi();
	NhanVienQuanLi(const string& maNv,const string& hoTen,const string& sdt,
		const string& TK,const string& MK, const float& hsl);
	NhanVienQuanLi(const string& maNv, const string& hoTen, const string& sdt,
		const string& MK, const float& hsl);
	void xemDsNV (DuLieu& data);
	void timKiemNV(DuLieu& data);
	void themNV(DuLieu& data,const NhanVienPhucVu& nv);
    void xoaNV(DuLieu& data, const string& maNv);
	void chinhSuaThongTinNv(DuLieu& data, const string& maNv);
	// quan li menu
	void xemDsDoUong(DuLieu& data);
	void timKiemDoUong(DuLieu& data);
	void themMon(DuLieu& data, const DoUong& mon);
	void xoaMon(DuLieu& data, const int& maDoUong);
	void Edit_Gia(DuLieu& data, const int& MaDouong, const float& gia);
	void themSLDoUong(DuLieu& data, const int& MaDouong, const int& newsl);
	void menuQuanLi(DuLieu& data);
	void menuQuanLiNV(DuLieu& data);
	void menuQuanLiDoUong(DuLieu& data);
	void nhapThongTin();
	void xuatThongTin();
};
