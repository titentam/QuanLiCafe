#include "DoUong.h"
#include<iomanip>
#include"menu.h"



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
int DoUong::getMaDoUong() const {
	return maDoUong;
}
void DoUong::setMaDoUong(const int& maDoUong) {
	this->maDoUong = maDoUong;
}
string DoUong::getName() const {
	return tenDoUong;
}
void DoUong::setName(const string& tenDoUong) {
	this->tenDoUong = tenDoUong;
}
float DoUong::getGia() const {
	return gia;
}
void DoUong::setGia(const float& gia) {
	this->gia = gia;
}
int DoUong::getSoLuong() const {
	return soLuong;
}
void DoUong::setSoLuong(const int& soLuong) {
	this->soLuong = soLuong;
}
string DoUong::getLoaiDoUong() const {
	return loaiDoUong;
}
void DoUong::setLoaiDoUong(const string& loaiDoUong) {
	this->loaiDoUong = loaiDoUong;
}

void DoUong::nhapThongTinDoUong() {
	Menu a;
	const int TAB = 10;
	DoHoa::textColor(10);
	a.pre(TAB); cout << "Nhap ma do uong: "; cin >> maDoUong;
	cin.ignore();
	a.pre(TAB); cout << "Nhap ten do uong: "; getline(cin, tenDoUong);
	a.pre(TAB); cout << "Nhap gia do uong: "; cin >> gia;
	a.pre(TAB); cout << "Nhap so luong do uong: "; cin >> soLuong;
	a.pre(TAB); cout << "Nhap loai do uong: "; cin >> loaiDoUong;

}
void DoUong::xuatThongTinDoUong(ostream& out) {
	out <<setw(10)<<left<< maDoUong << " ";
	out <<setw(20)<<left<< tenDoUong << " ";
	out << soLuong << endl;
}

void DoUong::xuatThongTinDoUong2(ostream& outw)
{
	/*outw << setw(7) << left << "ID";
	outw << setw(25) << left << "TEN";
	outw << setw(25) << left << "LOAI";
	outw << setw(15) << left << "DG";*/
	outw << setw(7) << left << maDoUong;
	outw << setw(25) << left << tenDoUong;
	outw << setw(25) << left << loaiDoUong;
	outw << setw(15) << left << gia;
	outw << endl;
}

void DoUong::xuatThongTinDoUong3(ostream& outw)
{
	Menu a;
	const int TAB = 7;
	DoHoa::textColor(11);
	a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
	a.pre(TAB); outw << "| " << setw(7) << left << maDoUong << "| ";
	a.pre(1); outw << setw(25) << left << tenDoUong << "| ";
	a.pre(1); outw << setw(15) << left << loaiDoUong << "| ";
	a.pre(1); outw << setw(10) << left << gia << "| ";
	a.pre(1); outw << setw(7) << left << soLuong << "| ";
	outw << endl;
}
