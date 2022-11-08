#include "DuLieu.h"
#include<iomanip>
#include"menu.h"

DuLieu::DuLieu() {
}
void DuLieu::docFileDsNhanVien() {
	ifstream f;
	f.open("NhanVien.csv", ios::in);
	while (!f.eof()) {
		string maNv;
		string hoTen;
		string sdt;
		string MK;
		float hsl;
		getline(f, maNv, ',');
		getline(f, hoTen, ',');
		getline(f, sdt, ',');
		getline(f, MK, ',');
		f >> hsl;
		f.ignore(1);

		// get loai nhan vien
		int loaiNv = (int)(maNv[0] - '0') * 10 + (int)(maNv[1] - '0');
		switch (loaiNv)
		{
		case 0:
		{
			NhanVienQuanLi nv(maNv, hoTen, sdt, MK, hsl);
			nvql.push_back(nv);
			break;
		}
		case 1:
		{
			NhanVienPhucVu nv(maNv, hoTen, sdt, MK, hsl);
			nvpv.push_back(nv);
		
			break;
		}
		default:
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
	Menu m;
	const int TAB = 10;
	bool check = true;
	while (check) {
		Date d;
		long long res = 0;
		m.menu_thongke();
		int choice =Menu::getInt();
		switch (choice)
		{
		case 1: {
			d.nhap();
			string day = to_string(d.getNgay());
			string month = d.convert();
			string year = to_string(d.getNam());
			ifstream f;
			string tke = "ThongKe\\" + year + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					size_t found1 = (tg.substr(8, 2)).find(day);
					size_t found2 = tg.find(month);
					size_t found3 = tg.find(year);

					if (found1 != string::npos && found2 != string::npos && found3 != string::npos) {
						res += total;
					}
				}
				DoHoa::textColor(14);
				m.pre(TAB); 
				cout << "Doanh thu la: " << res << endl;
				system("pause");
				f.close();
			}
			else {
				DoHoa::textColor(12);
				m.pre(TAB);
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			int tmp;
			DoHoa::textColor(10);
			m.pre(TAB);
			cout << "Moi ban nhap thang: ";
			tmp = Menu::getInt();
			d.setThang(tmp);

			m.pre(TAB);
			cout << "Moi ban nhap nam: ";
			tmp = Menu::getInt();
			d.setNam(tmp);
			string month = d.convert();
			string year = to_string(d.getNam());
			ifstream f;
			string tke = "ThongKe\\" + year + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					size_t found2 = tg.find(month);
					size_t found3 = tg.find(year);

					if (found2 != string::npos && found3 != string::npos) {
						res += total;
					}
				}
				DoHoa::textColor(14);
				m.pre(TAB);
				cout << "Doanh thu la: " << res << endl;
				system("pause");
				f.close();
			}
			else {
				DoHoa::textColor(12);
				m.pre(TAB);
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		case 3: {
			int nam;
			DoHoa::textColor(10);
			m.pre(TAB);
			cout << "Moi ban nhap nam: ";
			nam = Menu::getInt();

			string year = to_string(nam);

			ifstream f;
			string tke = "ThongKe\\" + year + ".csv";
			f.open(tke, ios::in);
			if (f.is_open()) {
				while (!f.eof()) {
					string tg;
					long long total;
					getline(f, tg, ',');
					f >> total;
					f.ignore(1);
					size_t found3 = tg.find(year);

					if (found3 != string::npos) {
						res += total;
					}
				}
				DoHoa::textColor(14);
				m.pre(TAB);
				cout << "Doanh thu la: " << res << endl;
				system("pause");
				f.close();
			}
			else {
				DoHoa::textColor(12);
				m.pre(TAB);
				cout << "Khong co du lieu!" << endl;
				system("pause");
			}
			break;
		}
		case 0: {
			check = false;
			break;
		}
		default:
			DoHoa::textColor(12);
			m.pre(TAB); cout << "KHONG CO LUA CHON NAY TRONG MENU!" << endl;
			m.pre(TAB); cout << "VUI LONG NHAP LAI!" << endl;
			system("pause");
			break;
		}
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
void DuLieu::xuatFileDsNhanvien(ostream& out)
{
	for (int i = 0; i < nvql.size(); i++) {
		out << nvql[i].getMaNv() << "," << nvql[i].getName() << "," << nvql[i].getSdt() << "," << nvql[i].getMK() << "," << nvql[i].getHsl() << endl;
	}
	for (int i = 0; i < nvpv.size(); i++) {
		out << nvpv[i].getMaNv() << "," << nvpv[i].getName() << "," << nvpv[i].getSdt() << "," << nvpv[i].getMK() << "," << nvpv[i].getHsl() << endl;
	}
	out << "\b";
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