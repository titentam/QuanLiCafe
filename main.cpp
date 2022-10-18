#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>
#include<conio.h>
#include<Windows.h>


using namespace std;


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
void menu_quanli() {
	system("cls");  br(3); pre(4); cout << ">>>> Nhan vien quan li <<<<   \n\n";
	int TAB = 5;
	int sleep = 180;
	pre(TAB);
	printf(" 1. Doanh thu \n\n"); Sleep(sleep); pre(TAB);
	printf(" 2. Them do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 3. Xoa do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 4. Chinh sua do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 5. Xem danh sach do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 6. Them nhan vien phuc vu \n\n"); Sleep(sleep); pre(TAB);
	printf(" 7. Xoa nhan vien phuc vu\n\n"); Sleep(sleep); pre(TAB);
	printf(" 8. Chinh sua nhan vien phuc vu\n\n"); Sleep(sleep); pre(TAB);
	printf(" 0. Main Menu \n\n");
	printf("Enter Your From 1-0: ");
	Sleep(250);
}
void menu_phucvu() {
	system("cls");  br(3); pre(4); cout << ">>>> Nhan vien phuc vu <<<<   \n\n";
	int TAB = 5;
	int sleep = 180;
	pre(TAB);
	printf(" 1. Xem danh sach do uong \n\n"); Sleep(sleep); pre(TAB);
	printf(" 2. Xuat hoa don \n\n"); Sleep(sleep); pre(TAB);
	printf(" 0. Main Menu \n\n");
	printf("Enter Your From 1-0: ");
	Sleep(250);
}
void main_menu() {

	system("cls");
	br(5); pre(6); cout << "    >>  DANG NHAP  <<"; Sleep(400);
	br(2); pre(6); cout << ">> 1. Nhan vien quan li"; Sleep(400);
	br(2); pre(6); cout << ">> 2. Nhan vien phuc vu"; Sleep(400);
	br(2); pre(6); cout << ">> 3. Thoat";  Sleep(400);
	//   br(2); pre(3); echo("=> 4. Admin Panel");  Sleep(400);

	br(1);

}

void nhapmk() {
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
	cout << endl << res;
}
int main() {
	//DuLieu data;
	//data.docFileDsDoUong();
	//data.docFileDsNhanVien();
	//

	//NhanVienQuanLi nvql;
	//nvql = (data.getNvQuanLi())[0];

	//nvql.xemDsNV(data);
	///*
	//nvql.themNV(data, { "01asdad","Tam Ten Toi","8123712738127","tamcute","12312h",2 });
	//cout << endl;
	//nvql.xemDsNV(data);*/
	//
	///*nvql.xemDsDoUong(data);
	//DoUong ncdua(19, "Nuoc dua", 10000, 100, "Nuoc trai cay");
	//nvql.themMon(data, ncdua);
	//cout << endl;
	//nvql.xemDsDoUong(data);*/
	//nvql.xemDsDoUong(data);
	//cout << endl;
	//nvql.xoaMon(data, 12);
	//cout << endl;
	//nvql.xemDsDoUong(data);
	wellcome();
	loadingbar();
	main_menu();
	menu_quanli();
	menu_phucvu();
	nhapmk();
	
	return 0;
}