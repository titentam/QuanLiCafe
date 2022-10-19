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
void NhanVienPhucVu::lamDoUong(DuLieu& data, const Vector<DoUong>& dsDoUong, const Vector<int>& sl){
	Vector<DoUong> &menu = data.getDoUong();
	for (int i = 0; i < dsDoUong.size(); i++) {
		int maDoUong = dsDoUong[i].getMaDoUong();
		for (int j = 0; j < menu.size(); j++) {
			if (menu[i].getMaDoUong() == maDoUong) {
				int soLuongcon = menu[i].getSoLuong();
				// ktra thu con so luong hay  k
				if (soLuongcon < sl[i]) {
					cout << "Do uong co ma: " << maDoUong << " con lai khong du!" << endl;
				}
				else {
					menu[i].setSoLuong(soLuongcon - sl[i]);
				}	
				break;
			}
		}
	}
}
void NhanVienPhucVu::xuatBill(ostream& outw, const Vector<DoUong>& dsDoUong, const Vector<int>& sl){

	time_t now = time(0);
	string tg = ctime(&now);
	outw << "HOA DON THANH TOAN" << endl;
	outw <<"Thoi gian "<< tg << endl;// ma ten gia
	outw <<setw(10)<<left<< "id" << setw(20) <<left<< "Ten " << setw(5) <<left<< "SL " << setw(6) <<left<< "DG " << setw(10) << left<<"T.Tien" << endl;
	float tongtien = 0;
	int soluong = 0;
	for (int i = 0; i < dsDoUong.size(); i++) {
		dsDoUong[i].xuatThongTinDoUong(outw);
		outw<< setw(5) <<left<< sl[i] << setw(6) << left << dsDoUong[i].getGia() << setw(10) << left << dsDoUong[i].getGia()*sl[i] << endl;
		tongtien += dsDoUong[i].getGia() * sl[i];
		soluong += sl[i];
	}
	outw << "T.Cong" << setw(25) << soluong << setw(16) << tongtien << endl;
}
float NhanVienPhucVu::getLuong(const int& soGioLam) {
	return soGioLam * hsl* LUONG;
}

