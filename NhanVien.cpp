#include<iostream>
#include<string>
#include"Nhanvien.h"
#include"menu.h"

using namespace std;

NhanVien::NhanVien(const string& maNv, const string& hoTen, const string& sdt, const string& MK, const float& hsl)
{
	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
	this->MK = MK;
	this->hsl = hsl;
}
NhanVien::NhanVien() :maNv(""), hoTen(""), sdt(""), MK(""), hsl(0) {
}
string NhanVien::getName() const
{
	return this->hoTen;
}
void NhanVien::setName(const string& hoTen)
{
	this->hoTen = hoTen;
}
string NhanVien::getMaNv()const
{
	return this->maNv;
}
void NhanVien::setMaNv(const string& maNv)
{
	this->maNv = maNv;
}
string NhanVien::getSdt()const
{
	return this->sdt;
}
void NhanVien::setSdt(const string &sdt)
{
	this->sdt = sdt;
}
string NhanVien::getMK() const {
	return this->MK;
}
void NhanVien::setMK(const string &MK) {
	this->MK = MK;
}
float NhanVien::getHsl()const {
	return hsl;
}
void NhanVien::setHsl(const float& hsl) {
	this->hsl = hsl;
}

void NhanVien::nhapThongTin() {
	const int TAB = 10;
	Menu m;
	DoHoa::textColor(10);
	while (true) {
		m.pre(TAB); cout << "Ma nhan vien(0YXXXX)\n";
		m.pre(TAB); cout << "Y = 0 : Nhan vien quan li\n";
		m.pre(TAB); cout << "Y = 1 : Nhan vien phuc vu\n";
		m.pre(TAB); cout << "X: ky tu bat ki\n";
		m.pre(TAB); cout << "Nhap ma nhan vien: ";
		cin >> maNv;
		if (checkMaNv(this->maNv)) break;
		cout << endl;
	}
	cin.ignore();
	m.pre(TAB); cout << "Nhap ho ten: "; getline(cin, hoTen);
	while (true) {
		m.pre(TAB); cout << "Nhap sdt: "; getline(cin, sdt);
		if (checkSdt(this->sdt)) break;
		cout << endl;
	}	
	m.pre(TAB); cout << "Nhap mat khau: "; cin >> MK;
	m.pre(TAB); cout << "Nhap he so luong: "; hsl =Menu::getFloat();
}
void NhanVien::xuatThongTin()const {
	cout << maNv << " ";
	cout <<  hoTen << " ";
	cout <<  sdt << " ";
	cout <<  hsl <<endl;
}

void NhanVien::xuatThongTin2() const
{
	/*cout << setw(10) << left << "ID";
	cout << setw(30) << left << "TEN";
	cout << setw(15) << left << "sdt";
	cout << setw(5) << left << "hsl";*/
	Menu a;
	const int TAB = 7;
	DoHoa::textColor(14);
	a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
	a.pre(TAB); cout << "| " << setw(10) << left << maNv << "| ";
	a.pre(2); cout << setw(25) << left << hoTen << "| ";
	a.pre(1); cout << setw(15) << left << sdt << "| ";
	a.pre(1); cout << setw(5) << left<<setprecision(4) << hsl << " |";
	
	cout << endl;
}

bool NhanVien::checkMaNv(string ma)
{
	if (ma.size() == 6 && ma[0]=='0') {
		if (ma[1] == '0' || ma[1] == '1') return true;
	}
	return false;
}

bool NhanVien::checkSdt(string sdt)
{
	for (int i = 0; i < sdt.size(); i++) {
		if (sdt[i] < '0' || sdt[i]>'9') return false;
	}
	return true;
}
