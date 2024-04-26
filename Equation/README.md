# Quadratic Equation Class

## Overview

The `Equation` class models and solves quadratic equations of the form `A*X^2 + B*X + C = 0`.
It includes full support for dynamic memory management, operator overloading for convenient equation manipulation,
and robust methods to determine and retrieve the roots based on the discriminant.

## Features

- **Dynamic Memory Management**: Ensures safe handling of memory for root storage.
- **Operator Overloading**: Facilitates equation outputting, copying, and arithmetic operations.
- **Root Calculation**: Automatically calculates the roots when coefficients are set or modified.

## Class Details

### Private Members

- `double a`: Coefficient of X². Must not be zero.
- `double b`: Coefficient of X.
- `double c`: Constant term.
- `double* solutions`: Points to an array of doubles storing the equation's roots.
- `std::size_t solutions_size`: Indicates the number of valid roots (0, 1, or 2).

### Public Methods

- Accessors and Mutators for `a`, `b`, and `c`.
- `std::size_t get_solutions_size()`: Returns the count of real roots.
- `double const* get_solutions()`: Returns a constant pointer to the roots array.

### Constructors

- `Equation(double a, double b, double c)`: Initializes coefficients and calculates roots. Throws `std::invalid_argument` if `a` is zero.

### Rule of Three

- **Copy Constructor**: Copies the solutions array deeply.
- **Assignment Operator**: Assigns an equation by freeing existing solutions and copying new ones.
- **Destructor**: Frees the allocated memory for solutions.

### Operators

- `<< (ostream&)`: Outputs equation in the format `A X^2 + B X + C = 0`.
- `+ (Equation)`: Adds two equations.
- `+ (double)`: Adds a double to the constant term and returns a new equation.
- `double + Equation`: Adds a double to the constant term from the left side.

### Root Calculation

Based on the discriminant `B² - 4*A*C`:

- **Two distinct real roots**: Discriminant > 0.
- **Single real root**: Discriminant == 0.
- **No real roots**: Discriminant < 0.

## HOW RUN TEST

- \*\*make tests

## HOW BUILD CLASS

- \*\*make task1
