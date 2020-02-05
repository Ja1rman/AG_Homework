#include <iostream>

using namespace std;

struct Array
{
    int size;
	int* data;
    Array() {}
    Array(int x)
    {
		size = x;
		data = new int[size];
	}

	Array(const Array& A)
	{
		if (this != &A)
		{
			size = A.size;
			data = new int[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = A.data[i];
			}
		}
	}

	~Array() {
		delete[] data;
	}

	Array& operator= (const Array A)
	{
		if (this == &A)
			return *this;
		delete [] data;
		size = A.size;
		data = new int[size];

		for (int i = 0; i < size; i++)
			data[i] = A.data[i];

		return *this;
	}

	int& operator[] (int i) {
		if (i < 0 || i >= size) {
			std::cout << "Err";
			return data[0];
		}
		return data[i];
	}
};


struct Vector
{
	int size;
	int* data;
	int capacity;

	Vector() {}

	Vector(int x)
	{
		size = x;
		capacity = x;
		data = new int[capacity];
	}

	Vector(const Vector& A)
	{
	    if (this != &A)
	    {
    		size = A.size;
    		capacity = A.capacity;
    		data = new int[capacity];
    		for (int i = 0; i < size; i++)
    		{
    			data[i] = A.data[i];
    		}
	    }
	}

	~Vector()
	{
		delete[] data;
	}

	int& operator[] (int i)
	{
		if (i < 0 || i >= size)
			return data[0];

		return data[i];
	}

	int& Size() {
		return size;
	}

	int& Capacity() {
		return capacity;
	}

	Vector& operator= (const Vector A) {
		if (this = &A)
		    return *this;

		delete[] data;
		size = A.size;
		capacity = A.capacity;
		int* data;
		data = new int[capacity];

		for (int i = 0; i < size; i++)
			data[i] = A.data[i];

		return *this;
	}

	void push_back(int x) {
		if (size == capacity)
		{
			capacity *= 2;
			double* temp = new int[capacity];
			for (int i = 0; i < size; i++)
				temp[i] = data[i];

			delete[] data;
			data = temp;
		}
		data[size] = x;
		size++;
	}

	void resize(int x)
	{
		int* temp = new int[x];
		for(int i = 0; i < size && i < x; i++)
			temp[i] = data[i];

		delete[] data;

		capacity = x;
		data = temp;
		if (size < capacity) {
			size = capacity;
		}
	}
};


int main()
{


	return 0;
}
