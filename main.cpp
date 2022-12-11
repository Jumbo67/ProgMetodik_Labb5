#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "MyPrint.h"



struct ageGreaterThan30 {
    bool operator()(const Person& person) {
        return person.getAge() > 30;
    }
};

struct equalNames{
    bool operator()(const Person& lhs, const Person& rhs) {
        return lhs.getName() == rhs.getName();
    }
};


int main() {

    Person personsArray [] = {{"Vincent Johansson", 22}, {"Gillian Persson", 21}, {"Carl olofsson", 23}, {"Andreas Pettersson", 27}, {"Oskar Oskarsson", 31}};
    std::vector<Person> persons(personsArray, personsArray + 5);
    MyPrint print;

    std::cout << "For_each" << "\n";
    std::for_each(persons.begin(), persons.end(), [](Person person) {
        MyPrint print;
        print(person);
    });

    std::cout << "Age greater than 30" << "\n";
    auto found = std::find_if(persons.begin(), persons.end(), ageGreaterThan30());

    if (found != persons.end())
        print(*found);

    found = std::adjacent_find(persons.begin(), persons.end(), equalNames());

    std::cout << "Adjacent equal names" << "\n";
    if (found != persons.end())
        print(*found);
    else
        std::cout << "No duplicate adjacent names found" << "\n";

    std::cout << "Equality part" << "\n";
    std::cout << (std::equal(persons.begin(), persons.end(), personsArray)? "They are the same":"They are not the same");

    std::cout << "\n";


    std::cout << "Std::search part" << "\n";
    found = std::search(persons.begin(), persons.end(), personsArray, personsArray + 2);

    if (found != persons.end()) {
        for (int i = 0; i < 2; ++i) {
            print(*(found+i));
        }
    }

    return 0;
}
