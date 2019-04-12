#ifndef PACKAGE_H
#define PACKAGE_H

#include<memory>
#include "box.h"

using SharedBox = std::shared_ptr<Box>;

class Package{
private:
	SharedBox pBox;
	Package* pNext;
public:
	Package(SharedBox pb): pBox{pb},pNext{nullptr} {}
	~Package(){delete pNext;}

	SharedBox getBox(){return pBox;}
	Package* getNext(){return pNext;}
	void setNext(Package* pPackage) {pNext = pPackage;}
};
#endif