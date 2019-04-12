#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>

class Box{
private:
	double L{};
	double W{} , H{};
public:
	Box(double l , double w ,double h);
	Box()=default;
	double volume() const;
	int compare(const Box& box) const;
	void listBox() const;

};
#endif