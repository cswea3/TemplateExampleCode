// Template class for an Array
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array
{
private:

	// size holds the number of elements in the Array
	int size;

	// internal holds a pointer to the first element of the array
	T* internal;

public:

	Array();

	Array(int size);

	Array(const Array &rhs);

	~Array();

	Array operator+(const Array &rhs);

	T getValue(int index) const;

	void setValue(int index, T value);

	friend std::ostream& operator<<(std::ostream& os, const Array &rhs)
	{
		for(int i = 0; i < rhs.getSize(); i++)
		{
			os << rhs.getValue(i);
		}
		return os;
	}

	int getSize() const;

	void operator=(const Array &rhs);

private:
	void init();
};

template<class T>
Array<T>::Array()
{
	init();
}

template<class T>
Array<T>::Array(int size)
{
	init();
	this->size = size;
	internal = new T[size];
}

template<class T>
Array<T>::Array(const Array &rhs)
{
	init();
	*this = rhs;
}

template<class T>
Array<T>::~Array()
{
	delete internal;
}

template<class T>
void Array<T>::operator=(const Array &rhs)
{
	if(this != &rhs)
	{
		init();
		this->size = rhs.getSize();
		this->internal = (size ? new T[size] : NULL);

		for(int i = 0; i < this->size; ++i)
		{
			this->setValue(i,rhs.getValue(i));
		}
	}
}

template<class T>
Array<T> Array<T>::operator+(const Array& b)
{
	Array temp(this->size);
	for(int i = 0; i < this->size; ++i)
	{
		temp.setValue(i, this->getValue(i) + b.getValue(i));
	}

	return temp;
}

template<class T>
void Array<T>::init()
{
	this->size = 0;
	internal = NULL;
}

template<class T>
T Array<T>::getValue(int index) const
{
	return internal[index];
}

template<class T>
void Array<T>::setValue(int index, T value)
{
	internal[index] = value;
}

template<class T>
int Array<T>::getSize() const
{
	return this->size;
}
#endif //ARRAY_HPP
