#include <iostream>
#include"maxheap.h"

// Based on that PDF you sent us, the first index of
// array in the class is number 1 ... not number 0 ;

int main()
{
	Maxheap h1{};
	h1.add(25);
	h1.add(32);
	h1.add(17);
	h1.add(23);
	h1.add(101);
 	std::cout <<std::endl;

	std::cout << h1 << std::endl;  
	/* 
	101,
	32, 17,
	23, 25
	*/
	std::cout << std::endl;
	std::cout << h1.parent(3) << std::endl; // 101
	std::cout << h1.LeftChild(1) << std::endl;  // 32
	std::cout << h1.RightChild(1) << std::endl;  // 17
	std::cout << std::endl;

	int arr[7] {23, 1, 7, 52, 11, 10, 75};
	Maxheap h2{arr ,7};	
			
	std::cout << h2 << std::endl; 
	std::cout <<"height of h2 is " << h2.getHeight() << std::endl; //2

	Maxheap h3{arr,7};

	h2.Heapsort();
	h2.printArray(); // 75, 52, 23, 11, 10, 7, 1

	
	std::cout << h3.Max()<<std::endl; //75
	h3[1] = h3[1] - 25; 
	//h3.Heapsort();
	std::cout << h3.Max() <<std::endl; //52
	h3.Delete();
	std::cout << h3.Max() << std::endl; //50


		
	return 0;
}


