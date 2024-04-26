#include "Cat.hpp"

// Constructor using member initializer list, unchanged from your implementation
Cat::Cat(std::string name, double temp, double breath, double heart)
    : Animal(name, temp, breath, heart)
{
}

// Simplified destructor using default
Cat::~Cat() = default;

// Optimized health check
bool Cat::check_health()
{
    return (38 <= get_temp() && get_temp() <= 39.2) &&
           (16 <= get_breath() && get_breath() <= 40) &&
           (120 <= get_heart() && get_heart() <= 140);
}
