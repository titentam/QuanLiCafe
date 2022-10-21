#include<iostream>
#include"NhanVienQuanLi.h"
#include"menu.h"
#include<iomanip>
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
NhanVienQuanLi::NhanVienQuanLi(const string& maNv, const string& hoTen, const string& sdt, const string& MK, const float& hsl)
{
	this->maNv = maNv;
	this->hoTen = hoTen;
	this->sdt = sdt;
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
		nvpv[i].xuatThongTin2();
	}
}
void NhanVienQuanLi::timKiemNV(DuLieu& data)
{
	Vector<NhanVienPhucVu> nvpv = data.getNvPhucVu();
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		cout << "1. Tim kiem theo ma" << endl;
		cout << "2. Tim kiem theo tu khoa(Ho ten)" << endl;
		cout << "0. Tro ve" << endl;
		cout << "Nhap lua chon: ";
		int opt; cin >> opt;
		switch (opt) {
		case 1: {
			Vector<NhanVienPhucVu> res;
			cout << "Nhap ma nhan vien can tim: ";
			cin.ignore();
			string id; cin >> id;
			size_t found;
			for (int i = 0; i < nvpv.size(); i++) {
				found = (nvpv[i].getMaNv()).find(id);
				if (found != string::npos) {
					res.push_back(nvpv[i]);
				}

			}
			if (res.size() == 0) {
				cout << "Khong tim thay!" << endl;
				system("pause");
			}
			else {
				cout << "DANH SACH NHAN VIEN CAN TIM: " << endl;
				cout << endl;
				cout << setw(10) << left << "MANV";
				cout << setw(30) << left << "TEN";
				cout << setw(15) << left << "SDT";
				cout << setw(5) << left << "HSL";
				cout << endl;
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTin2();
				}
				system("pause");
			}
			break;
		}
		case 2: {
			Vector<NhanVienPhucVu> res;
			cout << "Nhap tu khoa: ";
			cin.ignore();
			string key; cin >> key;
			size_t found;
			for (int i = 0; i < nvpv.size(); i++) {
				found = (nvpv[i].getName()).find(key);
				if (found != string::npos) {
					res.push_back(nvpv[i]);
				}
	
			}
			if (res.size() == 0) {
				cout << "Khong tim thay!" << endl;
				system("pause");
			}
			else {
				cout << "DANH SACH NHAN VIEN CAN TIM: " << endl;
				cout << endl;
				cout << setw(10) << left << "MANV";
				cout << setw(30) << left << "TEN";
				cout << setw(15) << left << "SDT";
				cout << setw(5) << left << "HSL";
				cout << endl;
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTin2();
				}
				system("pause");
			}
			break;
		}
		case 0:
			tryAgain = false;
			break;
		default:
			cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
			system("pause");
			system("cls");
			break;
		}
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
	cout << "Them thanh cong!" << endl;
	system("pause");
	nvpv.push_back(nv);
	data.xuatFileDsNhanvien(cout);
	ofstream f;
	f.open("tam.csv", ios::out);
	data.xuatFileDsNhanvien(f);
	f.close();
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
	data.xuatFileDsNhanvien(cout);
	ofstream f;
	f.open("tam.csv", ios::out);
	data.xuatFileDsNhanvien(f);
	f.close();
}void NhanVienQuanLi::xoaMon(DuLieu& data, const int& maDoUong) {
	Vector<DoUong>& doUong = data.getDoUong();
	bool check = true;
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == maDoUong) {
			check = false;
			doUong.erase(i);
			cout << "Da xoa do uong nay khoi MENU" << endl;
			system("pause");

		}
	}
	if (check) {
		cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
		system("pause");
	}

	//data.xuatFileDsDoUong(cout);
	ofstream f;
	f.open("douong2.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
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
	else {
		Menu m;
		bool tryAgain = true;
		while (tryAgain) {
			int choise;
			const int SLEEP = 50;
			system("cls");
			m.br(5); m.pre(6); cout << ">> CHINH SUA THONG TIN NHAN VIEN <<"; Sleep(SLEEP);
			m.br(2); m.pre(6); cout << ">> 1. Chinh sua ho ten"; Sleep(SLEEP);
			m.br(2); m.pre(6); cout << ">> 2. Chinh sua sdt"; Sleep(SLEEP);
			m.br(2); m.pre(6); cout << ">> 3. Chinh sua he so luong"; Sleep(SLEEP);
			m.br(2); m.pre(6); cout << ">> 0. Tro ve";  Sleep(400);
			m.br(2); m.pre(6); cout << ">> Nhap lua chon: "; cin >> choise;
			cin.ignore();
			switch (choise)
			{
			case 1: {
				string tenMoi;
				cout << "Moi nhap ten moi: ";
				getline(cin, tenMoi);
				nvPhucVu[pos].setName(tenMoi);
				cout << "SUA THANH CONG!" << endl;
				system("pause");
				break;
			}
			case 2: {
				string sdtMoi;
				cout << "Moi nhap sdt moi: ";
				getline(cin, sdtMoi);
				nvPhucVu[pos].setSdt(sdtMoi);
				cout << "SUA THANH CONG!" << endl;
				system("pause");
				break;
			}
			case 3: {
				float hslMoi;
				cout << "Moi nhap he so luong moi: ";
				cin >> hslMoi;
				nvPhucVu[pos].setHsl(hslMoi);
				cout << "SUA THANH CONG!" << endl;
				system("pause");
				break;
			}
			case 0:
				tryAgain = false;
				break;
			default:
				cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
				system("pause");
				break;
			}
			
		}
	}
	ofstream f;
	f.open("tam.csv", ios::out);
	data.xuatFileDsNhanvien(f);
	f.close();
}
// quan li menu
void NhanVienQuanLi::xemDsDoUong(DuLieu& data) {
	Vector<DoUong>& douong = data.getDoUong();
	cout << "DANH SACH DO UONG!" << endl;
	cout << setw(7) << left << "ID";
	cout << setw(25) << left << "TEN";
	cout << setw(25) << left << "LOAI";
	cout << setw(15) << left << "DG";
	cout << setw(10) << left << "SL.Con";
	cout << endl;
	for (int i = 0; i < douong.size(); i++) {
		douong[i].xuatThongTinDoUong3(cout);
	}
}

void NhanVienQuanLi::timKiemDoUong(DuLieu& data)
{
	Vector<DoUong> dsDoUong = data.getDoUong();
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		cout << "1. Tim kiem theo ma" << endl;
		cout << "2. Tim kiem theo tu khoa(Ten do uong)" << endl;
		cout << "0. Tro ve" << endl;
		cout << "Nhap lua chon: ";
		int opt; cin >> opt;
		switch (opt) {
		case 1: {
			cout << "Nhap ma do uong can tim: ";
			int id; cin >> id;
			bool check = true;
			for (int i = 0; i < dsDoUong.size(); i++) {
				if (dsDoUong[i].getMaDoUong() == id) {
					check = false;
					cout << "THONG TIN DO UONG: " << endl;
					cout << setw(7) << left << "ID";
					cout << setw(25) << left << "TEN";
					cout << setw(25) << left << "LOAI";
					cout << setw(15) << left << "DG";
					cout << endl;
					dsDoUong[i].xuatThongTinDoUong2(cout);
					system("pause");
					system("cls");
					break;
				}
			}
			if (check) {
				cout << "Khong co do uong nao co ma: " << id << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			Vector<DoUong> res;
			cout << "Nhap tu khoa: ";
			string key; cin >> key;
			size_t found;
			for (int i = 0; i < dsDoUong.size(); i++) {
				found = (dsDoUong[i].getName()).find(key);
				if (found != string::npos) res.push_back(dsDoUong[i]);
			}
			if (res.size() == 0) {
				cout << "Khong tim thay!" << endl;
				
			}
			else {
				cout << "DANH SACH DO UONG CAN TIM: " << endl;
				cout << setw(7) << left << "ID";
				cout << setw(25) << left << "TEN";
				cout << setw(25) << left << "LOAI";
				cout << setw(15) << left << "DG";
				cout << endl;
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTinDoUong2(cout);
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 0:
			tryAgain = false;
			break;
		default:
			cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
			system("pause");
			break;
		}
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
	cout << "Them thanh cong!" << endl;
	system("pause");
	doUong.push_back(mon);
	//data.xuatFileDsDoUong(cout);
	ofstream f;
	f.open("douong2.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}

void NhanVienQuanLi::Edit_Gia(DuLieu& data, const int& MaDouong, const float& gia) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setGia(gia);
			cout << "Sua thanh cong!" << endl;
			system("pause");
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
	//data.xuatFileDsDoUong(cout);
	ofstream f;
	f.open("douong2.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}
void NhanVienQuanLi::themSLDoUong(DuLieu& data, const int& MaDouong, const int& newsl) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setSoLuong(newsl);
			cout << "Them thanh cong!" << endl;
			system("pause");
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
	data.xuatFileDsDoUong(cout);
	ofstream f;
	f.open("douong2.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}
void NhanVienQuanLi::menuQuanLi(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_quanli();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			xemDsNV(data);
			system("pause");
			break;
		}
		case 2: {
			timKiemNV(data);
			break;
		}
		case 3: {
				NhanVienPhucVu nvpv;
				cout << endl;
				nvpv.nhapThongTin();
				// ktra co hop le hay khong
				Vector<NhanVienPhucVu> dsNvPV = data.getNvPhucVu();
				for (int i = 0; i < dsNvPV.size(); i++) {

					while (nvpv.getMaNv() == dsNvPV[i].getMaNv()) {
						cout << "Ma nhan vien phuc vu nay da ton tai!" << endl;
						cout << "Vui long nhap lai(Ma nv): ";
						string id;
						cin >> id;
						nvpv.setMaNv(id);
						cout << endl;
					}
				}
				themNV(data, nvpv);
				//system("pause");
				break;
		}
		case 4: {
			string manv;
			cout << "Nhap ma nhan vien can xoa: ";
			cin >> manv;
			xoaNV(data, manv);
			//system("pause");
			break;
		}
		case 5: {
			string manv;
			cout << "Nhap ma nhan vien can chinh sua: ";
			cin >> manv;
			chinhSuaThongTinNv(data, manv);
			//system("pause");
			break;
		}
		case 6: {
			xemDsDoUong(data);
			system("pause");
			break;
		}
		case 7: {
			timKiemDoUong(data);
			//system("pause");
			break;
			
		}
		case 8: {
			DoUong douong;
			cout << endl;
			douong.nhapThongTinDoUong();
			// ktra co hop le hay khong
			Vector<DoUong> dsDoUong = data.getDoUong();
			for (int i = 0; i < dsDoUong.size(); i++) {

				while (douong.getMaDoUong() == dsDoUong[i].getMaDoUong()) {
					cout << "Ma do uong nay da ton tai!" << endl;
					cout << "Vui long nhap lai(Ma do uong): ";
					int id;
					cin >> id;
					douong.setMaDoUong(id);
					cout << endl;
				}
			}
			themMon(data, douong);
			//system("pause");
			break;
		}
		case 9: {
			int mamon;
			cout << "Nhap ma do uong can xoa: ";
			cin >> mamon;
			xoaMon(data, mamon);
			//system("pause");
			break;
		}
		case 10: {
			int maDoUong;
			cout << "Nhap ma do uong: ";
			cin >> maDoUong;
			float gia;
			cout << "Gia moi: ";
			cin >> gia;
			Edit_Gia(data, maDoUong, gia);
			//system("pause");
			break;
		}
		case 11: {
			int maDoUong;
			cout << "Nhap ma do uong: ";
			cin >> maDoUong;
			int sl;
			cout << "So luong: ";
			cin >> sl;
			themSLDoUong(data, maDoUong, sl);
			//system("pause");
			break;
		}
		case 0: {
			check = false;
			break;
		}
		default:
			break;
		}
		/*if (luachon == 1) {
			xemDsNV(data);
			system("pause");
		}
		else if (luachon == 2) {
			NhanVienPhucVu a;
			a.nhapThongTin();
			themNV(data, a);
		}
		else if (luachon == 4) {
			string manv;
			cout << "nhap ma nhan vien: ";
			cin >> manv;
			chinhSuaThongTinNv(data, manv);

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
			int soluong;
			cout << "so luong con lai: ";
			cin >> soluong;
			themSLDoUong(data, madouong, soluong);
		}
		else if (luachon == 9) {
			xemDsDoUong(data);
			system("pause");
		}
		else if (luachon == 0) {
			break;
			check = false;
		}*/
	}
}
void NhanVienQuanLi::nhapThongTin() {
	NhanVien::nhapThongTin();
}
void NhanVienQuanLi::xuatThongTin() {
	NhanVien::xuatThongTin();
}

