#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

#include "../Equation/Equation.hpp"

/**
 *  Test the output of the Equation's string representation
 */
TEST(EquationTest, StringOutput)
{
    Equation eq(10, 20, 30);
    std::stringstream ss;
    ss << eq;
    ASSERT_EQ("10.00X^2 + 20.00X + 30.00 = 0", ss.str());

    eq = -20 + eq;
    ss.str("");
    ss.clear();
    ss << eq;
    ASSERT_EQ("10.00X^2 + 20.00X + 10.00 = 0", ss.str());
}

/**
 *  Test the number of solutions for different equations
 */
TEST(EquationTest, SolutionCount)
{
    Equation eq1(10, 20, 30);
    ASSERT_EQ(0, eq1.get_solutions_size());

    eq1 = -20 + eq1;
    ASSERT_EQ(1, eq1.get_solutions_size());

    Equation eq2(1, 3, -4);
    ASSERT_EQ(2, eq2.get_solutions_size());
}

/**
 *  Test the solutions themselves
 */
TEST(EquationTest, Solutions)
{
    Equation eq1(-20 + Equation(10, 20, 30));
    const double *solutions1 = eq1.get_solutions();
    ASSERT_DOUBLE_EQ(-1, solutions1[0]);

    Equation eq2(1, 3, -4);
    const double *solutions2 = eq2.get_solutions();
    ASSERT_DOUBLE_EQ(1, solutions2[0]);
    ASSERT_DOUBLE_EQ(-4, solutions2[1]);
}

/**
 * Test addition of equations
 */
TEST(EquationTest, Addition)
{
    Equation eq1(1, 5, 3);
    Equation eq2(2, 6, 4);
    Equation sum = eq1 + eq2;
    std::stringstream ss;
    ss << sum;
    ASSERT_EQ("3.00X^2 + 11.00X + 7.00 = 0", ss.str());
}

/**
 * Test Copy Constructor and Assignment Operator
 */
TEST(EquationTest, CopyAndAssignment)
{
    Equation eq(1, 3, -4);
    Equation e5(eq);
    Equation e6 = eq;
    std::stringstream ss1, ss2;
    ss1 << e5;
    ss2 << e6;
    ASSERT_EQ(ss1.str(), ss2.str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
