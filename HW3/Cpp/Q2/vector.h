#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <math.h>

void display(int*& , int&);

class Vector {
public:
	//Variables:
	int size{};
	int* arr{new int [size]};
	int capacity{};
	int k{};

	//Constructors:
	Vector(std::initializer_list<int>); //initializer list Constructor.
	Vector()= default;
	Vector(const Vector&); //copy constructor
	Vector( Vector&&);

	//Destructor:
	~Vector();
	//Functions:
	void push_back(int);
	void pop_back();
	void show();

	//Operators:
	Vector operator *(const Vector); //inner Product.
	Vector operator +(const Vector&); //Adding two Vectors.
	bool operator >(const Vector&);
	bool operator <(const Vector&);
	bool operator =(const Vector&);

};

#endif