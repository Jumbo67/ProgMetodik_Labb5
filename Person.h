//
// Created by vincent on 2022-12-08.
//

#ifndef PROGMETODIK_LABB5_PERSON_H
#define PROGMETODIK_LABB5_PERSON_H

#include <iostream>

class Person {
    std::string name;
    double age;

public:
    Person() = delete;
    Person(std::string name, double age);

    friend bool operator==(const Person& lhs, const Person& rhs);
};


#endif //PROGMETODIK_LABB5_PERSON_H
