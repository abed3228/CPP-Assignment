/**
 * @file Equation.hpp
 * @author Abed Alnkib <abed3228@gmail.com>
 * @brief Class to represent and solve quadratic equations.
 * @version 2.0
 * @date 2024-04-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

/**
 * @brief Represents a quadratic equation of the form ax^2 + bx + c = 0.
 */
class Equation
{
public:
    /**
     * @brief Default constructor, initializes the coefficients to zero.
     */
    Equation();

    /**
     * @brief Parameterized constructor to set the equation's coefficients.
     * @param a Coefficient of x^2
     * @param b Coefficient of x
     * @param c Constant term
     * @throws std::invalid_argument if 'a' is zero.
     */
    Equation(double a, double b, double c);

    /**
     * @brief Copy constructor.
     * @param e2 Another instance of Equation to copy from.
     */
    Equation(const Equation &e2);

    /**
     * @brief Destructor, cleans up allocated memory.
     */
    ~Equation();

    /**
     * @brief Get the coefficient 'a'.
     * @return double The coefficient of x^2.
     */
    double getA() const;

    /**
     * @brief Get the coefficient 'b'.
     * @return double The coefficient of x.
     */
    double getB() const;

    /**
     * @brief Get the constant term 'c'.
     * @return double The constant term.
     */
    double getC() const;

    /**
     * @brief Get the number of solutions stored.
     * @return std::size_t Number of solutions.
     */
    std::size_t get_solutions_size() const;

    /**
     * @brief Get the solutions array.
     * @return double const* Pointer to the array of solutions.
     */
    double const *const get_solutions() const;

    /**
     * @brief Set the coefficient 'a'.
     * @param a Coefficient of x^2.
     */
    void setA(double a);

    /**
     * @brief Set the coefficient 'b'.
     * @param b Coefficient of x.
     */
    void setB(double b);

    /**
     * @brief Set the constant term 'c'.
     * @param c Constant term.
     */
    void setC(double c);

    /**
     * @brief Assignment operator overload.
     * @param e Source equation to copy.
     * @return Equation& Reference to the current object.
     */
    Equation &operator=(const Equation &e);

    /**
     * @brief Stream insertion operator to output the equation in human-readable form.
     * @param out Output stream.
     * @param e Equation to output.
     * @return std::ostream& Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const Equation &e);

    /**
     * @brief Addition operator to add a constant to an equation.
     * @param num Constant to add.
     * @param e Equation to add to.
     * @return Equation Resulting equation.
     */
    friend Equation operator+(int num, const Equation &e);

    /**
     * @brief Addition operator to add a constant to an equation.
     * @param e Equation to add to.
     * @param num Constant to add.
     * @return Equation Resulting equation.
     */
    friend Equation operator+(const Equation &e, int num);

    /**
     * @brief Addition operator to combine two equations.
     * @param e1 First equation.
     * @param e2 Second equation.
     * @return Equation Resulting equation.
     */
    friend Equation operator+(const Equation &e1, const Equation &e2);

private:
    double *m_a;                  ///< Pointer to the coefficient of x^2
    double *m_b;                  ///< Pointer to the coefficient of x
    double *m_c;                  ///< Pointer to the constant term
    double *m_solutions;          ///< Dynamic array of solutions
    std::size_t m_solutions_size; ///< Size of the solutions array

    /**
     * @brief Updates the solutions array based on current coefficients.
     */
    void update_solutions();

    /**
     * @brief Clears all current solutions from the data structure.
     * This function removes all stored solutions, resetting the data structure to an empty state.
     * It does not allocate new memory but ensures that the solutions container is cleared.
     */
    void clear_solutions();

    /**
     * @brief Allocates memory or initializes resources necessary for storing solutions.
     * This function prepares the data structure for storing solutions by allocating memory or
     * initializing resources. It should be called before adding any solutions to ensure that
     * the data structure is ready to store the data efficiently.
     */
    void allocation_solutions();

    /**
     * @brief Sets the size of the solution container.
     * This function allocates or reallocates the solution container to the specified size.
     * It is useful for pre-setting the container size to improve memory management and performance.
     * @param size The new size of the solutions container in terms of the number of solutions it can hold.
     */
    void set_solutions_size(unsigned int size);

    /* Static constant for factor of the quadratic equation used in solution calculations. */
    static constexpr int EQUATION_TWO = 2;
    /* Static constant for factor of the quadratic equation used in discriminant calculations. */
    static constexpr int EQUATION_FOUR = 4;
    /* Number of solutions indicator for no solutions. */
    static constexpr int SOLUTIONS_ZERO = 0;
    /* Number of solutions indicator for one solution. */
    static constexpr int SOLUTIONS_ONE = 1;
    /* Number of solutions indicator for two solutions. */
    static constexpr int SOLUTIONS_TWO = 2;
    /* Indicator for zero discriminant. */
    static constexpr int DELTA_ZERO = 0;
    /* Index for the first solution in solution array. */
    static constexpr int EQ_SOLUTION_1 = 0;
    /* Index for the second solution in solution array. */
    static constexpr int EQ_SOLUTION_2 = 1;
    /* Print format double . */
    static constexpr int PRINT_FORMAT = 2;
};

#endif // EQUATION_HPP
