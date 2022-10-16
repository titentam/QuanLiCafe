#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class DoUong
{
private:
	int maDoUong;
	string tenDoUong;
	float gia;
	int soLuong;
	string loaiDoUong;
public:
	DoUong();
	DoUong(const int&maDoUong,const string&tenDoUong,const float&gia,const int& soLuong,const string&loaiDoUong);
	int getMaDoUong() const;
	void setMaDoUong(const int&);
	string getName() const;
	void setName(const string&);
	float getGia() const;
	void setGia(const float&);
	int getSoLuong() const;
	void setSoLuong(const int&);
	string getLoaiDoUong() const;
	void setLoaiDoUong(const string&);
	void nhapThongTinDoUong();
	void xuatThongTinDoUong(ostream&);
};

