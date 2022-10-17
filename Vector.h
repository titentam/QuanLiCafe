#pragma once

#include<iostream>
#include<string>


using namespace std;

class NhanVienPhucVu;
class NhanVienQuanLi;
class DoUong;

template<typename T>
class Vector
{
private:
	int SIZE;
	int capacity;
	T* arr;
	void expand(int newCapacity);
public:
	Vector(int initCapacity);
	Vector();
	Vector(const Vector<T>& another);
	~Vector();
	int size() const;
	int cap() const;
	bool empty();
	void push_back(const T& newElement);
	void pop_back();
	void insert(int pos, const T& newElement);
	void erase(int pos);
	void clearn();
	const Vector<T>& operator=(const Vector<T>& rhs);
	T& operator[](int idx) const;
	void resize(const int& size);
};
