#include <iostream>
#include <algorithm>

class A {
private:
	int* _data;
	int _size;
public:
	// default ctor
	A() : _data(nullptr), _size(0) { }
	// parameterised ctor
	A(int s) : _size(s) {
		_data = new int[_size];
		for (int i = 0; i < _size; ++i) _data[i] = 0;
	}
	// destructor
	~A() {
		delete[] _data;
	}
	// copy ctor
	A(const A& other) : _size(other._size) {
		_data = new int[other._size];
		std::copy(other._data, other._data + _size, _data);
	}
	// move ctor
	A(A&& other) : _data(other._data), _size(other._size) {
		other._data = nullptr;
		other._size = 0;
	}
	// copy assign operator
	A& operator=(const A& other) {
		if (this == &other) return *this;
		delete[] _data;
		_size = other._size;
		_data = new int[_size];
		std::copy(other._data, other._data + _size, _data);
		return *this;
	}
	// move assign operator
	A& operator=(A&& other) {
		if (this == &other) return *this;
		delete[] _data;
		_size = other._size;
		_data = other._data;
		other._data = nullptr;
		other._size = 0;
		return *this;
	}
	// size method
	int size() const {
		return _size;
	}
	// indexer
	int& operator[](int index) {
		return _data[index];
	}
	// indexer const
	const int& operator[](int index) const {
		return _data[index];
	}
};

int main()
{
	std::cout<<"Hello\n";

	A a1;
	A a2(10); // size 10
	A a3 = a2;
	a1 = a3;
	a2 = A(20);
	const A a4(5);
	for(int i=0; i<a2.size(); i++)
	{
		std::cout<<a4[i];
	}

	return 0;
}