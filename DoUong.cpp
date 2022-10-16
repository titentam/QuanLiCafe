#include "DoUong.h"
#include<iomanip>



DoUong::DoUong() {
	maDoUong = 0;
	tenDoUong = "";
	gia = 0;
	soLuong = 0;
	loaiDoUong = "";
}
DoUong::DoUong(const int& maDoUong, const string& tenDoUong, const float& gia, const int& soLuong, const string& loaiDoUong) {
	this->maDoUong = maDoUong;
	this->tenDoUong = tenDoUong;
	this->gia = gia;
	this->soLuong = soLuong;
	this->loaiDoUong = loaiDoUong;
}
int DoUong::getMaDoUong() {
	return maDoUong;
}
void DoUong::setMaDoUong(const int& maDoUong) {
	this->maDoUong = maDoUong;
}
string DoUong::getName() {
	return tenDoUong;
}
void DoUong::setName(const string& tenDoUong) {
	this->tenDoUong = tenDoUong;
}
float DoUong::getGia() {
	return gia;
}
void DoUong::setGia(const float& gia) {
	this->gia = gia;
}
int DoUong::getSoLuong() {
	return soLuong;
}
void DoUong::setSoLuong(const int& soLuong) {
	this->soLuong = soLuong;
}
string DoUong::getLoaiDoUong() {
	return loaiDoUong;
}
void DoUong::setLoaiDoUong(const string& loaiDoUong) {
	this->loaiDoUong = loaiDoUong;
}

void DoUong::nhapThongTinDoUong() {
	cout << "Nhap ma do uong: "; cin >> maDoUong;
	cout << "Nhap ten do uong: "; cin >> tenDoUong;
	cout << "Nhap gia do uong: "; cin >> gia;
	cout << "Nhap so luong do uong: "; cin >> soLuong;
	cout << "Nhap loai do uong: "; cin >> loaiDoUong;

}
void DoUong::xuatThongTinDoUong(ostream& out) {
	out << maDoUong << " ";
	out <<setw(20)<< tenDoUong << " ";
}