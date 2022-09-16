#ifndef SIMPLE_NN_HPP
#define SIMPEL_NN_HPP

#include <memory>
#include <vector>
#include <stdio.h>

#include "SimpleNNLayer.hpp"

using Eigen::VectorXd;

class SimpleNN {
    public:
        SimpleNN(std::vector<size_t> layer_sizes, const size_t output_size, const double learning_rate); 
        VectorXd fireNetwork(VectorXd & input);

    private:
        std::vector<std::shared_ptr<SimpleNNLayer>> layers_;
        double learning_rate_;

        void init(const std::vector<size_t> & layer_sizes);

};

#endif
