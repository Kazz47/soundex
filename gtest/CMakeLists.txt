include(ExternalProject)
  
# Add gtest
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/smarr/googletest.git
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    # Disable install step
    INSTALL_COMMAND ""
)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR ${binary_dir} PARENT_SCOPE)
