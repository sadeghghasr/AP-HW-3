#include "box.h"

Box::Box(double l,double w,double h)
{
	L=l;
	W=w;
	H=h;
}

double Box::volume() const
{
	return L*W*H;
}

int Box::compare(const Box& box) const
{
	if(volume() < box.volume()) 
		return -1;
	if(volume() == box.volume())
		return 0;
	return +1;
}

void Box::listBox() const
{
	std::cout<< "Box("<<std::setw(2)<<L<<','<<std::setw(2)
	<<W<<','<<std::setw(2)<<H<<')';
}