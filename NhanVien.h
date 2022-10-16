#pragma once
#include <string>
#include<iostream>

using namespace std;

class NhanVien
{
protected:
	string maNv;
	string hoTen;
	string sdt;
	string TK;
	string MK;
	float hsl;
public:
	NhanVien();
	NhanVien(const string& maNv,
		const string& hoTen,
		const string& sdt,
		const string& TK,
		const string& MK,
		const float& hsl);
	string getName();
	void setName(const string&);
	string getMaNv();
	void setMaNv(const string&);
	string getSdt();
	void setSdt(const string&);
	string getTK();
	void setTK(const string&);
	string getMK();
	void setMK(const string&);
	float getHsl();
	void setHsl(const float&);
	virtual void nhapThongTin();
	virtual void xuatThongTin();
};


