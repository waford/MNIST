#include <vector>

#include <Eigen/Dense>

#include "SimpleNN.hpp"
#include "SimpleNNLayer.hpp"

using Eigen::VectorXd;

SimpleNN::SimpleNN(std::vector<size_t> layer_sizes, const double learning_rate) :
    learning_rate_(learning_rate)
{
    init(layer_sizes);
}

void SimpleNN::init(std::vector<size_t> &layer_sizes) {
    // The last layer will create an output the same size as its inputs.
    // Duplicate last layer size to correctly size the output layer of the network.
    layer_sizes.push_back(layer_sizes.back()); 

    for(int i = 0; i < layer_sizes.size() - 1; i++) {
        size_t input_size = layer_sizes[i];
        size_t output_size = layer_sizes[i + 1];
        layers_.emplace_back(new SimpleNNLayer(input_size, output_size));
    }
}

VectorXd SimpleNN::fireNetwork(VectorXd & input) {
    VectorXd & current_activations = input;
    for(std::shared_ptr<SimpleNNLayer> layer : layers_) {
        layer->activateNeurons(current_activations);
        current_activations = layer->output();
    }
    return layers_.back()->output();
}
