cmake_minimum_required(VERSION 3.10)
project(sik1)

set(CMAKE_CXX_STANDARD 17)

add_executable(sik1 main.cpp err.h Session.cpp Session.h State.h ABState.cpp ABState.h Util.h BState.cpp BState.h)