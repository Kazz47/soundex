cmake_minimum_required (VERSION 2.6) 
project (SOUNDEX)

set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(src)

# Sources
add_subdirectory(gtest)
add_subdirectory(test)
