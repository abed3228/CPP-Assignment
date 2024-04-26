#include "Dog.hpp"

Dog::Dog(std::string name, double temp, double breath, double heart, bool is_large)
    : Animal(name, temp, breath, heart), m_is_large(is_large)
{
}

Dog::~Dog() = default; // Explicitly defaulted if no special cleanup is required.

bool Dog::get_is_large() const
{
    return m_is_large;
}

bool Dog::check_health()
{
    // Common checks for temperature and breathing rate
    bool tempCheck = (38 <= get_temp() && get_temp() <= 39.2);
    bool breathCheck = (10 <= get_breath() && get_breath() <= 35);

    // Heart rate checks differ based on the dog's size
    bool heartCheck = get_is_large()
                          ? (60 <= get_heart() && get_heart() <= 100)
                          : (100 <= get_heart() && get_heart() <= 140);

    return tempCheck && breathCheck && heartCheck;
}
