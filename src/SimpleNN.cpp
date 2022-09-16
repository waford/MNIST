#include <vector>

#include <Eigen/Dense>

#include "SimpleNN.hpp"
#include "SimpleNNLayer.hpp"

using Eigen::VectorXd;

SimpleNN::SimpleNN(std::vector<size_t> layer_sizes, const size_t output_size, const double learning_rate) :
    learning_rate_(learning_rate)
{
    layer_sizes.push_back(output_size);
    init(layer_sizes);
}

void SimpleNN::init(const std::vector<size_t> &layer_sizes) {
    for(int i = 0; i < layer_sizes.size() - 1; i++) {
        size_t input_size = layer_sizes[i];
        size_t output_size = layer_sizes[i + 1];
        layers_.emplace_back(new SimpleNNLayer(input_size, output_size));

        if(i != 0) {
            layers_[i-1]->setNextLayer(layers_.back());
        }
    }
}

VectorXd SimpleNN::fireNetwork(VectorXd & input) {
    layers_.front()->activateNeurons(input);
    return layers_.back()->activations_;
}
