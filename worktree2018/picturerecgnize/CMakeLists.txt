cmake_minimum_required(VERSION 2.8)
project(picturerecgnize)

find_package(qibuild)

# Create a executable named picture_recgnize
# with the source file: main.cpp
qi_create_bin(picturerecgnize "main.cpp")

# Add a simple test:
qi_use_lib(picturerecgnize OPENCV2_WORLD)
