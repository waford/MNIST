#ifndef SIMPLE_NN_LAYER_HPP
#define SIMPLE_NN_LAYER_HPP

#include <Eigen/Dense>

using Eigen::Matrix;

class ISimpleNNLayer {
    public:
        size_t input_size();
        size_t output_size();
        
};

template <size_t input, size_t output>
class SimpleNNLayer : public ISimpleNNLayer {
    SimpleNNLayer();
    Matrix<double, output, 1> fireNeurons(Matrix<double, input, 1> & input_neurons) {
        return weights_ * input_neurons + biases_;
    }

    //size_t input_size() { return weights_.cols(); }
    //size_t output_size() { return weights_.rows(); }
    size_t input_size() { return input; }
    size_t output_size() { return output; }

    private:
        Matrix<double, output, input> weights_;
        Matrix<double, output, 1> biases_;
};
#endif
