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
	const int TAB = 7;
	 a.br(2);
	 a.pre(TAB + 3); a.span(3);
	 DoHoa::textColor(142);
	 cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
	 a.br(1);
	 DoHoa::textColor(11);
	 a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
	 a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
	 a.pre(2); cout << setw(25) << left << " TEN" << "| ";
	 a.pre(1); cout << setw(15) << left << " SDT" << "|";
	 a.pre(1); cout << setw(5) << left << "HSL" << " |";
	
	cout << endl;
	for (int i = 0; i < nvpv.size(); i++) {
		 nvpv[i].xuatThongTin2(); 
	}
	DoHoa::textColor(14);
	a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
	a.br(2); a.pre(TAB);
}
void NhanVienQuanLi::xemDsDoUong(DuLieu& data) {
	Vector<DoUong>& douong = data.getDoUong();
	system("cls");
	Menu a;
	const int TAB = 7;
	a.br(2);
	a.pre(TAB + 5); a.span(1);
	DoHoa::textColor(94);
	cout << "DANH SACH DO UONG" << endl;
	a.br(1);
	DoHoa::textColor(15);
	a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
	a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
	a.pre(1); cout << setw(25) << left << "TEN" << "| ";
	a.pre(1); cout << setw(15) << left << "LOAI" << "| ";
	a.pre(1); cout << setw(10) << left << "DG" << "| ";
	a.pre(1); cout << setw(7) << left << "SL.Con" << "| ";
	cout << endl;
	for (int i = 0; i < douong.size(); i++) {
		douong[i].xuatThongTinDoUong3(cout);
	}
	DoHoa::textColor(11);
	a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
	a.br(2);
}
void NhanVienQuanLi::timKiemNV(DuLieu& data)
{
	Menu a;
	Vector<NhanVienPhucVu> nvpv = data.getNvPhucVu();
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		const int TAB = 7;
		a.br(2);
		a.pre(TAB + 5); a.span(1);

		DoHoa::textColor(46);
		cout << "TIM KIEM NHAN VIEN" << endl;
		a.br(2);
		DoHoa::textColor(10);
		a.pre(TAB + 4); a.span(1); cout << "1. Tim kiem theo ma"; a.br(2);
		a.pre(TAB + 4); a.span(1); cout << "2. Tim kiem theo tu khoa(Ho ten)"; a.br(2);
		a.pre(TAB + 4); a.span(1); cout << "0. Tro ve"; a.br(2);
		a.pre(TAB + 4); a.span(1); cout << ">>  Nhap lua chon: ";

		int opt = a.getInt();
		switch (opt) {
		case 1: {
			Vector<NhanVienPhucVu> res;
			string id;
			a.pre(TAB + 4); a.span(1); cout << "Nhap ma nhan vien can tim: ";
			cin >> id;
			size_t found;
			for (int i = 0; i < nvpv.size(); i++) {
				found = (nvpv[i].getMaNv()).find(id);
				if (found != string::npos) {
					res.push_back(nvpv[i]);
				}

			}
			if (res.size() == 0) {
				DoHoa::textColor(12);
				a.br(1); a.pre(TAB + 4); a.span(1); 
				cout << "Khong tim thay!" << endl;
				a.br(2); a.pre(TAB + 4);
				system("pause");
			}
			else {
				DoHoa::textColor(135);
				a.br(2);
				a.pre(TAB+3); cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
				a.br(1);
				DoHoa::textColor(11);
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
				a.pre(2); cout << setw(25) << left << " TEN" << "| ";
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
			a.pre(TAB + 4); a.span(1); cout << "Nhap tu khoa: ";
			string key; cin >> key;
			size_t found;
			for (int i = 0; i < nvpv.size(); i++) {
				found = (nvpv[i].getName()).find(key);
				if (found != string::npos) {
					res.push_back(nvpv[i]);
				}
	
			}
			if (res.size() == 0) {
				DoHoa::textColor(12);
				a.br(1); a.pre(TAB + 4); a.span(1);
				cout << "Khong tim thay!" << endl;
				a.br(2); a.pre(TAB + 4);
				system("pause");
			}
			else {
				a.br(2);
				DoHoa::textColor(135);
				a.pre(TAB+3); cout << "DANH SACH NHAN VIEN PHUC VU" << endl;
				a.br(1);
				DoHoa::textColor(11);
				a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
				a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
				a.pre(2); cout << setw(25) << left << " TEN" << "| ";
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
			DoHoa::textColor(12);
			a.br(1); a.pre(TAB + 4); a.span(1);
			cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
			a.br(2); a.pre(TAB + 4);
			system("pause");
			system("cls");
			break;
		}
	}
}
void NhanVienQuanLi::themNV(DuLieu& data, const NhanVienPhucVu& nv) {
	Menu a;
	DoHoa b;
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	for (int i = 0; i < nvpv.size(); i++) {
		if (nv.getMaNv() == nvpv[i].getMaNv()) {
			cout << "Nhap khong thanh cong, ma nhan vien nay da ton tai!" << endl;
			system("pause");
			return;
		}
	}
	b.textColor(5);
	a.pre(10); cout << "Them thanh cong!" << endl;
	a.pre(10); system("pause");
	nvpv.push_back(nv);
	ofstream f;
	f.open("NhanVien.csv", ios::out);
	data.xuatFileDsNhanvien(f);
	f.close();
}
void NhanVienQuanLi::xoaNV(DuLieu& data, const string& maNv) {
	Vector<NhanVienPhucVu>& nvpv = data.getNvPhucVu();
	Menu a;
	bool check = true;
	for (int i = 0; i < nvpv.size(); i++) {
		if (nvpv[i].getMaNv() == maNv) {
			check = false;
			
			system("cls");
			const int TAB = 7;
			a.br(2);
			
			a.pre(TAB + 4); a.span(3); 
			DoHoa::textColor(240);
			cout << "THONG TIN NHAN VIEN " << endl;
			a.br(1);
			DoHoa::textColor(15);
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
			a.pre(2); cout << setw(25) << left << " TEN" << "| ";
			a.pre(1); cout << setw(15) << left << " SDT" << "|";
			a.pre(1); cout << setw(5) << left << "HSL" << " |";
			cout << endl;
			nvpv[i].xuatThongTin2();
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.br(2);
			DoHoa::textColor(11);
			nhaplai3:
			a.pre(11); cout << "Xac nhan xoa nhan vien nay? (y/n): ";
			
			char c = a.getChar();
			if (c == 'y') {
				nvpv.erase(i);
				DoHoa::textColor(15);
				a.pre(11); cout << "Da xoa nhan vien phuc vu co ma NV " << maNv << endl;
				system("pause");
			}
			else if (c == 'n') break;
			else{
				DoHoa::textColor(12);
				a.pre(11); cout << "Nhap sai! Vui long nhap lai lua chon\n ";
				goto nhaplai3;
			}
		}
	}
	if (check) {
		DoHoa::textColor(12);
		a.pre(11); cout << "Khong tim thay nhan vien phuc vu co ma Nv: " << maNv << endl;
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
	Menu a;
	Vector<DoUong>& doUong = data.getDoUong();
	bool check = true;
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == maDoUong) {
			check = false;
			system("cls");
			
			const int TAB = 7;
			a.br(2);
			DoHoa::textColor(30);
			a.pre(TAB+4); cout << "THONG TIN DO UONG" << endl;
			a.br(1);
			DoHoa::textColor(15);
			a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
			a.pre(1); cout << setw(25) << left << "TEN" << "| ";
			a.pre(1); cout << setw(15) << left << "LOAI" << "| ";
			a.pre(1); cout << setw(10) << left << "DG" << "| ";
			a.pre(1); cout << setw(7) << left << "SL.Con" << "| ";
			cout << endl;
			doUong[i].xuatThongTinDoUong3(cout);
			a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
			a.br(2);
			DoHoa::textColor(10);
			nhaplai3:
			a.pre(11); cout << "Xac nhan xoa mon nay? (y/n): ";
			char c = a.getChar();
			if (c == 'y') {
				doUong.erase(i);
				DoHoa::textColor(15);
				a.pre(11); cout << "Da xoa mon co ma " << maDoUong << endl;
				system("pause");
			}
			else if (c == 'n') break;
			else {
				DoHoa::textColor(12);
				a.pre(11); cout << "Nhap sai! Vui long nhap lai lua chon\n ";
				goto nhaplai3;
			}
			
			
		}
	}
	if (check) {
		DoHoa::textColor(12);
		a.pre(11); cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
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
	Menu a;
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
		DoHoa::textColor(12);
		a.pre(11); cout << "Khong tim thay nhan vien phuc vu co ma Nv: " << maNv << endl;
		system("pause");
	}
	else {	
		bool tryAgain = true;
		while (tryAgain) {
			system("cls");
			const int TAB = 7;
			a.br(2);
			a.pre(TAB+4); 
			DoHoa::textColor(240);
			cout << "THONG TIN NHAN VIEN CAN CHINH SUA" << endl;
			a.br(1);
			DoHoa::textColor(15);
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			a.pre(TAB); cout << "| " << setw(10) << left << " MANV" << "| ";
			a.pre(2); cout << setw(25) << left << " TEN" << "| ";
			a.pre(1); cout << setw(15) << left << " SDT" << "|";
			a.pre(1); cout << setw(5) << left << "HSL" << " |";
			cout << endl;
			nvPhucVu[pos].xuatThongTin2();
			a.pre(TAB); cout << "---------------------------------------------------------------------------------------\n";
			int choice;
			const int SLEEP = 20;

			a.br(2); a.pre(TAB+3); 
			DoHoa::textColor(30);
			cout << ">> CHINH SUA THONG TIN NHAN VIEN <<"; Sleep(SLEEP);
			DoHoa::textColor(11);
			a.br(2); a.pre(TAB+3); cout << "  >> 1. Chinh sua ho ten"; Sleep(SLEEP);
			a.br(2); a.pre(TAB + 3); cout << "  >> 2. Chinh sua sdt"; Sleep(SLEEP);
			a.br(2); a.pre(TAB + 3); cout << "  >> 3. Chinh sua he so luong"; Sleep(SLEEP);
			a.br(2); a.pre(TAB + 3); cout << "  >> 0. Tro ve";  Sleep(400);
			a.br(2); a.pre(TAB + 3); cout << "  >> Nhap lua chon: ";
			DoHoa::textColor(10);
			choice = a.getInt();
			switch (choice)
			{
			case 1: {
				string tenMoi;
				a.br(1);
				a.pre(11); cout << "Moi nhap ten moi: ";
				getline(cin, tenMoi);
				nvPhucVu[pos].setName(tenMoi);
				DoHoa::textColor(15);
				a.pre(11);
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
				while (true) {
					a.br(1);
					a.pre(11); cout << "Moi nhap sdt moi: ";
					cin >> sdtMoi;
					if (nvPhucVu[pos].checkSdt(sdtMoi)) break;
				}
				nvPhucVu[pos].setSdt(sdtMoi);
				DoHoa::textColor(15);
				a.pre(11);
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
				a.br(1);
				a.pre(11); cout << "Moi nhap he so luong moi: ";
				hslMoi = a.getFloat();
				nvPhucVu[pos].setHsl(hslMoi);
				DoHoa::textColor(15);
				a.pre(11);
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
				DoHoa::textColor(12);
				a.pre(11); cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
				system("pause");
				break;
			}	
		}
	}
}

void NhanVienQuanLi::timKiemDoUong(DuLieu& data)
{
	Menu a;
	const int TAB = 10;
	Vector<DoUong> dsDoUong = data.getDoUong();
	bool tryAgain = true;
	while (tryAgain) {
		system("cls");
		DoHoa::textColor(30);
		a.br(3); a.pre(TAB + 1); cout << "TIM KIEM DO UONG"; a.br(2);
		DoHoa::textColor(14);
		a.pre(TAB); cout << "1. Tim kiem theo ma"; a.br(2);
		a.pre(TAB); cout << "2. Tim kiem theo tu khoa(Ten do uong)"; a.br(2);
		a.pre(TAB); cout << "0. Tro ve"; a.br(2);
		a.pre(TAB); cout << "Nhap lua chon: ";
		
		DoHoa::textColor(10);
		int opt = a.getInt();
	
		switch (opt) {
		case 1: {
			a.br(1); a.pre(TAB); cout << "Nhap ma do uong can tim: ";
			int id=a.getInt();
			bool check = true;
			for (int i = 0; i < dsDoUong.size(); i++) {
				if (dsDoUong[i].getMaDoUong() == id) {
					check = false;
					Menu a;
					const int TAB = 7;
					a.br(2);
					DoHoa::textColor(30);
					a.pre(TAB+4); cout << "DANH SACH DO UONG" << endl;
					a.br(1);
					DoHoa::textColor(15);
					a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
					a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
					a.pre(1); cout << setw(25) << left << "TEN" << "| ";
					a.pre(1); cout << setw(15) << left << "LOAI" << "| ";
					a.pre(1); cout << setw(10) << left << "DG" << "| ";
					a.pre(1); cout << setw(7) << left << "SL.Con" << "| ";
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
				DoHoa::textColor(12);
				a.pre(TAB); cout << "Khong tim thay "<< endl;
				system("pause");
			}
			break;
		}
		case 2: {
			Vector<DoUong> res;
			DoHoa::textColor(10);
			a.br(1); a.pre(TAB); cout << "Nhap tu khoa: ";
			string key; getline(cin,key);
			size_t found;
			for (int i = 0; i < dsDoUong.size(); i++) {
				found = (dsDoUong[i].getName()).find(key);
				if (found != string::npos) res.push_back(dsDoUong[i]);
			}
			if (res.size() == 0) {
				DoHoa::textColor(12);
				a.pre(TAB); cout << "Khong tim thay!" << endl;
				
			}
			else {
				Menu a;
				const int TAB = 7;
				a.br(2);
				DoHoa::textColor(30);
				a.pre(TAB+4); cout << "DANH SACH DO UONG" << endl;
				a.br(1);
				DoHoa::textColor(15);
				a.pre(TAB); cout << "------------------------------------------------------------------------------------------------\n";
				a.pre(TAB); cout << "| " << setw(7) << left << "ID" << "| ";
				a.pre(1); cout << setw(25) << left << "TEN" << "| ";
				a.pre(1); cout << setw(15) << left << "LOAI" << "| ";
				a.pre(1); cout << setw(10) << left << "DG" << "| ";
				a.pre(1); cout << setw(7) << left << "SL.Con" << "| ";
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
			DoHoa::textColor(12);
			a.pre(TAB); cout << "LUA CHON NAY KHONG CO TRONG MENU, VUI LONG NHAP LAI!" << endl;
			system("pause");
			break;
		}
	}
}

void NhanVienQuanLi::themMon(DuLieu& data, const DoUong& mon) {
	Menu a;
	const int TAB = 10;
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (mon.getMaDoUong() == doUong[i].getMaDoUong()) {
			DoHoa::textColor(12);
			a.pre(TAB); cout << "Them mon khong thanh cong!" << endl;
			a.pre(TAB); cout<<"Mon nay da ton tai" << endl;
			system("pause");
			return;
		}
	}
	DoHoa::textColor(14);
	a.pre(TAB); cout << "Them thanh cong!" << endl;
	system("pause");
	doUong.push_back(mon);
	ofstream f;
	f.open("Menu.csv", ios::out);
	data.xuatFileDsDoUong(f);
	f.close();
}

void NhanVienQuanLi::Edit_Gia(DuLieu& data, const int& MaDouong, const float& gia) {
	Menu a;
	const int TAB = 10;
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setGia(gia);
			DoHoa::textColor(14);
			a.pre(TAB); cout << "Sua thanh cong!" << endl;
			ofstream f;
			f.open("Menu.csv", ios::out);
			data.xuatFileDsDoUong(f);
			f.close();
			system("pause");
			return;
		}
	}
	DoHoa::textColor(12);
	a.pre(TAB); cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
}
void NhanVienQuanLi::themSLDoUong(DuLieu& data, const int& MaDouong, const int& newsl) {
	Menu a;
	const int TAB = 10;
	Vector<DoUong>& doUong = data.getDoUong();
	for (int i = 0; i < doUong.size(); i++) {
		if (doUong[i].getMaDoUong() == MaDouong) {
			doUong[i].setSoLuong(newsl);
			DoHoa::textColor(14);
			a.pre(TAB); cout << "Them thanh cong!" << endl;
			ofstream f;
			f.open("Menu.csv", ios::out);
			data.xuatFileDsDoUong(f);
			f.close();
			system("pause");
			return;
		}
	}
	DoHoa::textColor(12);
	a.pre(TAB); cout << "KHONG CO DO UONG NAY TRONG DANH SACH" << endl;
	system("pause");
}

void NhanVienQuanLi::menuQuanLiNV(DuLieu& data) {
	bool check = true;
	while (check) {
		Menu a;
		a.menu_quanliNV();
		int choice = a.getInt();
		
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
			
			while (true) {
				const int TAB = 11;
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
							DoHoa::textColor(12);
							a.pre(TAB); cout << "Ma nhan vien phuc vu nay da ton tai" << endl;
							DoHoa::textColor(10);
							string id;
							while (true) {	
								a.pre(TAB); cout << "Ma nhan vien(0YXXXX)\n";
								a.pre(TAB); cout << "Y = 0 : Nhan vien quan li\n";
								a.pre(TAB); cout << "Y = 1 : Nhan vien phuc vu\n";
								a.pre(TAB); cout << "X: ky tu bat ki\n";
								a.pre(TAB); cout << "Vui long nhap lai Ma nv: ";
								cin >> id;
								if(dsNvPV[0].checkMaNv(id)) break;
							}
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
				DoHoa::textColor(15);
				nhaplai:
				a.pre(3); cout << "Ban co muon tiep tuc? (y/n): ";	
				char c = a.getChar();
				if (c == 'y');
				else if (c == 'n') break;
				else {
					DoHoa::textColor(12);
					a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
					goto nhaplai;
				}
			}
			break;
		}
		case 4: {
			
			while (true) {
				const int TAB = 5;
				system("cls");
				xemDsNV(data);
				string manv;
				DoHoa::textColor(10);
				a.pre(TAB); cout << "Nhap ma nhan vien can xoa: ";
				cin >> manv;
				xoaNV(data, manv);
				system("cls");
				xemDsNV(data);
				DoHoa::textColor(15);
				nhaplai2:
				a.pre(TAB); cout << "Ban co muon tiep tuc? (y/n): ";
				char c = a.getChar();
				if (c == 'y');
				else if (c == 'n') break;
				else{
					DoHoa::textColor(12);
					a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
					goto nhaplai2;
				}
			}

			break;
		}
		case 5: {
			system("cls");
			xemDsNV(data);
			string manv;
			DoHoa::textColor(10);
			a.pre(4); cout << "Nhap ma nhan vien can chinh sua: ";
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
		int choice = a.getInt();
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
				Menu a;
				const int TAB = 10;
				
				while (true) {
					system("cls");
					xemDsDoUong(data);
					DoUong douong;
					cout << endl;
					douong.nhapThongTinDoUong();
					// ktra co hop le hay khong
					Vector<DoUong> dsDoUong = data.getDoUong();
					while (true) {
						bool tryAgain = true;
						for (int i = 0; i < dsDoUong.size(); i++) {
							if (douong.getMaDoUong() == dsDoUong[i].getMaDoUong()) {
								DoHoa::textColor(12);
								a.pre(TAB); cout << "Ma do uong nay da ton tai!" << endl;
								DoHoa::textColor(10);
								int id;
								a.pre(TAB); cout << "Vui long nhap lai(Ma do uong): ";
								id = a.getInt();	
								douong.setMaDoUong(id);
								cout << endl;
								tryAgain = false;
								break;
							}
						}
						if (tryAgain) break;
					}
					themMon(data, douong);
					system("cls");
					xemDsDoUong(data);
					DoHoa::textColor(14);
					nhaplai:
					a.pre(TAB); cout << "Ban co muon tiep tuc? (y/n): ";
					char c = a.getChar();
					DoHoa::textColor(10);
					if (c == 'y');
					else if (c == 'n') break;
					else {
						DoHoa::textColor(12);
						a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
						goto nhaplai;
					}	
					
				}
				break;
			}
			case 4: {
				Menu a;
				const int TAB = 10;
				
				while (true) {
					system("cls");
					xemDsDoUong(data);
					int mamon;
					DoHoa::textColor(10);
					a.pre(TAB); cout << "Nhap ma do uong can xoa(so nguyen): ";
					mamon = a.getInt();
					xoaMon(data, mamon);
					system("cls");
					xemDsDoUong(data);
					DoHoa::textColor(14);
					nhaplai2:
					a.pre(TAB); cout << "Ban co muon tiep tuc? (y/n): ";
					DoHoa::textColor(10);
					char c = a.getChar();
					if (c == 'y');
					else if (c == 'n') break;
					else {
						DoHoa::textColor(12);
						a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
						goto nhaplai2;
					}	
				}
				break;
			}
			case 5: {
				Menu a;
				const int TAB = 10;
				
				while (true) {
					system("cls");
					xemDsDoUong(data);
					int maDoUong;
					DoHoa::textColor(10);
					a.pre(TAB); cout << "Nhap ma do uong: ";
					maDoUong = a.getInt();
					float gia;
					a.pre(TAB); cout << "Gia moi: ";
					gia = a.getFloat();
					Edit_Gia(data, maDoUong, gia);
					system("cls");
					xemDsDoUong(data);
					DoHoa::textColor(14);
					nhaplai3:
					a.pre(TAB); cout << "Ban co muon tiep tuc? (y/n): ";
					DoHoa::textColor(10);
					char c = a.getChar();
					if (c == 'y');
					else if (c == 'n') break;
					else {
						DoHoa::textColor(12);
						a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
						goto nhaplai3;
					}
				}
				break;
			}
			case 6: {
				Menu a;
				const int TAB = 10;
				
				while (true) {
					system("cls");
					xemDsDoUong(data);
					int maDoUong;
					DoHoa::textColor(10);
					a.pre(TAB); cout << "Nhap ma do uong(so nguyen): ";
					maDoUong = a.getInt();
					int sl;
					a.pre(TAB); cout << "So luong: ";
					sl = a.getInt();
					themSLDoUong(data, maDoUong, sl);
					system("cls");
					xemDsDoUong(data);
					DoHoa::textColor(14);
					nhaplai4:
					a.pre(TAB); cout << "Ban co muon tiep tuc? (y/n): ";
					DoHoa::textColor(10);
					char c = a.getChar();
					if (c == 'y');
					else if (c == 'n') break;
					else {
						DoHoa::textColor(12);
						a.pre(TAB); cout << "NHAP LAI LUA CHON!\n\n ";
						goto nhaplai4;
					}
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
	DoHoa::textColor(30);
	a.pre(10); cout << "DANH SACH LUONG NHAN VIEN PHUC VU" << endl;
	a.br(1);
	DoHoa::textColor(8);
	a.pre(9); cout << setw(20) << left << "MA NHAN VIEN" << setw(20) << left << "TEN NHAN VIEN" << setw(20) << left << "LUONG" << endl;
	DoHoa::textColor(15);
	for (int i = 0; i < nvpv.size(); i++) {
		a.pre(9); cout << setw(20) << left << nvpv[i].getMaNv() << setw(20) << left << nvpv[i].getName() << setw(20) << setprecision(20) << left << nvpv[i].getLuong() << endl;
	}
	a.br(1); a.pre(5);
}

