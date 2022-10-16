#include "KhachHang.h"

int KhachHang::datMon() {
	int maDoUong;
	cin >> maDoUong;
	return maDoUong;
}
string KhachHang::getMaKH() {
	return this->maKH;
}
void KhachHang::setMaKH(const string& maKH) {
	this->maKH = maKH;
}
string KhachHang::getName() {
	return this->hoTen;
}
void KhachHang::setName(const string& hoTen) {
	this->hoTen = hoTen;
}
string KhachHang::getSdt() {
	return this->sdt;
}
void KhachHang::setSdt(const string& sdt) {
	this->sdt = sdt;
}
KhachHang::KhachHang() {
	this->maKH = "";
	this->hoTen = "";
	this->sdt = "";
}
KhachHang::KhachHang(const string& maKH, const string& hoTen, const string& sdt) {
	this->maKH = maKH;
	this->hoTen = hoTen;
	this->sdt = sdt;
}
