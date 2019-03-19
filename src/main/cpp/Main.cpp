/**
 * CSC232 Data Structures
 * Missouri State University
 * 
 * @file   Main.cpp
 * @author Jim Daehn
 * @brief  Entry point for hw03 target.
 */

#include <cstdlib>
#include <iostream>
#include "BagInterface.h"
#include "ArrayBag.h"
#include "SetArrayBag.h"

int main() {
    std::cout << "Hello, main!" << std::endl;
    BagInterface<int>* bagOfInts = new ArrayBag<int>{};
    bagOfInts->add(1);
    bagOfInts->add(2);
    for (auto item : bagOfInts->toVector()) {
        std::cout << item << std::endl;
    }

    SetArrayBag<int> lhb{};
    lhb.add(100);
    lhb.add(100);

    SetArrayBag<int> rhb{};
    rhb.add(100);
    rhb.add(200);
    rhb.add(300);

    BagInterface<int>& result = lhb.unionWith(rhb);
    std::cout << std::endl << "Union" << std::endl;
    for (auto item : result.toVector()) {
        std::cout << item << std::endl;
    }

    result.clear();

    std::cout << std::endl << "Intersection" << std::endl;
    const BagInterface<int>& result2 = lhb.intersectionWith(rhb);
    for (auto item : result2.toVector()) {
        std::cout << item << std::endl;
    }

    return EXIT_SUCCESS;
}
