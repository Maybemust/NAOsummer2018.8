cmake_minimum_required(VERSION 2.8)
project(cutpicture)

find_package(qibuild)

# Create a executable named cutpicture
# with the source file: main.cpp
qi_create_bin(cutpicture "main.cpp")

# Add a simple test:
qi_use_lib(cutpicture OPENCV2_WORLD)
