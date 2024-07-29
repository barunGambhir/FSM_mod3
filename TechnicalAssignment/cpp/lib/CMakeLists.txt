add_library(fsm STATIC fsm.cpp)
add_library(fsm_mod3 STATIC fsm_mod3.cpp)

target_include_directories(fsm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(fsm_mod3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(fsm_mod3 fsm)
