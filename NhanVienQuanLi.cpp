#include<iostream>
#include"NhanVienQuanLi.h"
#include"menu.h"
#include<iomanip>
using namespace std;
#define LUONG 6000000
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
	this->MK = "";
	this->hsl = 0;
}
void NhanVienQuanLi::xemDsNV(DuLieu& data) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	system("cls");
	Menu a;
	const int TAB = 2;
	 a.br(2);
	 a.pre(6); cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
	 a.br(1);
	 a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
	 a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
	 a.pre(TAB); cout << setw(25) << left << " TEN" << "| ";
	 a.pre(1); cout << setw(15) << left << " SDT" << "|";
	 a.pre(1); cout << setw(5) << left << "HSL" << " |";
	
	cout << endl;
	for (int i = 0; i < nvpv.size(); i++) {
		 nvpv[i].xuatThongTin2(); 
	}
	a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
	a.br(2);
	a.pre(6);
}
void NhanVienQuanLi::xemDsDoUong(DuLieu& data) {
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
void NhanVienQuanLi::timKiemNV(DuLieu& data)
{
	Menu a;
	const int TAB = 2;
	Vector<NhanVienPhucVu> nvpv = data.getNvPhucVu();
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		cout << "1. Tim kiem theo ma" << endl;
		cout << "2. Tim kiem theo tu khoa(Ho ten)" << endl;
		cout << "0. Tro ve" << endl;
		cout << "Nhap lua chon: ";
		int opt;
		string s;
		cin >> s;
		if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
			opt = -1;
		}
		else {
			opt = (int)(s[0] - 48);
		}
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
				a.br(2);
				a.pre(6); cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
				a.br(1);
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
				a.pre(TAB); cout << setw(25) << left << " TEN" << "| ";
				a.pre(1); cout << setw(15) << left << " SDT" << "|";
				a.pre(1); cout << setw(5) << left << "HSL" << " |";
				cout << endl;
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTin2();
				}
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.br(2);
				a.pre(6);
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
				a.br(2);
				a.pre(6); cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
				a.br(1);
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
				a.pre(TAB); cout << setw(25) << left << " TEN" << "| ";
				a.pre(1); cout << setw(15) << left << " SDT" << "|";
				a.pre(1); cout << setw(5) << left << "HSL" << " |";
				cout << endl;
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTin2();
				}
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.br(2);
				a.pre(6);
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
			cout << "Nhap khong thanh cong, ma nhan vien nay da ton tai!" << endl;
			system("pause");
			return;
		}
	}
	cout << "Them thanh cong!" << endl;
	system("pause");
	nvpv.push_back(nv);
	ofstream f;
	f.open("NhanVien.csv", ios::out);
	data.xuatFileDsNhanvien(f);
	f.close();
}
void NhanVienQuanLi::xoaNV(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	bool check = true;
	for (int i = 0; i < nvpv.size(); i++) {
		if (nvpv[i].getMaNv() == maNv) {
			check = false;
			Menu a;
			system("cls");
			const int TAB = 2;
			a.br(2);
			a.pre(5); cout << "   THONG TIN NHAN VIEN " << endl;
			a.br(1);
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
			a.pre(TAB); cout << setw(25) << left << " TEN" << "| ";
			a.pre(1); cout << setw(15) << left << " SDT" << "|";
			a.pre(1); cout << setw(5) << left << "HSL" << " |";
			cout << endl;
			nvpv[i].xuatThongTin2();
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.br(2);
			cout << "Xac nhan xoa nhan vien nay? (y/n): ";
			nhaplai3:
			string s;
			cin >> s;
			if (s.size() != 1) {
				cout << "Nhap sai! Vui long nhap lai lua chon: ";
				goto nhaplai3;
			}
			else if (s[0] == 'y') {
				nvpv.erase(i);
				cout << "Da xoa nhan vien phuc vu co ma NV " << maNv << endl;
				system("pause");
			}
			else if (s[0] == 'n') return;
			else goto nhaplai3;	
		}
	}
	if (check) {
		cout << "Khong tim thay nhan vien phuc vu co ma Nv: " << maNv << endl;
		system("pause");
	}
	else {
		ofstream f;
		f.open("NhanVien.csv", ios::out);
		data.xuatFileDsNhanvien(f);
		f.close();
	}
}
void NhanVienQuanLi::xoaMon(DuLieu& data, const int& maDoUong) {
	Vector<DoUong>& doUong = data.getDoUong();
	bool check = true;
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == maDoUong) {
			check = false;
			system("cls");
			Menu a;
			const int TAB = 1;
			a.br(2);
			a.pre(6); cout << "THONG TIN DO UONG" << endl;
			a.br(1);
			a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
			a.pre(TAB); cout << setw(25) << left << "TEN" << "| ";
			a.pre(TAB); cout << setw(15) << left << "LOAI" << "| ";
			a.pre(TAB); cout << setw(10) << left << "DG" << "| ";
			a.pre(TAB); cout << setw(7) << left << "SL.Con" << "| ";
			cout << endl;
			doUong[i].xuatThongTinDoUong3(cout);
			a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
			a.br(2);
			cout << "Xac nhan xoa do uong nay? (y/n): ";
			nhaplai3:
			string s;
			cin >> s;
			if (s.size() != 1) {
				cout << "Nhap sai! Vui long nhap lai lua chon: ";
				goto nhaplai3;
			}
			else if (s[0] == 'y') {
				doUong.erase(i);
				cout << "Da xoa do uong co ma: " << maDoUong << endl;
				system("pause");
			}
			else if (s[0] == 'n') return;
			else goto nhaplai3;
		}
	}
	if (check) {
		cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
		system("pause");
	}
	else {
		ofstream f;
		f.open("Menu.csv", ios::out);
		data.xuatFileDsDoUong(f);
		f.close();
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
		cout << "Khong tim thay nhan vien phuc vu co ma Nv: " << maNv << endl;
		system("pause");
	}
	else {
		Menu m;
		bool tryAgain = true;
		Menu a;
		while (tryAgain) {
			
			system("cls");
			const int TAB = 2;
			a.br(2);
			a.pre(5); cout << "   THONG TIN NHAN VIEN CAN CHINH SUA" << endl;
			a.br(1);
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
			a.pre(TAB); cout << setw(25) << left << " TEN" << "| ";
			a.pre(1); cout << setw(15) << left << " SDT" << "|";
			a.pre(1); cout << setw(5) << left << "HSL" << " |";
			cout << endl;
			nvPhucVu[pos].xuatThongTin2();
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			int choice;
			const int SLEEP = 50;

			m.br(2); m.pre(5); cout << "  >> CHINH SUA THONG TIN NHAN VIEN <<"; Sleep(SLEEP);
			m.br(2); m.pre(5); cout << "  >> 1. Chinh sua ho ten"; Sleep(SLEEP);
			m.br(2); m.pre(5); cout << "  >> 2. Chinh sua sdt"; Sleep(SLEEP);
			m.br(2); m.pre(5); cout << "  >> 3. Chinh sua he so luong"; Sleep(SLEEP);
			m.br(2); m.pre(5); cout << "  >> 0. Tro ve";  Sleep(400);
			m.br(2); m.pre(5); cout << "  >> Nhap lua chon: ";
			string s;
			cin >> s;
			if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
				choice = -1;
			}
			else {
				choice = (int)(s[0] - 48);
			}
			cin.ignore();
			switch (choice)
			{
			case 1: {
				string tenMoi;
				cout << "Moi nhap ten moi: ";
				getline(cin, tenMoi);
				nvPhucVu[pos].setName(tenMoi);
				cout << "SUA THANH CONG!" << endl;
				ofstream f;
				f.open("NhanVien.csv", ios::out);
				data.xuatFileDsNhanvien(f);
				f.close();
				system("pause");
				break;
			}
			case 2: {
				string sdtMoi;
				cout << "Moi nhap sdt moi: ";
				getline(cin, sdtMoi);
				nvPhucVu[pos].setSdt(sdtMoi);
				cout << "SUA THANH CONG!" << endl;
				ofstream f;
				f.open("NhanVien.csv", ios::out);
				data.xuatFileDsNhanvien(f);
				f.close();
				system("pause");
				break;
			}
			case 3: {
				float hslMoi;
				cout << "Moi nhap he so luong moi: ";
				cin >> hslMoi;
				nvPhucVu[pos].setHsl(hslMoi);
				cout << "SUA THANH CONG!" << endl;
				ofstream f;
				f.open("NhanVien.csv", ios::out);
				data.xuatFileDsNhanvien(f);
				f.close();
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
		int opt;
		string s;
		cin >> s;
		if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
			opt = -1;
		}
		else {
			opt = (int)(s[0] - 48);
		}
		switch (opt) {
		case 1: {
			cout << "Nhap ma do uong can tim: ";
			int id;
			cin >> s;
			if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
				id = -1;
			}
			else {
				id = (int)(s[0] - 48);
			}
			bool check = true;
			for (int i = 0; i < dsDoUong.size(); i++) {
				if (dsDoUong[i].getMaDoUong() == id) {
					check = false;
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
					dsDoUong[i].xuatThongTinDoUong3(cout);
					a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
					a.br(2);
					a.pre(5);
					system("pause");
					system("cls");
					break;
				}
			}
			if (check) {
				cout << "Khong tim thay "<< endl;
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
				for (int i = 0; i < res.size(); i++) {
					res[i].xuatThongTinDoUong3(cout);
				}
				a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
				a.br(2);
				a.pre(5);
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
			cout << "Them mon khong thanh cong!" << endl;
			cout<<"Mon nay da ton tai" << endl;
			system("pause");
			return;
		}
	}
	cout << "Them thanh cong!" << endl;
	system("pause");
	doUong.push_back(mon);
	ofstream f;
	f.open("Menu.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}

void NhanVienQuanLi::Edit_Gia(DuLieu& data, const int& MaDouong, const float& gia) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setGia(gia);
			cout << "Sua thanh cong!" << endl;
			ofstream f;
			f.open("Menu.csv", ios::out);
			data.xuatFileDsDoUong(f);
			f.close();
			system("pause");
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
}
void NhanVienQuanLi::themSLDoUong(DuLieu& data, const int& MaDouong, const int& newsl) {
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setSoLuong(newsl);
			cout << "Them thanh cong!" << endl;
			ofstream f;
			f.open("Menu.csv", ios::out);
			data.xuatFileDsDoUong(f);
			f.close();
			system("pause");
			return;
		}
	}
	cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
}

void NhanVienQuanLi::menuQuanLiNV(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_quanliNV();
		int choice;
		string s;
		cin >> s;
		if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
			choice = -1;
		}
		else {
			choice = (int)(s[0] - 48);
		}
		switch (choice)
		{
		case 1: {
			system("cls");
			xemDsNV(data);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			timKiemNV(data);
			break;
		}
		case 3: {
			bool again = true;
			while (again) {
				system("cls");
				xemDsNV(data);
				NhanVienPhucVu nvpv;
				cout << endl;
				nvpv.nhapThongTin();
				// ktra co hop le hay khong
				Vector<NhanVienPhucVu> dsNvPV = data.getNvPhucVu();
				bool check_c3 = true;
				while (check_c3) {
					bool tryAgain = false;

					for (int i = 0; i < dsNvPV.size(); i++) {
						if (nvpv.getMaNv() == dsNvPV[i].getMaNv()) {
							cout << "Ma nhan vien phuc vu nay da ton tai!" << endl;
							cout << "Vui long nhap lai Ma nv: ";
							string id;
							cin >> id;
							nvpv.setMaNv(id);
							cout << endl;
							tryAgain = true;
							break;
						}
					}
					if (!tryAgain) check_c3 = false;
				}
				themNV(data, nvpv);
				system("cls");
				xemDsNV(data);
				cout << "Ban co muon tiep tuc? (y/n): ";
				nhaplai:
				string s;
				cin >> s;
				if (s.size() != 1) {
					cout << "Nhap lai lua chon: ";
					goto nhaplai;
				}
				else if (s[0] == 'y') again = true;
				else if (s[0] == 'n') again = false;
				else goto nhaplai;
			}
			break;
		}
		case 4: {
			bool again = true;
			while (again) {
				system("cls");
				xemDsNV(data);
				string manv;
				cout << "Nhap ma nhan vien can xoa: ";
				cin >> manv;
				xoaNV(data, manv);
				system("cls");
				xemDsNV(data);
				cout << "Ban co muon tiep tuc? (y/n): ";
				nhaplai2:
				string s;
				cin >> s;
				if (s.size() != 1) {
					cout << "Nhap lai lua chon: ";
					goto nhaplai2;
				}
				else if (s[0] == 'y') again = true;
				else if (s[0] == 'n') again = false;
				else goto nhaplai2;
			}

			break;
		}
		case 5: {
			system("cls");
			xemDsNV(data);
			string manv;
			cout << "Nhap ma nhan vien can chinh sua: ";
			cin >> manv;
			chinhSuaThongTinNv(data, manv);
			break;
		}
		case 6: {
			system("cls");
			tinhLuongNV(data);
			system("pause");
			break;
		}
		case 0: {
			check = false;
			break;
		}
		default:
			break;
		}
	}
}
void NhanVienQuanLi::menuQuanLiDoUong(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_quanliDoUong();
		int choice;
		string s;
		cin >> s;
		if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
			choice = -1;
		}
		else {
			choice = (int)(s[0] - 48);
		}
		switch (choice){
			case 1: {
			xemDsDoUong(data);
			system("pause");
			break;
		}
			case 2: {
				timKiemDoUong(data);
				break;

			}
			case 3: {

				bool again = true;
				while (again) {
					system("cls");
					xemDsDoUong(data);
					DoUong douong;
					cout << endl;
					douong.nhapThongTinDoUong();
					// ktra co hop le hay khong
					Vector<DoUong> dsDoUong = data.getDoUong();
					bool check_c3 = true;
					while (check_c3) {
						bool tryAgain = false;
						for (int i = 0; i < dsDoUong.size(); i++) {
							if (douong.getMaDoUong() == dsDoUong[i].getMaDoUong()) {
								cout << "Ma do uong nay da ton tai!" << endl;
								cout << "Vui long nhap lai(Ma do uong): ";
								int id;
								cin >> id;
								douong.setMaDoUong(id);
								cout << endl;
								tryAgain = true;
								break;
							}
						}
						if (!tryAgain) check_c3 = false;
					}
					themMon(data, douong);
					system("cls");
					xemDsDoUong(data);
					cout << "Ban co muon tiep tuc? (y/n): ";
					nhaplai:
					string s;
					cin >> s;
					if (s.size() != 1) {
						cout << "Nhap lai lua chon: ";
						goto nhaplai;
					}
					else if (s[0] == 'y') again = true;
					else if (s[0] == 'n') again = false;
					else goto nhaplai;
				}
				break;
			}
			case 4: {

				bool again = true;
				while (again) {
					system("cls");
					xemDsDoUong(data);
					int mamon;
					cout << "Nhap ma do uong can xoa: ";
					cin >> mamon;
					xoaMon(data, mamon);
					system("cls");
					xemDsDoUong(data);
					cout << "Ban co muon tiep tuc? (y/n): ";
					nhaplai2:
					string s;
					cin >> s;
					if (s.size() != 1) {
						cout << "Nhap lai lua chon: ";
						goto nhaplai2;
					}
					else if (s[0] == 'y') again = true;
					else if (s[0] == 'n') again = false;
					else goto nhaplai2;
				}
				break;
			}
			case 5: {

				bool again = true;
				while (again) {
					system("cls");
					xemDsDoUong(data);
					int maDoUong;
					cout << "Nhap ma do uong: ";
					cin >> maDoUong;
					float gia;
					cout << "Gia moi: ";
					cin >> gia;
					Edit_Gia(data, maDoUong, gia);
					system("cls");
					xemDsDoUong(data);
					cout << "Ban co muon tiep tuc? (y/n): ";
					nhaplai4:
					string s;
					cin >> s;
					if (s.size() != 1) {
						cout << "Nhap lai lua chon: ";
						goto nhaplai4;
					}
					else if (s[0] == 'y') again = true;
					else if (s[0] == 'n') again = false;
					else goto nhaplai4;
				}
				break;
			}
			case 6: {

				bool again = true;
				while (again) {
					system("cls");
					xemDsDoUong(data);
					int maDoUong;
					cout << "Nhap ma do uong: ";
					cin >> maDoUong;
					int sl;
					cout << "So luong: ";
					cin >> sl;
					themSLDoUong(data, maDoUong, sl);
					system("cls");
					xemDsDoUong(data);
					cout << "Ban co muon tiep tuc? (y/n): ";
					nhaplai5:
					string s;
					cin >> s;
					if (s.size() != 1) {
						cout << "Nhap lai lua chon: ";
						goto nhaplai5;
					}
					else if (s[0] == 'y') again = true;
					else if (s[0] == 'n') again = false;
					else goto nhaplai5;
				}
				break;
			}
			case 0: {
				check = false;
				break;
			}
			default:
				break;
	}
	}
}

void NhanVienQuanLi::menuQuanLi(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_quanli();
		int choice;
		string s;
		cin >> s;
		if (s[0] < '0' || s[0]>'9' || s.size() > 1) {
			choice = -1;
		}
		else {
			choice = (int)(s[0] - 48);
		}
		switch (choice)
		{
		case 1: {
			menuQuanLiNV(data);
			break;
		}
		case 2: {
			menuQuanLiDoUong(data);
			break;
		}
		
		case 3: {
			data.thongKe();
		}
		case 0: {
			check = false;
			break;
		}
		default:
			break;
		}
	}
}
void NhanVienQuanLi::nhapThongTin() {
	NhanVien::nhapThongTin();
}
void NhanVienQuanLi::xuatThongTin() {
	NhanVien::xuatThongTin();
}

float NhanVienQuanLi::getLuong()
{
	return hsl * LUONG;
}

void NhanVienQuanLi::tinhLuongNV(DuLieu& data)
{
	Vector<NhanVienPhucVu> nvpv = data.getNvPhucVu();
	Menu a;
	const int TAB = 2;
	a.br(2);
	a.pre(5); cout << "DANH SACH LUONG NHAN VIEN PHUC VU" << endl;
	a.br(1);
	a.pre(4); cout << setw(20) << left << "MA NHAN VIEN" << setw(20) << left << "TEN NHAN VIEN" << setw(20) << left << "LUONG" << endl;
	for (int i = 0; i < nvpv.size(); i++) {
		a.pre(4); cout << setw(20) << left << nvpv[i].getMaNv() << setw(20) << left << nvpv[i].getName() << setw(20) << setprecision(20) << left << nvpv[i].getLuong() << endl;
	}
	a.br(1); a.pre(5);
}

