cmake_minimum_required(VERSION 2.8)
project(duibidu)

find_package(qibuild)

# Create a executable named duibidu
# with the source file: main.cpp
qi_create_bin(duibidu "main.cpp")

# Add a simple test:
qi_use_lib(duibidu OPENCV2_WORLD)
