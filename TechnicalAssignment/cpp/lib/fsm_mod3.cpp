#include "include/fsm_mod3.hpp"

ModThreeFSM::ModThreeFSM()
    : FSM({"S0", "S1", "S2"},  // states
        {'0', '1'}, // alphabet
        "S0",  // initialState
        {"S0", "S1", "S2"}, // finalStates 
        { // transition function
            {"S0", {{'0', "S0"}, {'1', "S1"}}},
            {"S1", {{'0', "S2"}, {'1', "S0"}}},
            {"S2", {{'0', "S1"}, {'1', "S2"}}}
        }) {}

/* dividing by 3 results in 3 possible remainders: 0, 1, 2
 * S0 -> 0
 * S1 -> 1
 * S2 -> 2
*/
int ModThreeFSM::getRemainder() const {
    if (currentState == "S0") return 0;
    if (currentState == "S1") return 1;
    if (currentState == "S2") return 2;
    return -1; 
}

/* initialize the fsm, process the input string and finally return the 
   remainder corressponding to the final state */
int modThree(const std::string& inputString) {
    ModThreeFSM fsm;
    fsm.processInput(inputString);
    return fsm.getRemainder();
}
