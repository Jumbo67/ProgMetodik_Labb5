#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
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

struct MyBinAccumulate {
    double operator()(const double& sum, const Person& person) {
        return sum + person.getAge();
    }
};

struct MyUnOp {
    double operator()(const Person& person) {
        return person.getAge();
    }
};

class MyFunc {

    double mean;

public:
    explicit MyFunc(double mean) : mean(mean) {}
    double operator()(const Person& person) {
        return person.getAge() - mean;
    }
};

int main() {

    srand(time(nullptr));

    std::vector<std::string> names = {"Vincent Johansson", "Vincent Johansson", "Carl Olofsson", "Andreas Pettersson", "Oskar Oskarsson"};

    Person personsArray [5];

    MyPrint print;

    std::generate(std::begin(personsArray), std::end(personsArray), [&names]() {
        std::string name = names.back();
        names.pop_back();
        return Person(name, rand() % 15 + 20);
    });

    std::vector<Person> persons_vec(std::begin(personsArray), std::end(personsArray));

    std::cout << "1. For_each" << "\n";
    std::for_each(persons_vec.begin(), persons_vec.end(), print);
    
    std::cout << "-------------------" << "\n";
    std::cout << "2. std::find_if age greater than 30" << "\n";
    auto found = std::find_if(persons_vec.begin(), persons_vec.end(), ageGreaterThan30());

    if (found != persons_vec.end())
        print(*found);
    else
        std::cout << "No person with age greater than 30" << "\n";

    std::cout << "-------------------" << "\n";
    std::cout << "3. Adjacent equal names" << "\n";
    found = std::adjacent_find(persons_vec.begin(), persons_vec.end());
    if (found != persons_vec.end())
    std::cout << found->getName() << "\n";
    else
        std::cout << "No duplicate adjacent names found" << "\n";

    std::cout << "-------------------" << "\n";
    std::cout << "4. Equality part" << "\n";
    std::cout << (std::equal(persons_vec.begin(), persons_vec.end(), personsArray) ? "They include the same names\n" : "They are not the same\n");

    std::cout << "-------------------" << "\n";

    std::cout << "5. Std::search part" << "\n";
    found = std::search(persons_vec.begin(), persons_vec.end(), personsArray, personsArray + 2);
    if(found != persons_vec.end())
        std::for_each(found, found + 2, print);
    else
        std::cout << "Subsequence not found" << "\n";

    std::cout << "---------------------" << "\n";
    std::cout << "6. std::accumulate part" << "\n";

    double mean = std::accumulate(persons_vec.cbegin(), persons_vec.cend(), double(), MyBinAccumulate()) / persons_vec.size();
    std::cout << "Mean: " << mean << "\n";

    std::cout << "---------------------" << "\n";
    std::cout << "7. std::transform" << "\n";
    std::vector<double> v2(persons_vec.size());
    std::transform(persons_vec.begin(), persons_vec.end(), v2.begin(), MyUnOp());

    for(double age : v2) {
        std::cout << age << ", ";
    }
    std::cout << "\n";


    std::cout << "---------------------" << "\n";
    std::cout << "8. std::transform" << "\n";
    std::transform(persons_vec.begin(), persons_vec.end(), v2.begin(), MyFunc(mean));
    for(double age : v2) {
        std::cout << age << ", ";
    }

    std::cout << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << "9. std::Sort" << "\n";

    std::sort(v2.begin(), v2.end());

    for(double age : v2) {
        std::cout << age << ", ";
    }

    return 0;
}
