#ifndef FSM_HPP
#define FSM_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <stdexcept>

class FSM {
protected:
    // Q (states here) is a finite set of states
    std::unordered_set<std::string> states;

    // \sum (alphabet here) is a finite input alphabet
    std::unordered_set<char> alphabet;  

    // q0 (initialState here) \in Q is the initial state
    std::string initialState;  

    // F (finalStates) \subseteq Q is the set of accepting/ final states               
    std::unordered_set<std::string> finalStates;

    // keeping a record of current state of the FSM
    std::string currentState;         

    /* \delta  (currentState) is the transition function
     * maps the states (Q) to a map of finite input alphabet (\sum) 
     * and the resultant state by passing all possible alphabet(s)
    
     * e.g for mod3-FSM states = {S1, S2, S3} and alphabet = {0, 1},
     * S0 maps to {{0, S0}, {1, S1}} as input of 0 to currentState S0, 
     * transitions the state back to S0 and input of 1 to currentState S0, 
     * transitions the state to S1 */

    std::unordered_map<std::string, 
        std::unordered_map<char, std::string>> transitionFunction;

public:
    FSM(const std::unordered_set<std::string>& states, 
        const std::unordered_set<char>& alphabet,
        const std::string& initialState, 
        const std::unordered_set<std::string>& finalStates,
        const std::unordered_map<std::string, 
            std::unordered_map<char, std::string>>& transitionFunction);

    // function to reset FSM to initial state (q0)
    void reset();

    // function to transition the FSM based on the inputString using
    // the transition function
    void processInput(const std::string& inputString);
    
    std::string getCurrentState() const;
    bool isAccepting() const;

    // implement this based on the requirements (e.g mod3-FSM)
    virtual int getRemainder() const = 0;
};

#endif // FSM_HPP
