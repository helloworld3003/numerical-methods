# Numerical Methods in C

This repository contains implementations of various numerical methods in C.

## Implemented Methods

### Root Finding
* **Bisection Method** (`bissection.c`): A root-finding method that repeatedly bisects an interval and then selects a subinterval in which a root must lie for further processing.
* **False Position Method** (`false_position.c`): Also known as the *regula falsi* method, it is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function.
* **Newton-Raphson Method** (`newton_raphson.c`): A root-finding algorithm which produces successively better approximations to the roots (or zeroes) of a real-valued function.

### Linear Equations
* **Gauss Elimination** (`Gauss'elimination.c`): An algorithm for solving systems of linear equations.
* **Gauss-Jacobi Method** (`gauss_jacobi.c`): An iterative algorithm for determining the solutions of a strictly diagonally dominant system of linear equations.

### Ordinary Differential Equations (ODEs)
* **Euler's Method** (`eulers_method_differentiation.c`): A first-order numerical procedure for solving ordinary differential equations (ODEs) with a given initial value.
* **Runge-Kutta 4th Order** (`runge_kutta_4th_order.c`): A widely used and high-precision iterative method for solving ordinary differential equations (ODEs).

### Numerical Integration
* **Simpson's 1/3 Rule** (`simpsons_1_3rd.c`): A method for numerical integration that provides an approximation for definite integrals using parabolas.
* **Trapezoidal Rule** (`trapezoidal_integration.c`): A numerical integration method that approximates the area under a curve by dividing it into a series of trapezoids.
