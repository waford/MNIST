#ifndef SIMPLE_NN_LAYER_HPP
#define SIMPLE_NN_LAYER_HPP

#include <memory>
#include <math.h>

#include <Eigen/Dense>


using Eigen::MatrixXd;
using Eigen::VectorXd;

class SimpleNNLayer {
    public:
        SimpleNNLayer(size_t inputs, size_t outputs) : 
            weights_(outputs, inputs),
            biases_(outputs),
            weighted_input_(outputs), 
            activations_(inputs)
        {}

       size_t inputSize() { return weights_.cols(); }
       size_t outputSize() { return weights_.rows(); }
       VectorXd & activations() { return activations_; }

       void activateNeurons(const VectorXd & input_activations) {
            weighted_input_ = weights_ * input_activations + biases_; 
            activations_ = sigmoid(weighted_input_);
        }
        
    private:
        MatrixXd weights_;
        VectorXd biases_;
        VectorXd weighted_input_;
        VectorXd activations_;

        static VectorXd sigmoid(VectorXd & x) {
            return 1 / (1 + exp(-(x.array())));
        }
};
#endif
