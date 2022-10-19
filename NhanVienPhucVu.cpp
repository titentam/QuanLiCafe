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
	outw << setw(7) << left << "ID";
	outw << setw(25) << left << "Ten ";
	outw << setw(5) << left << "SL ";
	outw << setw(15) << left << "DG ";
	outw << setw(10) << left << "T.Tien" << endl;
	float total = 0;
	int soluong = 0;
	for (int i = 0; i < dsDoUong.size(); i++) {
		
		outw << setw(7) << left << dsDoUong[i].getMaDoUong();
		outw << setw(25) << left << dsDoUong[i].getName();
		outw << setw(5) << left << sl[i];
		outw << setw(15) << left << dsDoUong[i].getGia();
		float sum = dsDoUong[i].getGia() * sl[i];
		outw << setw(10) << left << sum << endl;
		total += sum;
		soluong += sl[i];
	}
	for (int i = 1; i <= 62; i++) outw << "-";
	outw << endl;
	outw << setw(7) << left << "T.Cong";
	outw << setw(25) << " ";
	outw << setw(5) <<left<< soluong;
	outw << setw(15) << " ";
	outw << setw(10) <<left<< total << endl;
}
float NhanVienPhucVu::getLuong(const int& soGioLam) {
	return soGioLam * hsl* LUONG;
}

