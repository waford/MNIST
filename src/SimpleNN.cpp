#include <vector>

#include <Eigen/Dense>

#include "SimpleNN.hpp"
#include "SimpleNNLayer.hpp"

using Eigen::VectorXd;

SimpleNN::SimpleNN(std::vector<size_t> layer_sizes, double learning_rate) :
    learning_rate_(learning_rate)
{
    init(layer_sizes);
}

void SimpleNN::init(std::vector<size_t> layer_sizes) {
    ;
}
