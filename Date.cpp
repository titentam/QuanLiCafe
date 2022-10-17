#include "Date.h"

/// <summary>
/// sua date
/// </summary>
Date::Date() {
	ngay = thang = nam = 0;
}
Date::~Date() {

}
bool Date::check(const int& ngay, const int& thang , const int& nam){
	switch (thang)
	{
	case 1:case 3:case 5: case 7: case 8: case 10: case 12:
		if (ngay <= 0 || ngay>31) return false;
		break;
	case 4: case 6: case 9: case 11:
		if (ngay <= 0 || ngay>30) return false;
		break;
	case 2:
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) {
			if (ngay <= 0 || ngay > 29) return false;
		}
		else if (ngay <= 0 || ngay > 29) return false;
		break;
	default:
		return false;
	}
	return true;
}
void Date::nhap() {
	bool ktra = true;
	do
	{
		cout << "NHAP NGAY THANG NAM:" << endl;
		cout << "Nhap ngay: "; cin >> ngay;
		cout << "Nhap thang: "; cin >> thang;
		cout << "Nhap nam: "; cin >> nam;
		ktra = check(ngay, thang, nam);
		if (!ktra) {
			cout << "Ngay thang nam khong hop le, vui long nhap lai !" << endl;
			system("pause");
		}
	} while (!ktra);
}
void Date::xuat() {
	cout << ngay << "/" << thang << "/" << nam << endl;
}
