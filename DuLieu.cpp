#include "DuLieu.h"
#include<iomanip>

/*
	string maNv;
	string hoTen;
	string sdt;
	string TK;
	string MK;
	float hsl;
*/
DuLieu::DuLieu() {
}
void DuLieu::docFileDsNhanVien() {
	ifstream f;
	f.open("NhanVien.csv", ios::in);
	while (!f.eof()) {
		string maNv;
		string hoTen;
		string sdt;
		string TK;
		string MK;
		float hsl;
		getline(f, maNv, ',');
		getline(f, hoTen, ',');
		getline(f, sdt, ',');
		getline(f, TK, ',');
		getline(f, MK, ',');
		f >> hsl;
		f.ignore(1);

		// get loai nhan vien
		int loaiNv = (int)(maNv[0] - '0') * 10 + (int)(maNv[1] - '0');
		switch (loaiNv)
		{
		case 0:
		{
			NhanVienQuanLi nv(maNv, hoTen, sdt, TK, MK, hsl);
			nvql.push_back(nv);
			//cout << "Nhap nhan vien thanh cong!" << endl;
			break;
		}
		case 1:
		{
			NhanVienPhucVu nv(maNv, hoTen, sdt, TK, MK, hsl);
			nvpv.push_back(nv);
			//cout << "Nhap nhan vien thanh cong!" << endl;
			break;
		}
		default:
			cout << "Nhap nhan vien khong thanh cong!" << endl;
			break;
		}	
	}
	f.close();
}

void DuLieu::docFileDsDoUong() {
	ifstream f;
	f.open("Menu.csv", ios::in);
	while (!f.eof()) {
		
		int maDoUong;
		string tenDoUong;
		float gia;
		int soLuong;
		string loaiDoUong;

		f >> maDoUong;
		f.ignore(1);
		getline(f, tenDoUong, ',');
		getline(f, loaiDoUong, ',');
		f >> gia;
		f.ignore(1);
		f >> soLuong;
		f.ignore(1);
		
		// ktr do uong da co trong danh sach chua
		bool check = true;
		for (int i = 0; i < douong.size(); i++) {
			if (douong[i].getMaDoUong() == maDoUong) {
				check = false;
				break;
			}
		}
		if (check) {
			douong.push_back(DoUong(maDoUong, tenDoUong, gia, soLuong, loaiDoUong));
		}
	}
	f.close();
}
void DuLieu::thongKe() {
	
	Date d;
		long long res = 0;
		cout << "1. Thong ke theo ngay" << endl;
		cout << "2. Thong ke theo thang" << endl;
		cout << "3. Thong ke theo nam" << endl;
		cout << "0. Tro ve" << endl << endl;

		cout << "Nhap lua chon: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1: {
			d.nhap();
			string month=d.convert();
			ifstream f;
			string tke = "ThongKe\\" + d.getNam() + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					size_t found1 = (tg.substr(8, 2)).find(d.getNgay());
					size_t found2 = tg.find(month);
					size_t found3 = tg.find(d.getNam());

					if (found1 != string::npos && found2 != string::npos && found3 != string::npos) {
						res += total;
					}
				}
				cout << "Doanh thu la: " << res << endl;
				f.close();
			}
			else {
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			string tmp;
			cout << "Moi ban nhap thang: ";
			cin >> tmp;
			d.setThang(tmp);

			cout << "Moi ban nhap nam: ";
			cin >> tmp;
			d.setNam(tmp);
			string month=d.convert();
			ifstream f;
			string tke = "ThongKe\\" + d.getNam() + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					cout << tg << "," << total << endl;
					size_t found2 = tg.find(month);
					size_t found3 = tg.find(d.getNam());

					if (found2 != string::npos && found3 != string::npos) {
						res += total;
					}
				}
				cout << "Doanh thu la: " << res << endl;
				f.close();
			}
			else {
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		case 3: {
			string tmp;
			cout << "Moi ban nhap nam: ";
			cin >> tmp;

			d.setNam(tmp);

			ifstream f;
			string tke = "ThongKe\\" + d.getNam() + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					size_t found3 = tg.find(d.getNam());

					if (found3 != string::npos) {
						res += total;
					}
				}
				cout << "Doanh thu la: " << res << endl;
				f.close();
			}
			else {
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		default:
			cout << "Khong co lua chon nay trong menu!" << endl;
			system("pause");
			break;
		}
}
Vector<DoUong>& DuLieu::getDoUong() {
	return douong;
}
Vector<NhanVienPhucVu>& DuLieu::getNvPhucVu() {
	return nvpv;
}

Vector<NhanVienQuanLi>& DuLieu::getNvQuanLi()
{
	return this->nvql;
}

void DuLieu::xuatFileDsNhanvien(ostream& out) {
	for (int i = 0; i < nvql.size(); i++) {
		out << nvql[i].getMaNv() << "," << nvql[i].getName() << "," << nvql[i].getSdt() << "," << nvql[i].getTK() << "," << nvql[i].getMK() << "," << nvql[i].getHsl() << endl;
	}
	for (int i = 0; i < nvpv.size(); i++) {
		out << nvpv[i].getMaNv() << "," << nvpv[i].getName() << "," << nvpv[i].getSdt() << "," << nvpv[i].getTK() << "," << nvpv[i].getMK() << "," << nvpv[i].getHsl() << endl;
	}
}
void DuLieu::xuatFileDsDoUong(ostream& out) {
	for (int i = 0; i < douong.size(); i++) {
		DoUong tmp = douong[i];
		out << tmp.getMaDoUong() << ",";
		out << tmp.getName() << ",";
		out << tmp.getLoaiDoUong() << ",";
		out << tmp.getGia() << ",";
		out << tmp.getSoLuong() << endl;
	}
}