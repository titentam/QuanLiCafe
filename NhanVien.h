#pragma once
#include <string>
#include<iostream>
#include<iomanip>

using namespace std;

class NhanVien
{
protected:
	string maNv;
	string hoTen;
	string sdt;
	string MK;
	float hsl;
public:
	NhanVien();
	NhanVien(const string& maNv,
		const string& hoTen,
		const string& sdt,
		const string& MK,
		const float& hsl);
	string getName() const;
	void setName(const string&);
	string getMaNv() const;
	void setMaNv(const string&);
	string getSdt() const;
	void setSdt(const string&);
	string getMK() const;
	void setMK(const string&);
	float getHsl() const;
	void setHsl(const float&);
	virtual void nhapThongTin();
	virtual void xuatThongTin() const;
	virtual void xuatThongTin2() const;

	virtual float getLuong() = 0;
};


