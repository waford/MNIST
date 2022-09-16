#include "gtest/gtest.h"
#include <iostream>
#include <gtest/gtest.h>

#include "test.hpp"
#include "SimpleNN.hpp"

INSTANTIATE_TEST_SUITE_P(SingleLayerTestInputOutput, SingleLayerTest, testing::Range<size_t>(1, 20));
INSTANTIATE_TEST_SUITE_P(TwoLayerTestInputOutpt, TwoLayerTest, testing::Combine(testing::Range<size_t>(1,20), testing::Range<size_t>(1,20)));

TEST_P(SingleLayerTest, InputOutput) {
    size_t layer_size = GetParam();
    SimpleNN one_layer_net({layer_size}, 1);  
    VectorXd inputs(layer_size);

    VectorXd output = one_layer_net.fireNetwork(inputs);

    ASSERT_EQ(output.rows(), layer_size);
    ASSERT_EQ(inputs.rows(), output.rows());
    ASSERT_EQ(inputs.cols(), output.cols());
}

TEST_P(TwoLayerTest, InputOutput) {
    auto param = GetParam();
    size_t input_size;
    size_t output_size;
    input_size = std::get<0>(param);
    output_size = std::get<1>(param);

    SimpleNN two_layer_net({input, output}, 1);
    VectorXd inputs(input_size);

    VectorXd outputs = two_layer_net.fireNetwork(inputs);

    ASSERT_EQ(output.rows(), output_size);
    ASSERT_EQ(input.activations().size, input_size);
}
