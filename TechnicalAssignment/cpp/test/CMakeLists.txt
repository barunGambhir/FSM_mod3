enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(fsm_test fsm_test.cpp)

target_link_libraries(fsm_test ${GTEST_LIBRARIES} pthread fsm fsm_mod3)

add_test(NAME ModThreeFSMTest COMMAND fsm_test)
