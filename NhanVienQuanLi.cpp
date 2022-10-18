#include<iostream>
#include"NhanVienQuanLi.h"
using namespace std;

NhanVienQuanLi::NhanVienQuanLi(const string& maNv, const string& hoTen, const string& sdt,
	const string& TK, const string& MK, const float& hsl) {

	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
	this->TK = TK;
	this->MK = MK;
	this->hsl = hsl;
}
NhanVienQuanLi::NhanVienQuanLi() {
	this->maNv = "";
	this->hoTen = "";
	this->sdt = "";
	this->TK = "";
	this->MK = "";
	this->hsl = 0;
}
void NhanVienQuanLi::xemDsNV(DuLieu& data) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	cout << "DANH SACH NHAN VIEN PHUC VU!" << endl;
	for (int i = 0; i < nvpv.size(); i++) {
		cout << i << ". ";
		nvpv[i].xuatThongTin();
	}
}
void NhanVienQuanLi::themNV(DuLieu& data, const NhanVienPhucVu& nv) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	for (int i = 0; i < nvpv.size(); i++) {
		if (nv.getMaNv() == nvpv[i].getMaNv()) {
			cout << "Nhap khong thanh cong, nhan vien nay da ton tai!" << endl;
			system("pause");
			return;
		}
	}
	nvpv.push_back(nv);
}
void NhanVienQuanLi::xoaNV(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	bool check = true;
	for (int i = 0; i < nvpv.size(); i++) {
		if (nvpv[i].getMaNv() == maNv) {
			check = false;
			nvpv.erase(i);
			cout << "Da xoa nhan vien phuc vu co maNV " << maNv << endl;
			system("pause");
		}
	}
	if (check) {
		cout << "Khong tim thay nhan vien phuc vu co maNv: " << maNv << endl;
		system("pause");
	}
}
void NhanVienQuanLi::chinhSuaThongTinNv(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvPhucVu = data.getNvPhucVu();
	bool check = true;
	int pos = 0;
	for (int i = 0; i < nvPhucVu.size(); i++)
	{
		if (nvPhucVu[i].getMaNv() == maNv) {
			check = false;
			pos = i;
			break;
		}
	}
	if (check) {
		cout << "Khong tim thay nhan vien phuc vu co maNv: " << maNv << endl;
		system("pause");
	}
	else{
		while (true){
			int choise;
			system("cls");
			cout << "===============================CHINH SUA THONG TIN NHAN VIEN==============================";
			cout << "1. Chinh sua ho ten" << endl;
			cout << "2. Chinh sua sdt" << endl;
			cout << "3. Chinh sua he so luong" << endl;
			cout << "0.Thoat" << endl;
			cout << "=========================================//===============================================";
			cout << "Moi nhap lua chon: " << endl;
			cin >> choise;
			cin.ignore();
			if (choise == 1) {

				string tenMoi;
				cout << "Moi nhap ten moi: ";
				getline(cin, tenMoi);

				nvPhucVu[pos].setName(tenMoi);
			}
			else if (choise == 2) {
				string sdtMoi;
				cout << "Moi nhap sdt moi: ";
				getline(cin, sdtMoi);

				nvPhucVu[pos].setSdt(sdtMoi);
			}
			else if (choise == 3) {
				float hslMoi;
				cout << "Moi nhap he so luong moi: ";
				cin >> hslMoi;
				nvPhucVu[pos].setHsl(hslMoi);
			}
			else break;
		}
	}
}
// quan li menu
void NhanVienQuanLi::xemDsDoUong(DuLieu& data) {
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

void NhanVienQuanLi::themMon(DuLieu& data, const DoUong& mon) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (mon.getMaDoUong() == doUong[i].getMaDoUong()) {
			cout << "Them mon khong thanh cong!-Mon nay da ton tai" << endl;
			system("pause");
			return;
		}
	}
	doUong.push_back(mon);
}
void NhanVienQuanLi::xoaMon(DuLieu& data, const int& maDoUong) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == maDoUong) {
			doUong.erase(i);
			cout << "Da xoa do uong nay khoi MENU" << endl;
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
}
void NhanVienQuanLi::Edit_Gia(DuLieu& data, const int& MaDouong, const float& gia) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setGia(gia);
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
}
void NhanVienQuanLi::themSLDoUong(DuLieu& data, const int& MaDouong, const int& newsl) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setSoLuong(newsl);
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
}
void NhanVienQuanLi::menuQuanLi(DuLieu& data) {
	
	while (true) {
		system("cls");
		cout << "===================================== MENU ===== QUAN ===== LI================================ \n";
		cout << "1.xem danh sach nhan vien phuc vu\n";
		cout << "2.them nhan vien phuc vu \n";
		cout << "3.xoa nhan vien phuc vu\n";
		cout << "4.chinh sua thong tin nhan vien phuc vu\n";
		cout << "5.them mon\n";
		cout << "6.xoa mon\n";
		cout << "7.chinh sua gia mon\n";
		cout << "8.cap nhat so luong con trong kho cua 1 mon \n";
		cout << "9.xem danh sach do uong\n";
		cout << "0.Thoat\n";
		cout << "============================================================================================== \n";
		cout << "moi nhap lua chon: ";
		int luachon;
		cin >> luachon;
		if (luachon == 1) {
			xemDsNV(data);
			system("pause");
		}
		else if (luachon == 2) {
			NhanVienPhucVu a;
			a.nhapThongTin();
			themNV(data,a);
		}
		else if (luachon == 4) {
			string manv;
			cout << "nhap ma nhan vien: ";
			cin >> manv;
			chinhSuaThongTinNv(data,manv);

		}
		else if (luachon == 3) {
			string manv;
			cout << "nhap ma nhan vien can xoa: ";
			cin >> manv;
			xoaNV(data, manv);
		}
		else if (luachon == 5) {
			DoUong a;
			a.nhapThongTinDoUong();
			themMon(data, a);
		}
		else if (luachon == 6) {
			int mamon;
			cout << "nhap ma mon do uong can xoa: ";
			cin >> mamon;
			xoaMon(data, mamon);
		}
		else if (luachon == 7) {
			int madouong;
			cout << "nhap ma do uong: ";
			cin >> madouong;
			float gia;
			cout << "gia moi: ";
			cin >> gia;
			Edit_Gia(data, madouong, gia);
		}
		else if (luachon == 8) {
			int madouong;
			cout << "nhap ma do uong: ";
			cin >> madouong;
			float soluong;
			cout << "so luong con lai: ";
			cin >> soluong;
			themSLDoUong(data, madouong, soluong);
		}
		else if (luachon == 9) {
			xemDsDoUong(data);
			system("pause");
		}
		else if (luachon == 0) { break; }
	}
}
void NhanVienQuanLi::nhapThongTin() {
	NhanVien::nhapThongTin();
}
void NhanVienQuanLi::xuatThongTin() {
	NhanVien::xuatThongTin();
}




