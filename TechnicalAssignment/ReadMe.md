## How to Build and Run

### Prerequisites

- CMake 3.10 or higher
- Google Test

### Run tests

- To run unit tests, within the TechnicalAssignment directory, run the following commands:

    ```bash
    mkdir build
    cd build
    cmake ../cpp
    make
    ./test/fsm_test

### Run main.cpp

- to run provided test cases, run main.cpp directly by following commands

    ```bash
    clang -o main main.cpp lib/fsm.cpp lib/fsm_mod3.cpp -lstdc++
    ./main