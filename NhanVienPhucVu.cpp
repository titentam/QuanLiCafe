#include "NhanVienPhucVu.h"
#include<iostream>
#include<string>
#include<iomanip>
#include"menu.h"
#include<string>


using namespace std;
#define LUONG 15000
void NhanVienPhucVu::menuPhucvu(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_phucvu();
		int choise;
		cin >> choise;


		switch (choise)
		{

		case(1):
		{
			xemDsDoUong(data);
			system("pause");
			break;
		}
		case(2):
		{	xemDsDoUong(data);
		//system("pause");
		cout << "Nhap so loai do uong: ";
		int n;
		cin >> n;
		Vector<DoUong> menu = data.getDoUong();
		Vector<DoUong> dsDoUong;

		Vector<int> sl;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap ma do uong: ";
			int  ma;
			cin >> ma;
			cout << "Nhap so luong: ";
			int so;
			cin >> so;

			dsDoUong.push_back(menu[ma]);
			sl.push_back(so);

		}
		lamDoUong(data, dsDoUong, sl);
		ofstream f;
	
		f.open("douong2.csv", ios::out);
		data.xuatFileDsDoUong(f);
		f.close();
		xuatBill(cout, dsDoUong, sl);
		system("pause");
		break;
		}
		case(0):
		{	cout << "Da tat menu phuc vu\n";
		check = false;
		break;

		}
		}
	}
		

}
void NhanVienPhucVu::xemDsDoUong(DuLieu& data) {
	Vector<DoUong>& douong = data.getDoUong();
	cout << "DANH SACH DO UONG!" << endl;
	for (int i = 0; i < douong.size(); i++) {
		cout << douong[i].getMaDoUong() << " ";
		cout << douong[i].getName() << " ";
		cout << douong[i].getLoaiDoUong() << " ";
		cout << douong[i].getGia() << " ";
		cout << douong[i].getSoLuong();
		cout << endl;
	}
}
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
void NhanVienPhucVu::lamDoUong(DuLieu& data, const Vector<DoUong>& dsDoUong, const Vector<int>& sl) {
	Vector<DoUong>& menu = data.getDoUong();
	for (int i = 0; i < dsDoUong.size(); i++) {
		int maDoUong = dsDoUong[i].getMaDoUong();

		for (int j = 0; j < menu.size(); j++) {
			if (menu[j].getMaDoUong() == maDoUong) {
				int soLuongcon = menu[j].getSoLuong();
				// ktra thu con so luong hay  k
				if (soLuongcon < sl[i]) {
					cout << "Do uong co ma: " << maDoUong << " con lai khong du!" << endl;
				}
				else {
					menu[j].setSoLuong(soLuongcon - sl[i]);
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
	outw <<"Thoi gian: "<< tg << endl;
	outw << setw(7) << left << "ID";
	outw << setw(25) << left << "Ten ";
	outw << setw(5) << left << "SL ";
	outw << setw(15) << left << "DG ";
	outw << setw(20) << left << "T.Tien" << endl;
	long double total = 0;
	int soluong = 0;
	ofstream order;
	
	order.open("Order.csv", ios::app);
	order << tg.substr(0,tg.size()-1) << ",";
	for (int i = 0; i < dsDoUong.size(); i++) {
		
		outw << setw(7) << left << dsDoUong[i].getMaDoUong();
		order << dsDoUong[i].getMaDoUong() << ",";

		outw << setw(25) << left << dsDoUong[i].getName();
		order << dsDoUong[i].getName() << ",";

		outw << setw(5) << left << sl[i];
		order << sl[i] << ",";

		outw << setw(15) << left << setprecision(20) << dsDoUong[i].getGia();
		order << setprecision(20) << dsDoUong[i].getGia() << ",";

		float sum = dsDoUong[i].getGia() * sl[i];
		outw << setw(10) << left << setprecision(20) << sum << endl;
		order << setprecision(20) << sum << endl;
		if (i != dsDoUong.size() - 1) {
			order << " " << ",";
		}
		total += sum;
		soluong += sl[i];
	}
	for (int i = 1; i <= 62; i++) outw << "-";
	outw << endl;
	outw << setw(7) << left << "T.Cong";
	order << "T.Tong, , ,";
	outw << setw(25) << " ";
	outw << setw(5) <<left<< soluong;
	order << soluong << ", ,";
	outw << setw(15) << " ";
	outw << setw(20) <<left<< setprecision(20) << total << endl;
	order << setprecision(20) << total << endl<<endl;
	// ghi vao lich su order
	
	order.close();

	// ghi vao thong ke
	ofstream f;
	int s = (int)tg.size() - 5;
	string thongke = "ThongKe\\";
	thongke += tg.substr(s, 4) + ".csv";
	f.open(thongke, ios::app);
	tg = tg.substr(0, tg.size() - 1);
	f << tg << "," << setprecision(20) << total << endl;
	f.close();
}

float NhanVienPhucVu::getLuong(const int& soGioLam) {
	return soGioLam * hsl* LUONG;
}

