#include "Date.h"

/// <suthangary>
/// sua date
/// </suthangary>
Date::Date() {
	ngay = thang = nam = "";
}
Date::~Date() {

}
bool Date::check(const string& ngay, const string& thang, const string& nam) {
	int day = (int)(ngay[0]- '0')* 10 + (int)(ngay[1]- '0');
	int month = (int)(thang[0]- '0') * 10 + (int)(thang[1]- '0');
	int year = (int)(nam[0]- '0') * 1000 + (int)(nam[1]- '0') * 100 + (int)(nam[2]-'0') * 10 + (int)(nam[3] - '0');
	switch (month)
	{
	case 1:case 3:case 5: case 7: case 8: case 10: case 12:
		if (day <= 0 || day > 31) return false;
		break;
	case 4: case 6: case 9: case 11:
		if (day <= 0 || day > 30) return false;
		break;
	case 2:
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
			if (day <= 0 || day > 29) return false;
		}
		else if (day <= 0 || day > 29) return false;
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
		cout << "Nhap ngay(dd): "; cin >> ngay;
		cout << "Nhap thang(mm): "; cin >> thang;
		cout << "Nhap nam(yyyy): "; cin >> nam;
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

string Date::getNgay() const {
	return this->ngay;
}
string Date::getThang() const {
	return this->thang;
}
string Date::getNam() const {
	return this->nam;
}

void Date::setNgay(const string& ngay) {
	this->ngay = ngay;
}
void Date::setThang(const string& thang) {
	this->thang = thang;
}
void Date::setNam(const string& nam) {
	this->nam = nam;
}

string Date::convert()
{
	int month = (int)(this->thang[0]-'0') * 10 + (int)(this->thang[1]-'0');
	string res="";
	switch (month)
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
