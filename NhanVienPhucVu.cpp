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

		case 1:
		{
			system("cls");
			xemDsDoUong(data);
			system("pause");
			break;
		}
		case 2:
		{	
			system("cls");
			xemDsDoUong(data);
			cout << "Nhap so do uong: ";
			int n;
			cin >> n;
			Vector<DoUong> menu = data.getDoUong();
			Vector<DoUong> dsDoUong;

			Vector<int> sl;
			for (int i = 0; i < n; i++)
			{
				cout << "Nhap ma do uong thu " << i + 1 << ": ";
				int  ma;
				cin >> ma;
				cout << "Nhap so luong: ";
				int so;
				cin >> so;
				bool error = true;
				for (int i = 0; i < menu.size(); i++) {
					if (menu[i].getMaDoUong() == ma) {
						dsDoUong.push_back(menu[i]);
						sl.push_back(so);
						error = false;
					}
				}
				if (error) {
					cout << "MA DO UONG NAY KHONG CO TRONG MENU!" << endl;
					cout << "VUI LONG NHAP LAI!" << endl;
					system("pause");
					i--;
					cout << endl;
				}	
			}
		    lamDoUong(data, dsDoUong, sl);
		    xuatBill(cout, dsDoUong, sl);
		    system("pause");
		    break;
		}
		case 0:
		{	
		    check = false;
		    break;

		}
		default:
			cout << "LUA CHON KHONG CO TRONG MENU!" << endl;
			cout << "VUI LONG NHAP LAI!" << endl;
			system("pause");
			system("cls");
		}
	}
		

}
void NhanVienPhucVu::xemDsDoUong(DuLieu& data) {
	Vector<DoUong>& douong = data.getDoUong();
	system("cls");
	Menu a;
	const int TAB = 1;
	a.br(2);
	a.pre(6); cout << "DANH SACH DO UONG" << endl;
	a.br(1);
	a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
	a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
	a.pre(TAB); cout << setw(25) << left << "TEN" << "| ";
	a.pre(TAB); cout << setw(15) << left << "LOAI" << "| ";
	a.pre(TAB); cout << setw(10) << left << "DG" << "| ";
	a.pre(TAB); cout << setw(7) << left << "SL.Con" << "| ";
	cout << endl;
	for (int i = 0; i < douong.size(); i++) {
		douong[i].xuatThongTinDoUong3(cout);
	}
	a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
	a.br(2);
	a.pre(5);
}
NhanVienPhucVu::NhanVienPhucVu(const string& maNv, const string& hoTen, const string& sdt, const string& MK, const float& hsl)
{
	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
	this->MK = MK;
	this->hsl = hsl;
}
NhanVienPhucVu::NhanVienPhucVu() {
	this->maNv = "";
	this->hoTen = "";
	this->sdt = "";
	this->MK = "";
	this->hsl = 0;
}
void NhanVienPhucVu::lamDoUong(DuLieu& data, Vector<DoUong>& dsDoUong, Vector<int>& sl) {
	Vector<DoUong>& menu = data.getDoUong();

	for (int i = 0; i < dsDoUong.size(); i++) {
		int maDoUong = dsDoUong[i].getMaDoUong();

		for (int j = 0; j < menu.size(); j++) {
			if (menu[j].getMaDoUong() == maDoUong) {
				int soLuongcon = menu[j].getSoLuong();
				// ktra thu con so luong hay  k
				if (soLuongcon < sl[i]) {
					cout << "Do uong co ma: " << maDoUong << " con lai khong du!" << endl;
					dsDoUong.erase(i);
					sl.erase(i);
					i--;
				}
				else {
					menu[j].setSoLuong(soLuongcon - sl[i]);
				}
			}
		}
	}
	ofstream f;
	f.open("Menu.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}
void NhanVienPhucVu::xuatBill(ostream& outw, const Vector<DoUong>& dsDoUong, const Vector<int>& sl){
	system("cls");
	Menu a;
	const int TAB = 1;
	
	time_t now = time(0);
	string tg = ctime(&now);
	a.br(2);
	a.pre(6); 
	outw << "HOA DON THANH TOAN" << endl;
	a.pre(TAB); outw <<"Thoi gian: "<< tg << endl;
	a.pre(TAB); outw << setw(7) << left << "ID";
	a.pre(TAB); outw << setw(25) << left << "Ten ";
	a.pre(TAB); outw << setw(5) << left << "SL ";
	a.pre(TAB); outw << setw(15) << left << "DG ";
	a.pre(TAB); outw << setw(20) << left << "T.Tien" << endl;
	long double total = 0;
	int soluong = 0;
	ofstream order;
	
	order.open("Order.csv", ios::app);
	order << tg.substr(0,tg.size()-1) << ",";
	for (int i = 0; i < dsDoUong.size(); i++) {
		
		a.pre(TAB); outw << setw(7) << left << dsDoUong[i].getMaDoUong();
		order << dsDoUong[i].getMaDoUong() << ",";

		a.pre(TAB); outw << setw(25) << left << dsDoUong[i].getName();
		order << dsDoUong[i].getName() << ",";

		a.pre(TAB); outw << setw(5) << left << sl[i];
		order << sl[i] << ",";

		a.pre(TAB); outw << setw(15) << left << setprecision(20) << dsDoUong[i].getGia();
		order << setprecision(20) << dsDoUong[i].getGia() << ",";

		float sum = dsDoUong[i].getGia() * sl[i];
		a.pre(TAB); outw << setw(10) << left << setprecision(20) << sum << endl;
		order << setprecision(20) << sum << endl;
		if (i != dsDoUong.size() - 1) {
			order << " " << ",";
		}
		total += sum;
		soluong += sl[i];
	}
	a.pre(TAB); for (int i = 1; i <= 70; i++)  outw << "-";
	outw << endl;
	a.pre(TAB); outw << setw(7) << left << "T.Cong";
	order << "T.Tong, , ,";
	a.pre(TAB); outw << setw(25) << " ";
	a.pre(TAB); outw << setw(5) <<left<< soluong;
	order << soluong << ", ,";
	a.pre(TAB); outw << setw(15) << " ";
	a.pre(TAB); outw << setw(20) <<left<< setprecision(20) << total << endl;
	order << setprecision(20) << total << endl<<endl;
	// ghi vao lich su order
	
	order.close();

	// ghi vao thong ke
	ofstream f;
	int s = (int)tg.size() - 5;
	string thongke = "ThongKe\\";
	thongke += tg.substr(s, 4) + ".csv";
	f.open(thongke, ios::app);
	f << endl;
	tg = tg.substr(0, tg.size() - 1);
	f << tg << "," << setprecision(20)<<total;
	f.close();
}

float NhanVienPhucVu::getLuong(const int& soGioLam) {
	return soGioLam * hsl* LUONG;
}

