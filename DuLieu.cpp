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
	cout << "tam";
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