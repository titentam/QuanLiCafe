#include"menu.h"

void Menu::br(int line) {
	for (int i = 0; i < line; i++) {
		cout << "\n";
	}
}
void Menu::pre(int tab) {
	for (int i = 0; i < tab; i++) {
		cout << "\t";
	}
}
void Menu::span(int space) {
	for (int i = 0; i < space; i++) {
		cout << " ";
	}
}
void Menu::loadingbar() {

	for (int i = 15; i <= 100; i += 5) {

		system("cls");

		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t";
		cout << i << " % Loading...\n\n\t\t";
		Sleep(15);
		if (i == 90 || i == 50 || i == 96 || i == 83) {
			Sleep(45);
		}

	}
}
void Menu::wellcome() {
	string s1 = "PHAN MEM QUAN LI";
	string s2 = "QUAN CAFE";
	cout << "\n\n\n\t\t\t\t\t\t";
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i];
		Sleep(30);
	}

	cout << "\n\n\t\t\t\t\t\t   ";
	for (int i = 0; i < s2.size(); i++) {

		cout << s2[i];
		Sleep(30);
	}
	cout << "\n\n";
	Sleep(100);
}

void Menu::menu_quanli() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU QUAN LI  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1.  MENU QUAN LI NHAN VIEN <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2.  MENU QUAN LI DO UONG  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3.  MENU THONG KE  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0.  Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);

}
void Menu::menu_quanliDoUong() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU QUAN LI DO UONG <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1. Xem danh sach do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2. Tim kiem do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3. Them mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 4. Xoa mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 5. Chinh sua gia mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 6. Cap nhat so luong con trong kho cua 1 mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0. Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);

}
void Menu::menu_quanliNV() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU QUAN LI NHAN VIEN <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1.  Xem danh sach nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2.  Tim kiem nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3.  Them nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 4.  Xoa nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 5.  Chinh sua thong tin nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 6.  Danh sach luong nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0.  Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);


	
}

void Menu::menu_phucvu() {

	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU NHAN VIEN PHUC VU <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1.  Xem danh sach do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2.  Lam do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0.  Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);
}
string Menu::nhapmk() {
	char c;
	string res = "";
	cout << "Mat khau: ";
	do
	{
		c = _getch();
		if (c == 8&&res.size()!=0) {
			cout << "\b \b";
			if (res == "") continue;
			res = res.substr(0, res.size() - 1);

		}
		else if (c != 13&&c!=8) {
			cout << "*";
			res += c;
		}
	} while (c != 13);
	return res;
}
void Menu::danhNhap(string& tk, string& mk) {
	cout << "Tai khoan: ";
	cin >> tk;
	mk = nhapmk();
}
int Menu::checkTK(DuLieu& data, const string& tk, const string& mk, const int& opt) {
	switch (opt)
	{
	case 0: {
		Vector<NhanVienQuanLi> nvql = data.getNvQuanLi();
		for (int i = 0; i < nvql.size(); i++) {
			if (nvql[i].getMaNv() == tk && nvql[i].getMK() == mk) return i;
		}
		break;
	}
	case 1: {
		Vector<NhanVienPhucVu> nvpv = data.getNvPhucVu();
		for (int i = 0; i < nvpv.size(); i++) {
			if (nvpv[i].getMaNv() == tk && nvpv[i].getMK() == mk) return i;
		}
		break;
	}
	default:
		break;
	}
	return -1;
}
void Menu::main_menu(DuLieu& data) {
	bool check = true;
	const int SLEEP = 100;
	while (check) {
		system("cls");
		br(5); pre(6); cout << "    >>  DANG NHAP  <<"; Sleep(SLEEP);
		br(2); pre(6); cout << ">> 1. Nhan vien quan li"; Sleep(SLEEP);
		br(2); pre(6); cout << ">> 2. Nhan vien phuc vu"; Sleep(SLEEP);
		br(2); pre(6); cout << ">> 0. Thoat";  Sleep(SLEEP);
		int choice;
		br(2); pre(6); cout << ">> Nhap lua chon: ";
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
			string tk, mk;
			danhNhap(tk, mk);
			int pos = checkTK(data, tk, mk, 0);
			if (pos != -1) {
				NhanVienQuanLi& nvql = (data.getNvQuanLi())[pos];
				nvql.menuQuanLi(data);
			}
			else {
				cout << endl;
				cout << "Tai khoan, mat khau sai!" << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			string tk, mk;
			danhNhap(tk, mk);
			int pos = checkTK(data, tk, mk, 1);
			if (pos != -1) {
				NhanVienPhucVu& nvpv = (data.getNvPhucVu())[pos];
				nvpv.menuPhucvu(data);
			}
			else {
				cout << endl;
				cout << "Tai khoan, mat khau sai!" << endl;
				system("pause");
			}
			break;
		}
		case 0: {
			check = false;
			break;
		}
		default:
			cout << endl;
			cout << "Lua chon khong co trong menu, vui long nhap lai!" << endl;
			system("pause");
			break;
		}
	}
}

void Menu::menu_thongke()
{
	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU THONG KE <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1. Thong ke theo ngay"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2. Thong ke theo thang"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3. Thong ke theo nam"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0. Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);
}
