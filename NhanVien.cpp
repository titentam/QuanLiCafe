#include<iostream>
#include<string>
#include"Nhanvien.h"

using namespace std;

NhanVien::NhanVien(const string& maNv,
	const string& hoTen,
	const string& sdt,
	const string& TK,
	const string& MK,
	const float& hsl)
	:maNv(maNv), hoTen(hoTen), sdt(sdt), TK(TK), MK(MK), hsl(hsl) {}
NhanVien::NhanVien(const string& maNv, const string& hoTen, const string& sdt, const string& MK, const float& hsl)
{
	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
	this->MK = MK;
	this->hsl = hsl;
}
NhanVien::NhanVien() :maNv(""), hoTen(""), sdt(""), TK(""), MK(""), hsl(0) {
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
string NhanVien::getTK()const {
	return this->TK;
}
void NhanVien::setTK(const string &TK) {
	this->TK = TK;
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
	cin.ignore();
	cout << "Nhap ma nhan vien: "; cin >> maNv;
	cin.ignore();
	cout << "Nhap ho ten: "; getline(cin, hoTen);
	cout << "Nhap sdt: "; getline(cin, sdt);	
	cout << "Nhap mat khau: "; cin >> MK;
	cout << "Nhap he so luong: "; cin >> hsl;
	cin.ignore();
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
	cout << setw(15) << left << "LOAI";
	cout << setw(5) << left << "DG";*/

	cout << setw(10) << left << maNv;
	cout << setw(30) << left << hoTen;
	cout << setw(15) << left << sdt;
	cout << setw(5) << left << hsl;
	cout << endl;
}
