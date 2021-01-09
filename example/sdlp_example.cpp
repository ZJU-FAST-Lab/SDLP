#include <iostream>

#include "sdlp/sdlp.hpp"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    int d = 3;
    int m = 6;
    Eigen::VectorXd x(d);    // decision variables
    Eigen::VectorXd c(d);    // objective coefficients
    Eigen::MatrixXd A(m, d); // constraint matrix
    Eigen::VectorXd b(m);    // constraint bound

    c << 1.0, 1.0, 1.0;
    A << 1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        -1.0, 0.0, 0.0,
        0.0, -1.0, 0.0,
        0.0, 0.0, -1.0;
    b << 2.0, 1.0, 0.0, 1.0, 2.0, 3.0;

    double minobj = sdlp::linprog(c, A, b, x);

    std::cout << "prob:\n"
              << std::endl;
    std::cout << "     min x1 + x2 + x3," << std::endl;
    std::cout << "     s.t. x1 <=  2,  x2 <=  1,  x3 <= 0," << std::endl;
    std::cout << "          x1 >= -1,  x2 >= -2,  x3 >= -3.\n"
              << std::endl;
    std::cout << "optimal sol: " << x.transpose() << std::endl;
    std::cout << "optimal obj: " << minobj << std::endl;

    return 0;
}