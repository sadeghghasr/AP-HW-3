#include<vector>
#include <iomanip>
#include "maxheap.h"


Maxheap::Maxheap(int A[] , int a){
	v[0]=0;
	size =1;
	for (int i{} ; i < a ;i++)
	{
		v[size] = A[i];
		size++;
	}

	build_max_heap(v,size);

	
}
Maxheap::Maxheap()
{
	size++;
}

Maxheap::Maxheap(const Maxheap& H) // Copy constructor
{
	this->size = H.size;
	for (int j{1}; j < H.size; j++)
	{
		this->v[j] = H.v[j];
	}
}

int Maxheap::parent(int y)
{
	return v[(y/2)];
}

int Maxheap::LeftChild(int i)
{
	if(i > ((size -1 )/2))
	{
		std::cout << "index ["<< i << "] , doesn't have any left child" <<std::endl;
		return 0;
	}

	else
		return v[2 * i];
	
}

int Maxheap::RightChild(int i)
{
	if (i >= (size / 2))
	{
		std::cout << "index [" << i << "] , doesn't have any right child" <<std::endl;
		return 0;
	}
	else
		return v[2 * i + 1];
}

void Maxheap::printArray()
{
	display(v,size);
}

void Maxheap::add(int x){
	v[size] = x;
	size++;
	build_max_heap(v,size);
}

void Maxheap::Delete()
{
	build_max_heap(v,size);
	for(int i{} ; i < size -1 ; i++)
	{
		if(i == 0)
			continue;
		int temp2{v[i+1]};
		v[i] = temp2;
	}
	size--;
	build_max_heap(v,size);
}

int& Maxheap::Max()
{
	Heapsort();
	return v[1];
}

int Maxheap::getHeight()
{
	return (log(size - 1)) / log(2) ;
}

void Maxheap::Heapsort()
{
	for(int i{1}; i < size ; i++)
	{
		for(int j{1}; j < size; j++)
		{
			if (v[i] > v[j])
			{
				int temp{v[i]};
				v[i] = v[j];
				v[j] = temp;


			}
		}

	}
}

int& Maxheap::operator [] (int i) const
{
	return v[i];
}

int& Maxheap::operator + ()
{
//	v[i] = v[i] - x;
	build_max_heap(v , size);
	std::cout <<"hi";
	return v[2];
}

Maxheap::~Maxheap()
{
	delete[] v;
}
std::ostream& operator << (std::ostream& os ,const Maxheap& h)
{
	for(int i{1} ; i <= log2 (h.size) + 1 ; i++)
	{
		for (int j{static_cast<int>(std::pow(2,i-1))} ; j < std::pow(2 ,i) ; j++)
		{
			if(j > h.size - 1)
				break;
			else
				os << h[j];
			if(j != h.size -1)
				os << " , ";
		}
		if(i != log2(h.size) + 1)
			os << std::endl;
	}
	return os;
}
void max_heapify(int A[] ,int size,int i){
	int l {left(i)};
	int r{right(i)};
	int largest{};

	if(l <= size && A[l] > A[i])
		largest = l;
	else largest =i ;

	if (r<= size && A[r] > A[largest])
		largest = r;
	if (largest != i )
	{
		//swap A[i] and A[largest].
		int  temp{A[i]};
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify(A,size, largest); 

	}
	
}

void build_max_heap(int*& A , int size)
{
	for (int i{size/2} ; i > 0 ; i--)
		max_heapify(A , size , i);
}

void display(int* x ,int size){
	for (int j{1}; j < size; j++)
		std::cout << x[j] << ",";
	std::cout << std::endl;
}

int paternt(int i)
{
	return ((i)/2);
}

int right(int i)
{
	return 2*i + 1;
}

int left(int i)
{
	return 2*i;
}