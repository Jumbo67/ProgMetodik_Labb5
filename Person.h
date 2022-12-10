//
// Created by vincent on 2022-12-08.
//

#ifndef PROGMETODIK_LABB5_PERSON_H
#define PROGMETODIK_LABB5_PERSON_H

#include <iostream>

class Person {
    std::string name;

private:
    double age;

public:
    Person() = delete;
    Person(std::string name, double age);

    const std::string &getName() const;
    double getAge() const;


    friend bool operator==(const Person& lhs, const Person& rhs);
};


#endif //PROGMETODIK_LABB5_PERSON_H
