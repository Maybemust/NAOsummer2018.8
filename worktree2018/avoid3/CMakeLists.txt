cmake_minimum_required(VERSION 2.8)
project(avoid3)
find_package(qibuild)

set(_srcs 
  avoidcollision.h
  objectFinder.h
  avoidcollision.cpp
  ycylib2.h
  ycylib2.cpp
  main.cpp
  wxzSVM.h
  wxzSVM.cpp
)

qi_create_bin(avoid3 ${_srcs})

qi_use_lib(avoid3 ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
