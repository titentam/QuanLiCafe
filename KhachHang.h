#pragma once
#include<string>
#include<iostream>
using namespace std;

class KhachHang
{
private:
	string maKH;
	string hoTen;
	string sdt;
public:
	int datMon();
	string getMaKH();
	void setMaKH(const string&);
	string getName();
	void setName(const string&);	
	string getSdt();
	void setSdt(const string&);
	KhachHang(const string& maKH,const string& hoTen,const string& sdt);
	KhachHang();
};

