#ifndef COW_HPP
#define COW_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

#include "Animal.hpp"

/**
 * @class Cow
 * @brief Represents a cow in a veterinary system.
 * This class is a derived class of Animal specifically for cows. It includes attributes and health checks
 * tailored to bovine physiology, including milk production measured in litres. It inherits basic attributes
 * and methods from the Animal class.
 */
class Cow : public Animal
{
public:
    /**
     * @brief Constructor for the Cow class.
     * @param name The name of the cow.
     * @param temp The body temperature of the cow in degrees Celsius.
     * @param breath The breathing rate of the cow in breaths per minute.
     * @param heart The heart rate of the cow in beats per minute.
     * @param litres The daily milk production of the cow in litres.
     */
    Cow(std::string name, double temp, double breath, double heart, double litres);

    /**
     * @brief Destructor for the Cow class.
     */
    ~Cow();

    /**
     * @brief Checks the health of the cow.
     * This function evaluates various health parameters specific to cows, such as temperature, breathing rate,
     * heart rate, and milk production to determine if the cow is healthy. The exact criteria for health can be
     * customized based on veterinary standards.
     * @return Returns true if the cow is considered healthy, false otherwise.
     */
    bool check_health();

    /**
     * @brief Get the daily milk production of the cow.
     * @return Returns the daily milk production in litres.
     */
    double get_litres() const;

private:
    double m_litres; ///< The daily milk production of the cow, measured in litres.
};

#endif