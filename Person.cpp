//
// Created by vincent on 2022-12-08.
//

#include "Person.h"



Person::Person() {

}
Person::Person(std::string name, double age) : name(name), age(age){
}


bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name;
}

const std::string &Person::getName() const {
    return name;
}

double Person::getAge() const {
    return age;
}


