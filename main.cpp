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


int main() {
    std::vector<Person> persons;
    MyPrint print;

    persons.push_back({"Vincent Johansson", 22});
    persons.push_back({"Gillian Persson", 21});
    persons.push_back({"Andreas Perkuleel", 27});
    persons.push_back({"Anton oskarsson", 30});
    persons.push_back({"Pita Rolifsson", 31});

    std::cout << "For_each" << "\n";
    std::for_each(persons.begin(), persons.end(), [](Person person) {
        MyPrint print;
        print(person);
        std::cout << "\n";
    });

    std::cout << "Age greater than 30" << "\n";
    auto found = std::find_if(persons.begin(), persons.end(), ageGreaterThan30());

    if (found != persons.end())
        print(*found);




    return 0;
}
