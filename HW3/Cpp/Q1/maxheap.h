#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <sstream>

void sort(std::vector<int>& y);
void display(int* x,int);
int right(int);
int left(int);
void max_heapify(int A[] ,int size,int i);
void build_max_heap(int*& A , int size);
class Maxheap;
std::ostream& operator << (std::ostream& os ,const Maxheap& h);

class Maxheap{
public:
	//Variables:
	int size{};
	int* v{new int [100]};
	//constructors:

	Maxheap(int A[] , int a);  // initializer-list constructor
	Maxheap(); // Default constructor
	Maxheap(const Maxheap& M); //copy constructor
	
	//Destructor:
	~Maxheap();
	//functions:

	void Heapsort();
	void add(int);
	void Delete();
	void printArray();
	int& Max();
	int getHeight();
	int parent(int);
	int LeftChild(int);
	int RightChild(int);

	//operators:

	int& operator [] (int i) const;
	int& operator + ();

private:
	//Variables:
	
	
};

#endif