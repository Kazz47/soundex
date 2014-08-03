include_directories(${GTEST_INCLUDE_DIRS} ${INCLUDE_DIRS})

# Testing Parameters
set(GTEST_SHUFFLE 1)
# set(GTEST_RANDOM_SEED 0-9999)

set(test_sources
    soundexTest
    soundexFuzz
)

add_executable(tests ${test_sources})

# Create dependency of MainTest on googletest
add_dependencies(tests googletest)

target_link_libraries(tests
    ${GTEST_LIBS_DIR}/libgtest.a
	${GTEST_LIBS_DIR}/libgtest_main.a
	pthread
	soundex
)

# Run the Tests
add_custom_command(
    OUTPUT testOut.dat
    COMMAND tests --gtest_shuffle
    COMMENT "Running Tests"
)

add_custom_target(
    RunTest ALL
    DEPENDS testOut.dat
)
