#pragma once
#include<iostream>
#include<string>

using namespace std;
class Date
{
private:
	int ngay;
	int thang;
	int nam;
public:
	Date();
	~Date();
	bool check(const int&, const int&, const int&);
	void nhap();
	void xuat();
};

