find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(CURL REQUIRED)

add_executable(main main.cpp
    MNISTImage.hpp
    MNISTDataset.cpp
    MNISTDataset.hpp)

target_link_libraries(main
        Eigen3::Eigen
        CURL::libcurl)
