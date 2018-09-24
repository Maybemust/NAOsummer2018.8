cmake_minimum_required(VERSION 2.8)
project(sebiao)

find_package(qibuild)

# Create a executable named sebiao
# with the source file: main.cpp
qi_create_bin(sebiao "main.cpp")

# Add a simple test:
qi_use_lib(sebiao OPENCV2_WORLD)
