include_directories(${GTEST_INCLUDE_DIRS})

set(test_sources
    simple
)

add_executable(tests ${test_sources})

# Create dependency of MainTest on googletest
add_dependencies(tests googletest)

target_link_libraries(tests
    ${GTEST_LIBS_DIR}/libgtest.a
	${GTEST_LIBS_DIR}/libgtest_main.a
	pthread
)

# Run the Tests
add_custom_command(
    OUTPUT testOut.dat
    COMMAND tests
    COMMENT "Running Tests"
)

add_custom_target(
    RunTest ALL
    DEPENDS testOut.dat
)