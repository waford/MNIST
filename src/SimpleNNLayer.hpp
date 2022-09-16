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
            weights_(inputs, outputs),
            biases_(outputs),
            weighted_input_(outputs), 
            activations_(outputs)
        {}

        size_t inputSize() { return weights_.cols(); }
        size_t outputSize() { return weights_.rows(); }
        void setNextLayer(std::shared_ptr<SimpleNNLayer> next_layer) { next_layer_ = next_layer; }

        void activateNeurons(VectorXd & input_activations) {
            weighted_input_ = weights_ * input_activations + biases_; 
            activations_ = sigmoid(weighted_input_);

            if(next_layer_) {
                next_layer_->activateNeurons(activations_);    
            }
        }

        VectorXd activations_;

    private:
        MatrixXd weights_;
        VectorXd biases_;
        VectorXd weighted_input_;

        std::shared_ptr<SimpleNNLayer> next_layer_;

        static VectorXd sigmoid(VectorXd & x) {
            return 1 / (1 + exp(-(x.array())));
        }
};
#endif
