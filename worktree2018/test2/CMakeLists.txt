cmake_minimum_required(VERSION 2.8)
project(test2)

find_package(qibuild)

# Create a executable named test2
# with the source file: main.cpp
qi_create_bin(test2 "main.cpp")

# Add a simple test:
qi_create_test(test_test2 "test.cpp")
