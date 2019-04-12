#include "oracle.h"



Oracle::Oracle(std::string Name)
{
	Name_Oracle = Name;
}

bool Oracle::marry (human*& M , human*& W) // First input name of man then name of woman.
{
	human* TEST{};

	if(M->spouse == TEST && W->spouse == TEST
		&&M->getAge() >= 18
		&& W-> getAge() >=18)
		{
			M->spouse = W;
			W->spouse = M;
			return true;
		}
	else
	{
		std::cout << (*M).getFirstName() << (*M).getLastName()
		<< " and " << (*W).getFirstName() << (*W).getLastName()
		<<" can't marry together."<<std::endl;
		return false; 
	}
}


void Oracle::setChild(human*& A , human*& B,human*& C)
{
	(*B).List_of_child.push_back(A);
	(*C).List_of_child.push_back(A);
	A->father = B;
	A->mother = C;
}