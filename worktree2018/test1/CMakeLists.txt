cmake_minimum_required(VERSION 2.8)
project(test1)

find_package(qibuild)

# Create a executable named test1
# with the source file: main.cpp
qi_create_bin(test1 "main.cpp")

# Add a simple test:
qi_use_lib(test1 ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
