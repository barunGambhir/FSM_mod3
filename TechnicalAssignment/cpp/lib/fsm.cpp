#include "include/fsm.hpp"

FSM::FSM(const std::unordered_set<std::string>& states, 
        const std::unordered_set<char>& alphabet,
        const std::string& initialState, 
        const std::unordered_set<std::string>& finalStates,
        const std::unordered_map<std::string, 
            std::unordered_map<char, std::string>>& transitionFunction)
        : states(states), 
        alphabet(alphabet), 
        initialState(initialState), 
        finalStates(finalStates),
        transitionFunction(transitionFunction), 
        // set current state to the initial state
        currentState(initialState) {}  
        
void FSM::reset() {
    currentState = initialState;
}

void FSM::processInput(const std::string& inputString) {
    for (char input : inputString) {
        if (alphabet.find(input) == alphabet.end()) {
            throw std::invalid_argument("Input symbol not in the alphabet");
        }

        // find the state in the transition function
        auto state = transitionFunction.find(currentState);
        if (state == transitionFunction.end()) {
            throw std::invalid_argument("Current state not in transition function");
        }

        // find the alphabet value (input) corresponding to the state
        auto alpha = state->second.find(input);
        if (alpha == state->second.end()) {
            throw std::invalid_argument("Transition not defined for this input symbol");
        }

        //set current state to next state corresponding to alpha
        currentState = alpha->second;
    }
}

std::string FSM::getCurrentState() const {
    return currentState;
}

bool FSM::isAccepting() const {
    return finalStates.find(currentState) != finalStates.end();
}
