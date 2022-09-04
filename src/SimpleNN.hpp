#ifndef SIMPLE_NN_HPP
#define SIMPEL_NN_HPP

#include <memory>
#include <vector>
#include <stdio.h>

#include "SimpleNNLayer.hpp"

class SimpleNN {
    SimpleNN(std::vector<size_t> layer_sizes, double learning_rate); 

    private:
        std::unique_ptr<ISimpleNNLayer> input_layer;
        double learning_rate_;

        void init(std::vector<size_t> layer_sizes);
};

#endif
