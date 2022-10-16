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
	nvpv.push_back(nv);
}
void NhanVienQuanLi::xoaNV(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	bool check = true;
	for (int i = 0; i < nvpv.size(); i++) {
		if (nvpv[i].getMaNv() == maNv) {
			check = false;
			nvpv.erase(i);
		}
	}
	if (check) {
		cout << "Khong tim thay nhan vien phuc vu co maNv: " << maNv << endl;
	}
}
void NhanVienQuanLi::chinhSuaThongTinNv(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvPhucVu = data.getNvPhucVu();
	for (int i = 0; i < nvPhucVu.size(); i++)
	{
		if (nvPhucVu[i].getMaNv() == maNv)
		{
			while (true)
			{
				int choise;
				system("cls");
				cout << "===============================CHINH SUA THONG TIN NHAN VIEN==============================";
				cout << "Moi nhap lua chon: " << endl;
				cout << "1. Chinh sua ho ten" << endl;
				cout << "2. Chinh sua sdt" << endl;
				cout << "3. Chinh sua he so luong" << endl;
				cout << "0.Thoat" << endl;
				cout << "=========================================//===============================================";
				cin >> choise;
				if (choise == 1) {

					string tenMoi;
					cout << "moi nhap ten moi: ";
					getline(cin, tenMoi);

					nvPhucVu[i].setName(tenMoi);
				}
				else if (choise == 2) {
					string sdtMoi;
					cout << "moi nhap sdt moi: ";
					getline(cin, sdtMoi);

					nvPhucVu[i].setSdt(sdtMoi);
				}
				else if (choise == 3) {
					string	hslMoi;
					cout << "moi nhap he so luong moi: ";
					getline(cin, hslMoi);

					nvPhucVu[i].setSdt(hslMoi);
				}
				else break;
			}
		}
		else {
			cout << "ma nhan vien khong dung, moi ban nhap lai";
			system("pause");
			break;
		}

	}
}
// quan li menu

void NhanVienQuanLi::themMon(DuLieu& data, const DoUong& douong) {
	Vector<DoUong>& doUong = data.getDoUong();
	doUong.push_back(douong);
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
		cout << "============================================================================================== \n";
		cout << "moi nhap lua chon: ";
		int luachon;
		cin >> luachon;
		if (luachon == 1) { xemDsNV(data); }
		else if (luachon == 2) {
			NhanVienPhucVu a;
			a.nhapThongTin();
			themNV(data,a);
		}
		else if (luachon == 3) {
			string manv;
			cout << "nhap ma nhan vien: ";
			cin >> manv;
			chinhSuaThongTinNv(data,manv);

		}
		else if (luachon == 4) {
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
			string mamon;
			cout << "nhap ma mon do uong can xoa: ";
			cin >> mamon;
			xoaNV(data, mamon);
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
			Edit_Gia(data, madouong, soluong);
		}
		else if (luachon == 8) { break; }
	}
}
void NhanVienQuanLi::nhapThongTin() {
	NhanVien::nhapThongTin();
}
void NhanVienQuanLi::xuatThongTin() {
	NhanVien::xuatThongTin();
}



