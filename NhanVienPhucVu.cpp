#include "NhanVienPhucVu.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
#define LUONG 15000

NhanVienPhucVu::NhanVienPhucVu(const string& maNv,const string& hoTen,const string& sdt,
	const string& TK,const string& MK,const float& hsl) {

	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
	this->TK = TK;
	this->MK = MK;
	this->hsl = hsl;
}
NhanVienPhucVu::NhanVienPhucVu() {
	this->maNv = "";
	this->hoTen = "";
	this->sdt = "";
	this->TK = "";
	this->MK = "";
	this->hsl = 0;
}
void NhanVienPhucVu::lamDoUong(DuLieu &data,const int& maDoUong,const int& soluong) {
	Vector<DoUong> &menu = data.getDoUong();
	bool check = true;
	for (int i = 0; i < menu.size(); i++) {
		// ktra co do uong trong ds hay k
		if (maDoUong == menu[i].getMaDoUong()) {
			int soLuongcon = menu[i].getSoLuong();
			// ktra thu con so luong hay  k
			if (soLuongcon <soluong) break;
			
			check = false;
			menu[i].setSoLuong(soLuongcon - soluong);
			dsDoUong.push_back(menu[i]);
			sl.push_back(soluong);
			break;
		}
	}
	if (check) {
		cout << "Do uong khong co trong danh sach, hoac khong du !!!" << endl;
	}
}
void NhanVienPhucVu::xuatBill(ostream& outw){

	time_t now = time(0);
	string tg = ctime(&now);
	outw << "HOA DON THANH TOAN" << endl;
	outw <<"Thoi gian "<< tg << endl;// ma ten gia
	outw << "id" << setw(20) << "Ten " << setw(5) << "SL " << setw(6) << "DG " << setw(10) << "T.Tien" << endl;
	float tongtien = 0;
	int soluong = 0;
	for (int i = 0; i < dsDoUong.size(); i++) {
		dsDoUong[i].xuatThongTinDoUong(outw);
		outw<< setw(5) << sl[i] << setw(6) << dsDoUong[i].getGia() << setw(10) << dsDoUong[i].getGia()*sl[i] << endl;
		tongtien += dsDoUong[i].getGia() * sl[i];
		soluong += sl[i];
	}
	outw << "T.Cong" << setw(25) << soluong << setw(16) << tongtien << endl;
}
float NhanVienPhucVu::getLuong(const int& soGioLam) {
	return soGioLam * hsl* LUONG;
}
void NhanVienPhucVu::xuatThongTin() {
	NhanVien::xuatThongTin();
}

