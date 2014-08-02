cmake_minimum_required (VERSION 2.6) 
project (SOUNDEX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(src)

# Sources
add_subdirectory(gtest)
add_subdirectory(test)
