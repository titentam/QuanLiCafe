#include "Vector.h"

template<typename T>
void Vector <T>::expand(int newCapacity) {
	if (newCapacity <= SIZE) return;
	T* tmp = new T[SIZE];

	for (int i = 0; i < SIZE; i++) {
		tmp[i] = arr[i];
	}

	delete[]arr;
	arr = new T[newCapacity];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
	capacity = newCapacity;
}

template<typename T>
Vector<T>::Vector() {
	this->SIZE = 0;
	this->capacity = 100;
	this->arr = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& another)
{
	this->SIZE = another.size();
	this->capacity = another.cap();
	this->arr = new T[SIZE];
	for (int i = 0; i < SIZE; i++) {
		this->arr[i] = another[i];
	}
}

template<typename T>
Vector<T>::Vector(int initCapacity) {
	this->SIZE = initCapacity;
	this->capacity = initCapacity;
	this->arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
}

template<typename T>
int Vector<T>::size() const {
	return SIZE;
}

template<typename T>
int Vector<T>::cap() const
{
	return this->capacity;
}

template<typename T>
bool Vector<T>::empty() {
	return SIZE == 0;
}

template<typename T>
void Vector<T>::push_back(const T& newElement) {
	if (SIZE == capacity) {
		expand(capacity + capacity / 2);
	}
	arr[SIZE] = newElement;
	SIZE++;
}

template<typename T>
void Vector<T>::pop_back() {
	SIZE--;
}

template<typename T>
void Vector<T>::insert(int pos, const T& newElement) {
	if (SIZE == capacity) {
		expand(capacity + capacity / 2);
	}
	for (int i = SIZE; i > pos; i--) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = newElement;
	SIZE++;
}

template<typename T>
void Vector<T>::erase(int pos) {
	for (int i = pos; i < SIZE - 1; i++) {
		arr[i] = arr[i + 1];
	}
	SIZE--;
}

template<typename T>
void Vector<T>::clearn() {
	SIZE = 0;
}

template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
	if (this != &rhs) {
		delete[] this->arr;
		this->SIZE = rhs.SIZE;
		this->capacity = rhs.capacity;
		this->arr = new T[capacity];
		for (int i = 0; i < SIZE; i++) {
			arr[i] = rhs.arr[i];
		}
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int idx) const {
	return arr[idx];
}
template<typename T>
void Vector<T>::resize(const int& size) {
	T* tmp = new T[SIZE];

	for (int i = 0; i < SIZE; i++) {
		tmp[i] = arr[i];
	}

	delete[]arr;
	arr = new T[size];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
	SIZE = size;
	capacity = size;
}