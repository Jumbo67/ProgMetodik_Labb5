#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    void setMean(double mean) {
        MyFunc::mean = mean;
    }
    double operator()(const Person& person) {
        return person.getAge() + mean;
    }
};

int main() {

    Person personsArray [] = {{"Vincent Johansson", 22}, {"Gillian Persson", 21}, {"Carl olofsson", 23}, {"Andreas Pettersson", 27}, {"Oskar Oskarsson", 31}};
    std::vector<Person> persons_vec(personsArray, personsArray + 5);
    MyPrint print;

    std::cout << "1. For_each" << "\n";
    std::for_each(persons_vec.begin(), persons_vec.end(), [](Person person) {
        MyPrint print;
        print(person);
    });
    
    std::cout << "-------------------" << "\n";
    std::cout << "2. Age greater than 30" << "\n";
    auto found = std::find_if(persons_vec.begin(), persons_vec.end(), ageGreaterThan30());

    if (found != persons_vec.end())
        print(*found);

    found = std::adjacent_find(persons_vec.begin(), persons_vec.end(), equalNames());

    std::cout << "-------------------" << "\n";
    std::cout << "3. Adjacent equal names" << "\n";
    if (found != persons_vec.end())
        print(*found);
    else
        std::cout << "No duplicate adjacent names found" << "\n";

    std::cout << "-------------------" << "\n";
    std::cout << "4. Equality part" << "\n";
    std::cout << (std::equal(persons_vec.begin(), persons_vec.end(), personsArray) ? "They are the same\n" : "They are not the same\n");

    std::cout << "-------------------" << "\n";

    std::cout << "5. Std::search part" << "\n";
    found = std::search(persons_vec.begin(), persons_vec.end(), personsArray, personsArray + 2);
    if (found != persons_vec.end()) {
        for (int i = 0; i < 2; ++i) {
            print(*found);
        }
    }

    std::cout << "---------------------" << "\n";
    std::cout << "6. std::acumulate part" << "\n";

    double mean = std::accumulate(persons_vec.begin(), persons_vec.end(), 0.0, MyBinAccumulate()) / persons_vec.size();
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
    MyFunc func;
    func.setMean(mean);
    std::transform(persons_vec.begin(), persons_vec.end(), v2.begin(), func);
    for(double age : v2) {
        std::cout << age << ", ";
    }

    std::cout << "---------------------" << "\n";
    std::cout << "9. std::Sort" << "\n";

    std::sort(v2.begin(), v2.end());

    for(double age : v2) {
        std::cout << age << ", ";
    }

    return 0;
}
