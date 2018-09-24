cmake_minimum_required(VERSION 2.8)
project(robotbaipingheng)
find_package(qibuild)

set(_srcs 
  avoidcollision.h
  avoidcollision.cpp
  main.cpp
)

qi_create_bin(robotbaipingheng ${_srcs})

qi_use_lib(robotbaipingheng ALCOMMON ALPROXIES ALVISION OPENCV2_WORLD)
