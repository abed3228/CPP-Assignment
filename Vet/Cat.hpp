#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

#include "Animal.hpp"

/**
 * @class Cat
 * @brief Represents a cat in a veterinary system.
 * This class is a derived class of Animal specifically for cats. It includes specialized health checks
 * specific to feline physiology. It inherits basic attributes and methods from the Animal class.
 */
class Cat : public Animal
{
public:
    /**
     * @brief Constructor for the Cat class.
     * @param name The name of the cat.
     * @param temp The body temperature of the cat in degrees Celsius.
     * @param breath The breathing rate of the cat in breaths per minute.
     * @param heart The heart rate of the cat in beats per minute.
     */
    Cat(std::string name, double temp, double breath, double heart);

    /**
     * @brief Destructor for the Cat class.
     */
    ~Cat();

    /**
     * @brief Checks the health of the cat.
     * This function evaluates various health parameters specific to cats, such as temperature, breathing rate,
     * and heart rate to determine if the cat is healthy. The exact criteria for health can be customized
     * based on veterinary standards.
     * @return Returns true if the cat is considered healthy, false otherwise.
     */
    bool check_health();
};

#endif
