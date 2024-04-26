#include "Equation.hpp"

Equation::Equation()
    : m_a(new double), m_b(new double), m_c(new double), m_solutions(nullptr), m_solutions_size(0)
{
}

Equation::Equation(double a, double b, double c)
    : m_a(new double), m_b(new double), m_c(new double), m_solutions(nullptr), m_solutions_size(0)
{
    setA(a);
    setB(b);
    setC(c);
}
Equation::Equation(const Equation &e)
    : m_a(new double(*e.m_a)), m_b(new double(*e.m_b)), m_c(new double(*e.m_c)), m_solutions(nullptr), m_solutions_size(0)
{
    update_solutions();
}
Equation::~Equation()
{
    delete m_a;
    m_a = nullptr;

    delete m_b;
    m_b = nullptr;

    delete m_c;
    m_c = nullptr;

    clear_solutions();
}

double Equation::getA() const
{
    return *m_a;
}
double Equation::getB() const
{
    return *m_b;
}
double Equation::getC() const
{
    return *m_c;
}
std::size_t Equation::get_solutions_size() const
{
    return m_solutions_size;
}

void Equation::setA(double a)
{
    if (a == 0)
    {
        throw std::invalid_argument("Coefficient 'a' should not be zero for a quadratic equation.");
    }
    else
    {
        *m_a = a;
        update_solutions();
    }
}
void Equation::setB(double b)
{
    *m_b = b;
    update_solutions();
}
void Equation::setC(double c)
{
    *m_c = c;
    update_solutions();
}
double const *const Equation::get_solutions() const
{
    return m_solutions;
}

std::ostream &operator<<(std::ostream &out, const Equation &e)
{
    out.precision(e.PRINT_FORMAT);
    out << std::fixed << e.getA() << "X^2 + " << e.getB() << "X + " << e.getC() << " = 0";
    return out;
}
Equation &Equation::operator=(const Equation &e)
{
    this->setA(e.getA());
    this->setB(e.getB());
    this->setC(e.getC());
    return *this;
}

Equation operator+(int num, const Equation &e)
{
    return e + num;
}
Equation operator+(const Equation &e, int num)
{
    return Equation(e.getA(), e.getB(), e.getC() + (double)num);
}
Equation operator+(const Equation &e1, const Equation &e2)
{
    return Equation(e1.getA() + e2.getA(), e1.getB() + e2.getB(), e1.getC() + e2.getC());
}

void Equation::update_solutions()
{
    int delta = pow(getB(), EQUATION_TWO) - EQUATION_FOUR * (getA() * getC());
    if (delta > DELTA_ZERO)
    {
        int sum = sqrt(delta);
        set_solutions_size(SOLUTIONS_TWO);
        allocation_solutions();
        m_solutions[EQ_SOLUTION_1] = (-getB() + sum) / (EQUATION_TWO * getA());
        m_solutions[EQ_SOLUTION_2] = (-getB() - sum) / (EQUATION_TWO * getA());
    }
    else if (delta == DELTA_ZERO)
    {
        set_solutions_size(SOLUTIONS_ONE);
        allocation_solutions();
        m_solutions[EQ_SOLUTION_1] = -getB() / (EQUATION_TWO * getA());
    }
    else
    {
        set_solutions_size(SOLUTIONS_ZERO);
    }
}

void Equation::clear_solutions()
{
    if (m_solutions == nullptr)
    {
        delete[] m_solutions;
        m_solutions = nullptr;
        set_solutions_size(SOLUTIONS_ZERO);
    }
}

void Equation::allocation_solutions()
{
    clear_solutions();
    try
    {
        m_solutions = new double(get_solutions_size());
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        m_solutions = nullptr;
    }
}

void Equation::set_solutions_size(unsigned int size)
{
    m_solutions_size = size;
}