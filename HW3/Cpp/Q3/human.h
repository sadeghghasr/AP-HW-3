#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>

class human;
void sort(std::vector<human*>& V);

class human{
public:
	//Variables:
	std::vector <human*> List_of_child{};
	human* father{};
	human* mother{};
	human* spouse{};
	int population{};

	//Constructors:
	human(std::string fistName , std::string lastName , int hairColor , int eyeColor , int age
		, bool gender , int numberOfChildren);
	
	human(const human&);
	human() = default;
	// Functions:
	std::string getFirstName() const;
	std::string getLastName() const;
	bool getGender() const;
	int getHairColor() const;
	int getEyeColor() const;
	int getAge() const;
	int getNumberOfChildren() const;
	void setFirstName(std::string s){first_Name = s;};
	void setLastName(std::string s){last_Name = s;};
	void setHairColor(int s){hair_Color = s;};
	void setEyeColor(int s){eye_Color = s;};
	void setAge(int s){Age = s;};
	void setGender(bool s){Gender = s;};
	void setNumberOfChildren(int s){numberOfChildren = s;};
	bool isChildOf(human*&);
	bool isFatherOf(human*&);
	bool isMotherOf(human*&);
	void printChildren();
	human getSpouse() const {return *spouse ;};

	//Operators:
	bool operator > (human&);
	bool operator == (human&);
	human* operator=(human*&);
	human* operator+(human&);
	void operator++();
	
private:
	std::string first_Name{};
	std::string last_Name{};
	int hair_Color{};
	int eye_Color{};
	int Age{};
	bool Gender{} ;
	int numberOfChildren{};


};

#endif