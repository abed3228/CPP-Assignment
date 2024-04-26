#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include "Animal.hpp"

/**
 * @class Dog
 * @brief Represents a dog in a veterinary system.
 * This class is derived from the Animal class and specifically represents dogs. It includes attributes and health checks
 * tailored to canine physiology, adding an additional attribute to denote if the dog is large.
 * Inherits basic attributes and methods from the Animal class.
 */
class Dog : public Animal
{
public:
    /**
     * @brief Constructor for the Dog class.
     * @param name The name of the dog.
     * @param temp The body temperature of the dog in degrees Celsius.
     * @param breath The breathing rate of the dog in breaths per minute.
     * @param heart The heart rate of the dog in beats per minute.
     * @param is_large Boolean indicating if the dog is considered large size.
     */
    Dog(std::string name, double temp, double breath, double heart, bool is_large);

    /**
     * @brief Destructor for the Dog class.
     */
    ~Dog();

    /**
     * @brief Checks the health of the dog.
     * This function evaluates various health parameters specific to dogs, such as temperature, breathing rate,
     * heart rate, and size characteristics to determine if the dog is healthy.
     * @return Returns true if the dog is considered healthy, false otherwise.
     */
    bool check_health();

    /**
     * @brief Get whether the dog is considered large.
     * @return Returns true if the dog is large, false otherwise.
     */
    bool get_is_large() const;

private:
    bool m_is_large; /* Indicates if the dog is considered large size. */
};

#endif