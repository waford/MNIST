#ifndef SIMPLE_NN_HPP
#define SIMPEL_NN_HPP

#include <memory>
#include <vector>
#include <stdio.h>

#include "SimpleNNLayer.hpp"

using Eigen::VectorXd;

class SimpleNN {
    public:
        SimpleNN(std::vector<size_t> layer_sizes, const double learning_rate); 
        VectorXd fireNetwork(VectorXd & input);

    private:
        std::vector<std::shared_ptr<SimpleNNLayer>> layers_;
        void backProp();
        void evaluateNetwork(VectorXd & input, VectorXd & expected_output);

        double learning_rate_;

        void init(std::vector<size_t> & layer_sizes);
};

#endif
