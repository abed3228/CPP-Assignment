
#include "Cow.hpp"

// Constructor using member initializer list, no change needed
Cow::Cow(std::string name, double temp, double breath, double heart, double litres)
    : Animal(name, temp, breath, heart), m_litres(litres)
{
}

// Simplified destructor using default
Cow::~Cow() = default;

// Getter for milk production
double Cow::get_litres() const
{
    return m_litres;
}

// Optimized health check
bool Cow::check_health()
{
    return (38.5 <= get_temp() && get_temp() <= 39.5) &&
           (26 <= get_breath() && get_breath() <= 50) &&
           (48 <= get_heart() && get_heart() <= 84) &&
           (get_litres() >= 30);
}
