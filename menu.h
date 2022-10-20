#pragma once
#include<string>
#include<fstream>
#include<conio.h>
#include"DuLieu.h"
#include<Windows.h>
using namespace std;

class Menu
{public:
	void br(int line) {
		for (int i = 0; i < line; i++) {
			cout << "\n";
		}
	}
	void pre(int tab) {
		for (int i = 0; i < tab; i++) {
			cout << "\t";
		}
	}
	void span(int space) {
		for (int i = 0; i < space; i++) {
			cout << " ";
		}
	}
	void loadingbar() {

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
	void wellcome() {
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
	void menu_quanli() {
		system("cls");  
		br(3); pre(2); cout << "===================================== MENU ===== QUAN ===== LI================================ \n";
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
		Sleep(250);
	}
	void menu_phucvu() {
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
	void main_menu() {
		bool check = true;
		while (check) {
			system("cls");
			br(5); pre(6); cout << "    >>  DANG NHAP  <<"; Sleep(400);
			br(2); pre(6); cout << ">> 1. Nhan vien quan li"; Sleep(400);
			br(2); pre(6); cout << ">> 2. Nhan vien phuc vu"; Sleep(400);
			br(2); pre(6); cout << ">> 3. Thoat";  Sleep(400);
			int choise;
			br(2); pre(6); cout << ">>Nhap lua chon: "; cin >> choise;
			switch (choise)
			{
			case(1): {
				DuLieu data;
				//data.docFileDsDoUong();
				data.docFileDsNhanVien();
				cout << "Nhap ma nhan vien: ";
				string manv;
				cin.ignore();
				getline(cin, manv);

				//nhapmk();
				NhanVienQuanLi nvql = (data.getNvQuanLi())[0];
				if (manv.compare(nvql.getMaNv()) != 0) {
					cout << "Sai tai khoan moi thu lai!!!";
					system("pause");
					break;
				}

				else if (manv.compare(nvql.getMaNv()) == 0 && nhapmk().compare(nvql.getMK()) == 0) {
					nvql.menuQuanLi(data);
					break;
				}
				else {
					cout << "Sai tai khoan hoac mk, moi thu lai!!!";
					system("pause");
					break;
				}
			}
			case(2): {
				DuLieu data;
				data.docFileDsDoUong();
				data.docFileDsNhanVien();
				cout << "Nhap ma nhan vien: ";
				string manv;
				cin.ignore();
				getline(cin, manv);

				//nhapmk();
				NhanVienPhucVu nvpv = (data.getNvPhucVu())[0];
				if (manv.compare(nvpv.getMaNv()) != 0) {
					cout << "Sai tai khoan moi thu lai!!!";
					system("pause");
					break;
				}

				else if (manv.compare(nvpv.getMaNv()) == 0 && nhapmk().compare(nvpv.getMK()) == 0) {
					//NhanVienPhucVu nvpv = (data.getNvPhucVu())[0];
					nvpv.menuPhucvu(data);
					break;
					
				}
				else {
					cout << "Sai tai khoan hoac mk, moi thu lai!!!";
					system("pause");
					break;
				}
			}
			case(3):
			{
			check = false;
			break;

			}
			}

			//   br(2); pre(3); echo("=> 4. Admin Panel");  Sleep(400);



		}
	}

	string nhapmk() {
		char c;
		string res = "";
		cout << "Enter password: " << endl;
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
};


