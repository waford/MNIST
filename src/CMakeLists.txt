include(FetchContent)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(neural)

list(APPEND INCLUDES "${PROJECT_SOURCE_DIR}/src/neural")
list(APPEND LIB 
    Eigen3::Eigen
    neural
    )

FetchContent_Declare(
    EasyBMP
    GIT_REPOSITORY https://github.com/izanbf1803/EasyBMP
    GIT_TAG 2ab57a08e4c76d2f60141a0d3364bf86d92893a2
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)

FetchContent_MakeAvailable(EasyBMP)

add_library(EasyBMP INTERFACE)
target_include_directories(EasyBMP INTERFACE ${easybmp_SOURCE_DIR})

add_executable(main main.cpp
    MNISTImage.cpp
    MNISTDataset.cpp
    )

target_link_libraries(main
        EasyBMP
        ${LIB})

target_include_directories(main PUBLIC
        ${INCLUDES}
        )

add_subdirectory(test)
