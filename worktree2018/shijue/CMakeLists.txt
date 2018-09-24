cmake_minimum_required(VERSION 2.8)
project(shijue)

find_package(qibuild)

# Create a executable named shijue
# with the source file: main.cpp
qi_create_bin(shijue "main.cpp")

# Add a simple test:
qi_use_lib(shijue OPENCV2_WORLD)
