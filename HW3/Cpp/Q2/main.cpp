#include <iostream>
#include "vector.h"


int main()
{
	Vector v{1,2,3,4,5,6,7,8,9,10};
	Vector v1{10,9,8,7,6,5,4,3,2,1};
	Vector b{std::move(v1)};
	//while(v1 < v)
	//	v1.push_back(1);
	std::cout <<v.size<<std::endl;
//	v1.show();
	b.show();
	
	v.show();
	return 0;
}