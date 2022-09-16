include(FetchContent)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(neural
    SimpleNN.cpp)

target_link_libraries(neural
    Eigen3::Eigen)
