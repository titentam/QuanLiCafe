#pragma once
#include<iostream>
#include"DuLieu.h"
#include<fstream>
#include<conio.h>
#include<Windows.h>



using namespace std;



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
	int sleep = 100;
	pre(TAB);
	cout<<(" 1. Doanh thu \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 2. Them do uong \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 3. Xoa do uong \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 4. Chinh sua do uong \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 5. Xem danh sach do uong \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 6. Them nhan vien phuc vu \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 7. Xoa nhan vien phuc vu\n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 8. Chinh sua nhan vien phuc vu\n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 0. Main Menu \n\n");
	cout<<("Enter Your From 1-0: ");
	Sleep(250);
}
void menu_phucvu() {
	system("cls");  br(3); pre(4); cout << ">>>> Nhan vien phuc vu <<<<   \n\n";
	int TAB = 5;
	int sleep = 100;
	pre(TAB);
	cout<<(" 1. Xem danh sach do uong \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 2. Xuat hoa don \n\n"); Sleep(sleep); pre(TAB);
	cout<<(" 0. Main Menu \n\n");
	cout<<("Enter Your From 1-0: ");
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
int main() {
	\
	DuLieu data;
	data.docFileDsDoUong();
	data.docFileDsNhanVien();
	//data.xuatFileDsDoUong(cout);
	cout << endl;

	Vector<DoUong> &menu = data.getDoUong();
	
	NhanVienPhucVu tam = (data.getNvPhucVu())[0];
	Vector<DoUong> dsdouong;
	Vector<int> sl;
	// 12
	// tim do uong co ma 12 -> them dsdouong , them -> soluong
	dsdouong.push_back(menu[2]);
	sl.push_back(70);

	dsdouong.push_back(menu[3]);
	sl.push_back(80);

	dsdouong.push_back(menu[5]);
	sl.push_back(50);

	tam.lamDoUong(data, dsdouong, sl);
	tam.xuatBill(cout, dsdouong, sl);
	//data.xuatFileDsDoUong(cout);
	/*ofstream f;
	string t = "TAM\\ti\\tamtentoi.txt";
	f.open(t, ios::out);
	tam.xuatBill(f, dsdouong, sl);
	f.close();*/

	

	return 0;
}