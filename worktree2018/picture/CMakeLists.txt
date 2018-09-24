cmake_minimum_required(VERSION 2.8)
project(picture)

find_package(qibuild)

# Create a executable named picture
# with the source file: main.cpp
qi_create_bin(picture "main.cpp")

# Add a simple test:
qi_use_lib(picture OPENCV2_WORLD)
