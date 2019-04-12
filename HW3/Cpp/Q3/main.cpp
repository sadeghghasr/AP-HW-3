#include <iostream>
#include "human.h"
#include "oracle.h"

int main() {



    human* p1{new human {"ALI", "BAHADORI", 4, 3, 25, 0, 0}};
    human* p2{new human {"BAHAR", "SHAMS", 1, 2, 22, 1, 0}};
    human* p3{};

    Oracle o1{"SHERVIN"};
    o1.marry(p1, p2);
    std::cout << (*(p1->spouse)).getFirstName()<< std::endl;
    //married couple
  
 //   std::cout << (*(p2->spouse)).getEyeColor() << std::endl;
    //creating new person*/
    p3 = (*p1) + (*p2);
    if(p3->getGender())
    {
        p3->setFirstName("MAHSHID");
        std::cout<< "girl"<<std::endl;
    }
    else
    {
        p3->setFirstName("FARSHID");
        std::cout << "boy"<<std::endl;
    }

    p3++;

    human* p4{new human {"SHAHIN", "REZAEE", 0, 5, 58, 1, 1}};
    human* p5{new human {"FARHAD", "BAHADORI", 0, 6, 63, 0, 1}};


    o1.setChild(p1, p4, p5);
  /*   //setting the firstname of newborn
    if(p3->getGender())
        p3->setFirstName("MAHSHID");
    else
        p3->setFirstName("FARSHID");


    //increasing the age of newborn
    p3++;

    Human* p4{new Human {"SHAHIN", "REZAEE", 0, 5, 58, 1, 1}};
    Human* p5{new Human {"FARHAD", "BAHADORI", 0, 6, 63, 0, 1}};


    o1.setChild{p1, p4, p5};

    if(o1.isFamily(p3, p5)) {
        std::cout << "the population of family is: " << o1.getPopulationOfFamily(p4) << endl;
        Human** f1{o1.getFamily(p3)};
        std::cout << "the name of each member of family: " ;
        for(int i{0}; i < o1.getPopulationOfFamily; i++) {
            std::cout << f1[i]->getFirstName() << " ";
        }
        std::cout << endl;
    }
*/

    return 0;
}
