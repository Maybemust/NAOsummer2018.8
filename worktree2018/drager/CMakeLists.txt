cmake_minimum_required(VERSION 2.8)
project(drager)
find_package(qibuild)

set(_srcs 
  dragcar.h
  dragcar.cpp
  main.cpp
  wxzSVM.h
  wxzSVM.cpp
)

qi_create_bin(drager ${_srcs})

qi_use_lib(drager ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
