#include <iostream>
#include <gtest/gtest.h>

#include "test.hpp"
#include "SimpleNN.hpp"

INSTANTIATE_TEST_SUITE_P(SingleLayerTestInputOutput, SingleLayerTest, testing::Range<size_t>(1, 20));

TEST_P(SingleLayerTest, InputOutput) {
    size_t layer_size = GetParam();
    SimpleNN one_layer_net({layer_size}, 1);  
    VectorXd inputs(layer_size);

    VectorXd output = one_layer_net.fireNetwork(inputs);

    ASSERT_EQ(output.rows(), layer_size);
    ASSERT_EQ(inputs.rows(), output.rows());
    ASSERT_EQ(inputs.cols(), output.cols());
}


