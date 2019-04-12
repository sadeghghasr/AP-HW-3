#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

class Truckload
{
private:
	Package* pHead{};
	Package* pTail{};
	Package* pCurrent{};
public:
	Truckload() = default;
	Truckload(SharedBox pBox){pHead = pTail = new Package{pBox};}
}