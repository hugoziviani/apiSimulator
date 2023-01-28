cmake_minimum_required(VERSION 3.23)
project(MyVensim)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(MyVensim main.cpp src/Flow.cpp src/Flow.hpp src/Model.cpp src/Model.hpp src/System.cpp src/System.hpp test/functional/FunctionalTest.cpp test/functional/FunctionalTest.hpp test/functional/main.cpp src/Exponential.hpp src/Logistic.hpp)

target_link_libraries(MyVensim Boost::boost)