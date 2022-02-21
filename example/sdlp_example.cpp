#include <iostream>

#include "sdlp/sdlp.hpp"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    int m = 2 * 7;
    Eigen::Matrix<double, 7, 1> x;        // decision variables
    Eigen::Matrix<double, 7, 1> c;        // objective coefficients
    Eigen::Matrix<double, -1, 7> A(m, 7); // constraint matrix
    Eigen::VectorXd b(m);                 // constraint bound

    c << 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0;
    A << 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
        -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0;
    b << 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0;

    double minobj = sdlp::linprog<7>(c, A, b, x);

    std::cout << "prob:\n"
              << std::endl;
    std::cout << "     min x1 + ... + x7," << std::endl;
    std::cout << "     s.t. x1 <=  6,  x2 <=  5, ..., x7 <= 0," << std::endl;
    std::cout << "          x1 >= -1,  x2 >= -2,  ..., x7 >= -7.\n"
              << std::endl;
    std::cout << "optimal sol: " << x.transpose() << std::endl;
    std::cout << "optimal obj: " << minobj << std::endl;

    return 0;
}