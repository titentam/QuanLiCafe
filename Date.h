#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
private:
	string ngay;
	string thang;
	string nam;
public:
	Date();
	~Date();
	bool check(const string&, const string&, const string&);
	void nhap();
	void xuat();

	string getNgay() const;
	string getThang() const;
	string getNam() const;

	void setNgay(const string&);
	void setThang(const string&);
	void setNam(const string&);

	string convert();


};
