#ifndef ORACLE_H
#define ORACLE_H

#include <iostream>
#include <string>
#include "human.h"

class Oracle {
public:

	//Constructors:
	Oracle(std::string Name);

	
	//Functions:
	bool marry(human*& , human*&);
	void setChild(human*& , human*&, human*&);

private:
	std::string Name_Oracle{};
};

#endif