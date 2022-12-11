//
// Created by vince on 2022-12-10.
//

#include "MyPrint.h"

void MyPrint::operator()(Person person) {
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << "\n";
}
