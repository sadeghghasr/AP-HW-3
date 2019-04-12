#include <iostream>
#include <string>

#include "human.h"


human::human(std::string firstName , std::string lastName , int hairColor , int eyeColor , int age
		, bool gender , int numberOfChildren)
{
	first_Name = firstName;
	last_Name = lastName;
	hair_Color = hairColor;
	eye_Color = eyeColor;
	Age = age;
	Gender = gender;
	numberOfChildren = numberOfChildren;
}

human::human(const human& K)
{

	
	first_Name = K.getFirstName();
	last_Name = K.getLastName();
	hair_Color = K.getHairColor();
	eye_Color = K.getEyeColor();
	Age = K.getAge();
	Gender = K.getGender();
	numberOfChildren = K.getNumberOfChildren();
}

bool human::getGender() const{return Gender;}
int human::getHairColor() const{return hair_Color;}
int human::getEyeColor() const{return eye_Color;}
int human::getAge() const{return Age;}
std::string human::getFirstName() const{return first_Name;}
std::string human::getLastName() const{return last_Name;}
int human::getNumberOfChildren() const{return numberOfChildren;}

bool human::operator > (human& H)
{
	return Age > H.getAge();

}

human* human::operator+(human& H)
{
	human* child{new human{}};
	if(*this->spouse == H)
	{
		child->setLastName(last_Name);
		int random{rand() % 100}; //random number between 0 and 99.
		if(random > 50)
		{
			child->setFirstName("boy");
			child->setGender("0");
		}
		else
		{
			child->setFirstName("girl");
			child->setGender("1");
		}
		random = rand() %100;
		if(random > 50)
		{
			child->setHairColor(hair_Color);
			child->setEyeColor(eye_Color);
		}
		else
		{
			child->setHairColor(H.getHairColor());
			child->setEyeColor(H.getEyeColor());
		}
		return child;
	}
	else
	{
		std::cout <<"they can't have a child"<<std::endl;
		return nullptr;
	}
}

bool human::operator== (human& H)
{
	return Gender == H.getGender() &&
		   hair_Color == H.getHairColor() &&
		   eye_Color ==H.getEyeColor() &&
		   Age == H.getAge() &&
		   first_Name == H.getFirstName() &&
		   last_Name == H.getLastName() &&
		   numberOfChildren == H.getNumberOfChildren() ;
}

human* human::operator= (human*& K)
{
	first_Name = K->getFirstName();
	last_Name = K->getLastName();
	hair_Color = K->getHairColor();
	eye_Color = K->getEyeColor();
	Age = K->getAge();
	Gender = K->getGender();
	numberOfChildren = K->getNumberOfChildren();
	return this;
}

void human::operator++()
{
	Age++;
}

bool human::isChildOf(human*& H)
{
	bool TEST{0};
	for(size_t i{} ; i < H->List_of_child.size() ; i++)
	{
		if(this == H->List_of_child[i])
		{
			TEST = 1;
			break;
		}
	}
	return TEST;
}

bool human::isFatherOf(human*& H)
{
	bool TEST{0};
	for(size_t i{} ; i < this->List_of_child.size() ; i++)
	{
		if(H == this->List_of_child[i] && Gender == 0)
		{
			TEST = 1;
			break;
		}
	}
	return TEST;
}

bool human::isMotherOf(human*& H)
{
	bool TEST{0};
	for(size_t i{} ; i < this->List_of_child.size() ; i++)
	{
		if(H == this->List_of_child[i] && Gender == 1)
		{
			TEST = 1;
			break;
		}
	}
	return TEST;
}

void human::printChildren()
{
	sort(List_of_child);
	for(size_t i{} ; i < List_of_child.size(); i++)
	{
		std::cout << List_of_child[i] ->getFirstName() << " " << 
		List_of_child[i] ->getLastName() <<" ,"<< std::endl;
	}

}

void sort(std::vector<human*>& V)
{
	for(size_t i{1}; i < V.size() ; i++)
	{
		for(size_t j{1}; j < V.size(); j++)
		{
			if (V[i]->getAge() > V[j] ->getAge())
			{
				human* temp{V[i]};
				V[i] = V[j];
				V[j] = temp;
			}
		}

	}
}
