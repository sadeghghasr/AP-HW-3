#include <initializer_list>
#include "vector.h"



Vector::Vector(std::initializer_list<int> li)
{
	std::initializer_list<int>::iterator it{li.begin()};
	for(size_t i{}; i < li.size() ;i++)
	{
		size++;
	}
	delete this->arr;
	this->arr = new int [size];
	
	for(int i{} ;i<size ;i++)
	{
		arr[i] = *it++;
	}
}

Vector::Vector(const Vector& V)
{
	std::cout<<"copy constructor"<<std::endl;
	size = V.size;
	for(int i{}; i< V.size;i++)
	{
		arr[i] = V.arr[i];
	}
}

Vector::Vector(Vector&& V)
{
	std::cout << "move constructor" <<std::endl;
	size = V.size;
	arr = V.arr;
	V.arr = nullptr;
}

void Vector::push_back(int x)
{
	if(size == 0)
   	 k =1;
	size++;
	int* p{new int [size]};
	p = this->arr;
	this->arr = nullptr;
	delete[] arr;
	this->arr = p;
	p=nullptr;
	delete[] p;
	arr[size - 1] = x;
	if(size < std::pow(2,k))
    	capacity = (std::pow(2,k));
  	if(size == std::pow(2,k))
	{
   	 capacity = size;
  	  k++;
	}

}

void Vector::pop_back()
{
	size--;
	int* p{new int [size]};
	p = this->arr;
	this->arr = nullptr;
	delete[] arr;
	this->arr = p;
	p=nullptr;
	delete[] p;
	if(size == std::pow(2,k-1))
	{
   	 capacity = size;
  	  k--;
	}

}

Vector Vector::operator *(const Vector A)
{
	if(A.size == this->size)
	{
		Vector Temp{};
		Temp.size = A.size;
		Temp.arr=new int [A.size];
		
		for (int i{}; i<A.size ;i++)
		{
			Temp.arr[i] = A.arr[i] * this->arr[i];
		}
		return Temp;
	}
	else
	{
		std::cout <<"No Matching to Product and the first Vector is :"<< std::endl;
		return *this;
	}

}

bool Vector::operator >(const Vector& V)
{
	return this->size > V.size;
}

bool Vector::operator <(const Vector& V)
{
	return this->size < V.size;
}

bool Vector::operator =(const Vector& V)
{
	return this->size == V.size;
}


Vector Vector::operator +(const Vector& A)
{
	if(A.size == this->size)
	{
		Vector Temp{};
		Temp.size = A.size;
		Temp.arr=new int [A.size];

		for (int i{}; i<A.size ;i++)
		{
			Temp.arr[i] = A.arr[i] + this->arr[i];
		}
		return Temp;
	}
	else
	{
		std::cout <<"No Matching to Add and the first Vector is :"<< std::endl;
		return *this;
	}

}

void Vector::show()
{
	display(arr, size);
}

Vector::~Vector()
{
	delete[] arr;
}

void display(int*& arr , int& size)
{
	for(int i{} ; i < size;i++)
	{
		std::cout << arr[i] << " ,";
	}
	std::cout<<std::endl;
}

