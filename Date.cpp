#include "Date.h"

/// <suthangary>
/// sua date
/// </suthangary>
Date::Date() {
	ngay = thang = nam = 0;
}
Date::~Date() {

}
bool Date::check(const int& ngay, const int& thang, const int& nam) {
	switch (thang)
	{
	case 1:case 3:case 5: case 7: case 8: case 10: case 12:
		if (ngay <= 0 || ngay > 31) return false;
		break;
	case 4: case 6: case 9: case 11:
		if (ngay <= 0 || ngay > 30) return false;
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

int Date::getNgay() const {
	return this->ngay;
}
int Date::getThang() const {
	return this->thang;
}
int Date::getNam() const {
	return this->nam;
}

void Date::setNgay(const int& ngay) {
	this->ngay = ngay;
}
void Date::setThang(const int& thang) {
	this->thang = thang;
}
void Date::setNam(const int& nam) {
	this->nam = nam;
}

string Date::convert()
{
	string res = "";
	switch (this->thang)
	{
	case 1:
		res = "Jan";
		break;
	case 2:
		res = "Feb";
		break;
	case 3:
		res = "Mar";
		break;
	case 4:
		res = "Apr";
		break;
	case 5:
		res = "May";
		break;
	case 6:
		res = "Jun";
		break;
	case 7:
		res = "Jul";
		break;
	case 8:
		res = "Aug";
		break;
	case 9:
		res = "Sep";
		break;
	case 10:
		res = "Oct";
		break;
	case 11:
		res = "Nov";
		break;
	case 12:
		res = "Dec";
		break;
	default:
		res = "ERROR";
		break;
	}
	return res;
}
