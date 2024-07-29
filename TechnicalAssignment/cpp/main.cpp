#include <iostream>
#include "lib/include/fsm_mod3.hpp"
#include "lib/include/fsm.hpp"

int main() {
    std::cout << "Remainder of '1101': " << modThree("1101") << std::endl; 
    std::cout << "Remainder of '1110': " << modThree("1110") << std::endl;
    std::cout << "Remainder of '1111': " << modThree("1111") << std::endl;
    return 0;
}