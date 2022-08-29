#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::Vector3f;



int main() {
    Vector3f xhat(1,0,0);
    Vector3f yhat(0,1,0);
    Vector3f zhat(0, 0, 1);
    std::cout << xhat.cross(yhat) << std::endl;

}
