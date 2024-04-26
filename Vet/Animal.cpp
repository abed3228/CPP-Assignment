

#include "Animal.hpp"

Animal::Animal(std::string name, double temp, double breath, double heart)
    : m_name(name), m_temp(temp), m_breath(breath), m_heart(heart)
{
}

Animal::~Animal() = default;

std::string Animal::get_name() const
{
    return m_name;
}
double Animal::get_temp() const
{
    return m_temp;
}
double Animal::get_breath() const
{
    return m_breath;
}
double Animal::get_heart() const
{
    return m_heart;
}