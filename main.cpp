#include <iostream>
#include <Eigen/Dense>

#include "MNISTDataset.hpp"

using Eigen::MatrixXd;
using Eigen::Vector3f;



int main() {
    MNISTDataset training("train", "image_url", "label_url");
    MNISTDataset test("test", "test_image_url", "test_label_url");
}
