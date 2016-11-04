include_directories(${CMAKE_SOURCE_DIR})
add_executable(run_tests testapp.cpp test_idfactory.cpp test_keymap.cpp test_eventmanager.cpp test_componentmanager.cpp test_entity.cpp)
#add_executable(run_tests testapp.cpp test_idfactory.cpp test_keymap.cpp)

target_link_libraries(run_tests cs cppunit)

# Install the executable
install(TARGETS run_tests DESTINATION ${BIN_DIR})
