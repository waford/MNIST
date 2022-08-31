#include <iostream>

#include "MNISTDataset.hpp"

std::string trainingImages("http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz");
std::string trainingLabels("http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz");

int main() {
    MNISTDataset training("train", trainingImages, trainingLabels);
//    MNISTDataset test("test", "test_image_url", "test_label_url");
}
