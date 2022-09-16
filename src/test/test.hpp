#include <gtest/gtest.h>

class SingleLayerTest : public ::testing::TestWithParam<size_t> {};

class TwoLayerTest : public ::testing::TestWithParam<std::tuple<size_t, size_t>> {};




