include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test test.cc)

target_link_libraries(test
    GTest::gtest_main
    ${LIB})

target_include_directories(test PUBLIC
    ${INCLUDES}
    )

include(GoogleTest)
gtest_discover_tests(test)
