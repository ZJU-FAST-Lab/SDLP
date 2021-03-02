# SDLP

Seidel's Algorithm: Linear-Complexity Linear Programming (LP) for Small-Dimensions

# About

1. This solver is super efficient for small-dimensional LP with any constraint number, mostly encountered in computational geometry. It enjoys [__linear complexity about the constraint number__](https://dl.acm.org/doi/10.1145/2422.322418).

2. The speed is __at least an order of magnitude__ faster than [GLPK](https://en.wikipedia.org/wiki/GNU_Linear_Programming_Kit) in small-dimensional LP (<10) with a large constraints number (>100).

3. This solver is adapted from the [linear-fractional programming (LFP)](https://en.wikipedia.org/wiki/Linear-fractional_programming) from Mike Hohmeyer at UC Berkerley based on [Raimund Seidel's algorithm](https://link.springer.com/article/10.1007/BF02574699). Kernel functions are reorganized. Previously-existed bugs are fixed here. An easy-to-use interface for LP via [Eigen](http://eigen.tuxfamily.org) is also added.

4. Only [a header file](https://github.com/ZJU-FAST-Lab/SDLP/blob/main/include/sdlp/sdlp.hpp) is all you need.

# Interface

To solve a linear programming:

        min cTx, 
        s.t. Ax<=b,

where x and c are d-dimensional vectors, b an m-dimensional vector and A an m*n matrix. It is assumed that d is small (<10) while m can be arbitrary value (1<= m <= 1e8).

Only one function is all you need:

    double linprog(const Eigen::VectorXd &c, 
                   const Eigen::MatrixXd &A,
                   const Eigen::VectorXd &b,
                   Eigen::VectorXd &x);

Input:

        c: objective coefficient
        A: constraint matrix
        b: constraint bound

Output:

        x: optimal solution if solved
        return: finite value if solved
                -infinity if unbounded
                infinity if infeasible

# Reference

1. Megiddo, N., 1984. Linear programming in linear time when the dimension is fixed. Journal of the ACM (JACM), 31(1), pp.114-127.
2. Seidel, R., 1991. Small-dimensional linear programming and convex hulls made easy. Discrete & Computational Geometry, 6(3), pp.423-434.
