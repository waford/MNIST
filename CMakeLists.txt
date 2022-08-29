cmake_minimum_required(VERSION 3.23)
project(eigen_test)

set(CMAKE_CXX_STANDARD 23)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(CURL REQUIRED)

add_executable(eigen_test main.cpp MNISTImage.hpp MNISTDataset.cpp MNISTDataset.hpp)

target_link_libraries(eigen_test
        Eigen3::Eigen
        CURL::libcurl)
