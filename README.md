# SDLP

Linear-Complexity Linear Programming (LP) for Small-Dimensional Variables (Seidel's LP Algorithm)

# About

1. This solver is super efficient for small-dimensional decision variables (<10), mostly encountered in computational geometry. It enjoys [__linear complexity about the constraint number__](https://dl.acm.org/doi/10.1145/2422.322418).

2. The speed is at least an order of magnitude faster than [GLPK](https://en.wikipedia.org/wiki/GNU_Linear_Programming_Kit) in small-dimensional LP with large constraints number.

3. 

# Interface

To solve a linear programming:

    min cTx, 
    s.t. Ax<=b,
where x and c are d-dimensional vectors, b an m-dimensional vector and A an m*n matrix. It is assumed that d is small (<10) while m can be arbitrary value (1<= m <= 1e8).

Only one function is all you need to solve:

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
