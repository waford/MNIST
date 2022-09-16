#include <iostream>
#include <Eigen/Core>

#include "MNISTDataset.hpp"

#include "SimpleNN.hpp"

using Eigen::VectorXd;

std::string trainingImages("http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz");
std::string trainingLabels("http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz");

int main() {
    MNISTDataset training("train");
    training.parseData();

}
