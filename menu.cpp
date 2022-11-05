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
	char a = 219, b = 177;
	int SLEEP = 100;
	system("Color 0B");

	pre(10); cout << "Loading ";
	for (int i = 0; i < 30; i++) {
		cout << b;

	}
	cout << "\r"; pre(11);
	for (int i = 0; i < 30; i++) {
		cout << a;
		Sleep(40);
		if (a % 10 == 0) Sleep(25);
	}
}
void Menu::wellcome() {
	ifstream f;

	f.open("hinhcoffee.txt", ios::in);
	br(2);
	while (!f.eof()) {
		system("Color 0A");
		string s;
		getline(f, s);
		pre(10); span(7); cout << s << endl;
	}
	f.close();

	f.open("quanlicoffee.txt", ios::in);
	while (!f.eof()) {
		system("Color 09");
		Sleep(15);
		string s;
		getline(f, s);
		pre(8); span(5); cout << s << endl;
	}
	f.close();
	loadingbar();
}

void Menu::menu_quanli() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 11;

	br(10); pre(TAB); span(6); 
	DoHoa::textColor(224);
	cout << ">>  MENU QUAN LI  <<"; Sleep(SLEEP);

	DoHoa::textColor(14);
	br(2); pre(TAB); cout << ">> 1.  MENU QUAN LI NHAN VIEN <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2.  MENU QUAN LI DO UONG  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3.  MENU THONG KE  <<"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0.  Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);

}
void Menu::menu_quanliDoUong() {
	system("cls");
	const int SLEEP = 60;
	const int TAB = 11;
	br(10); pre(TAB); span(6);
	DoHoa::textColor(240);
	cout << ">>  MENU QUAN LI DO UONG <<"; Sleep(SLEEP);

	DoHoa::textColor(15);
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
	const int TAB = 11;
	br(10); pre(TAB); span(6);
	DoHoa::textColor(176);

	cout << ">>  MENU QUAN LI NHAN VIEN <<"; Sleep(SLEEP);

	DoHoa::textColor(11);
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
	const int TAB = 11;
	br(10); pre(TAB); span(6);
	DoHoa::textColor(112);
	cout << ">>  MENU NHAN VIEN PHUC VU <<"; Sleep(SLEEP);

	DoHoa::textColor(7);
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
	br(1); pre(10);
	DoHoa::textColor(10);
	cout << "Tai khoan: ";
	cin >> tk;
	br(1); pre(10);
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
	const int TAB = 11;
	while (check) {
		system("cls");
		br(10); pre(TAB); span(6);
		DoHoa::textColor(94);

		cout << ">>  DANG NHAP  <<"; Sleep(SLEEP);

		DoHoa::textColor(14);
		br(2); pre(TAB); cout << ">> 1. Nhan vien quan li"; Sleep(SLEEP);
		br(2); pre(TAB); cout << ">> 2. Nhan vien phuc vu"; Sleep(SLEEP);
		br(2); pre(TAB); cout << ">> 0. Thoat";  Sleep(SLEEP);
		int choice;
		br(2); pre(TAB); cout << ">> Nhap lua chon: ";
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
	const int TAB = 11;

	br(10); pre(TAB); span(6);
	DoHoa::textColor(30);
	cout << "    >>  MENU THONG KE <<"; Sleep(SLEEP);

	DoHoa::textColor(14);
	br(2); pre(TAB); cout << ">> 1. Thong ke theo ngay"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 2. Thong ke theo thang"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 3. Thong ke theo nam"; Sleep(SLEEP);
	br(2); pre(TAB); cout << ">> 0. Tro ve";  Sleep(SLEEP);
	br(2); pre(TAB); cout << "->> Nhap lua chon: ";  Sleep(SLEEP);
}
