cmake_minimum_required(VERSION 2.8)
project(baipingheng)

find_package(qibuild)

# Create a executable named baipingheng
# with the source file: main.cpp
qi_create_bin(baipingheng "main.cpp")

# Add a simple test:
qi_use_lib(baipingheng OPENCV2_WORLD)
