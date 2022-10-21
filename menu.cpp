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
		cout << i << " %% Loading...\n\n\t\t";
		Sleep(60);
		if (i == 90 || i == 50 || i == 96 || i == 83) {
			Sleep(100);
		}

	}
}
void Menu::wellcome() {
	string s1 = "PHAN MEM QUAN LI";
	string s2 = "QUAN CAFE";
	cout << "\n\n\n\t\t\t\t\t\t";
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i];
		Sleep(50);
	}

	cout << "\n\n\t\t\t\t\t\t   ";
	for (int i = 0; i < s2.size(); i++) {

		cout << s2[i];
		Sleep(50);
	}
	cout << "\n\n";
}
//trong file nhanvienquanli.cpp co menu quan li roi
void Menu::menu_quanli() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 5;
	br(4); pre(TAB); cout << "    >>  MENU QUAN LI  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 1.  Xem danh sach nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2.  Tim kiem nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3.  Them nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 4.  Xoa nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 5.  Chinh sua thong tin nhan vien phuc vu"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 6.  Xem danh sach do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 7.  Tim kiem do uong"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 8.  Them mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 9.  Xoa mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 10. Chinh sua gia mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 11. Cap nhat so luong con trong kho cua 1 mon"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 12. Thong ke"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0.  Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);


	/*br(3); pre(2); cout << "===================================== MENU ===== QUAN ===== LI================================ \n";
	int TAB = 5;
	int sleep = 180;
	pre(TAB);
	cout << "1.Xem danh sach nhan vien phuc vu\n"; Sleep(sleep); pre(TAB);
	cout << "2.Them nhan vien phuc vu \n"; Sleep(sleep); pre(TAB);
	cout << "3.Xoa nhan vien phuc vu\n"; Sleep(sleep); pre(TAB);
	cout << "4.Chinh sua thong tin nhan vien phuc vu\n"; Sleep(sleep); pre(TAB);
	cout << "5.Them mon\n"; Sleep(sleep); pre(TAB);
	cout << "6.Xoa mon\n"; Sleep(sleep); pre(TAB);
	cout << "7.Chinh sua gia mon\n"; Sleep(sleep); pre(TAB);
	cout << "8.Cap nhat so luong con trong kho cua 1 mon \n"; Sleep(sleep); pre(TAB);
	cout << "9.Xem danh sach do uong\n"; Sleep(sleep); pre(TAB);
	cout << "0.Main Menu\n"; Sleep(sleep); pre(TAB);
	br(3); pre(2); cout << "============================================================================================== \n";
	cout << "Moi nhap lua chon: "; Sleep(sleep);
	Sleep(250);*/
}

void Menu::menu_phucvu() {
	system("cls");  br(3); pre(4); cout << ">>>> Nhan vien phuc vu <<<<   \n\n";
	int TAB = 5;
	int sleep = 180;
	pre(TAB);
	printf(" 1. Xem danh sach do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 2. Lam do uong \n\n"); Sleep(sleep); pre(TAB);

	printf(" 0. Main Menu \n\n");
	printf("Enter Your From 1-0: ");
	Sleep(250);
}
string Menu::nhapmk() {
	char c;
	string res = "";
	cout << "Mat khau: ";
	do
	{
		c = _getch();
		if (c == 8) {
			cout << "\b \b";
			if (res == "") continue;
			res = res.substr(0, res.size() - 1);

		}
		else if (c != 13) {
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
		br(2); pre(6); cout << ">> 0. Thoat";  Sleep(400);
		int choise;
		br(2); pre(6); cout << ">> Nhap lua chon: "; cin >> choise;
		cin.ignore();
		switch (choise)
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
	cout << "\t\t THONG KE" << endl;
	cout << "1. Thong ke theo ngay" << endl;
	cout << "2. Thong ke theo thang" << endl;
	cout << "3. Thong ke theo nam" << endl;
	cout << "0. Tro ve" << endl << endl;
	cout << "Nhap lua chon: ";
}
