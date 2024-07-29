#ifndef FSM_MOD3_HPP
#define FSM_MOD3_HPP

#include "fsm.hpp"

// deriving the mod3 FSM class from FSM class 
class ModThreeFSM : public FSM {
public:
    ModThreeFSM();
    int getRemainder() const override;
};

// calculate the mod three value of the input string
int modThree(const std::string& inputString);

#endif // FSM_MOD3_HPP
