#include <gtest/gtest.h>
#include "../lib/include/fsm.hpp"
#include "../lib/include/fsm_mod3.hpp"


// tests for the ModThreeFSM methods
TEST(ModThreeFSMTest, ProcessInput) {
    ModThreeFSM fsm;

    // Test for input "1101" -> Expected remainder: 1
    fsm.processInput("1101");
    EXPECT_EQ(fsm.getRemainder(), 1);

    fsm.reset();
    
    // Test for input "1110" -> Expected remainder: 2
    fsm.processInput("1110");
    EXPECT_EQ(fsm.getRemainder(), 2);

    fsm.reset();
    
    // Test for input "1111" -> Expected remainder: 0
    fsm.processInput("1111");
    EXPECT_EQ(fsm.getRemainder(), 0);
}

// tests to check state transitions with different inputs
TEST(FSMTest, StateTransitions) {
    ModThreeFSM fsm;

    // current state = S0, input = 1 -> transition to S1
    fsm.processInput("1");
    EXPECT_EQ(fsm.getCurrentState(), "S1");

    // current state = S1, input = 1 -> transition to S2
    fsm.processInput("0");
    EXPECT_EQ(fsm.getCurrentState(), "S2");

    // current state = S2, input = 1 -> transition to S2
    fsm.processInput("1");
    EXPECT_EQ(fsm.getCurrentState(), "S2");

    // current state = S2, input = 0 -> transition to S1
    fsm.processInput("0");
    EXPECT_EQ(fsm.getCurrentState(), "S1");

    // current state = S1, input = 1 -> transition to S0
    fsm.processInput("1");
    EXPECT_EQ(fsm.getCurrentState(), "S0");

    // current state = S0, input = 0 -> transition to S0
    fsm.processInput("0");
    EXPECT_EQ(fsm.getCurrentState(), "S0");
}

// tests for the modThree function
TEST(modThreeFunctionTest, ModThreeFunction) {

    // empty string -> expected remainder: 0
    EXPECT_EQ(modThree(""), 0);

    // provided input strings
    EXPECT_EQ(modThree("1101"), 1);
    EXPECT_EQ(modThree("1110"), 2);
    EXPECT_EQ(modThree("1111"), 0);

    // large input string: "111...111" (1000 times)
    std::string largeInput(1000, '1'); 
    EXPECT_EQ(modThree(largeInput), 0); //

    largeInput = "10" + largeInput;
    EXPECT_EQ(modThree(largeInput), 2);
}

// tests for handling invalid arguments  
TEST(modThreeInvalidArgs, ModThreeFunction){
    EXPECT_THROW(modThree("102001"), std::invalid_argument);
    EXPECT_THROW(modThree("110a001"), std::invalid_argument); 
    EXPECT_THROW(modThree("111.011"), std::invalid_argument); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
