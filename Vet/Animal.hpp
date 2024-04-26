#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

/**
 * @class Animal
 * @brief Represents a generic animal in a veterinary system.
 * This class serves as a base class for different types of animals in a veterinary health monitoring system.
 * It includes basic attributes such as name, body temperature, breathing rate, and heart rate.
 * Derived classes must implement the check_health method to assess the animal's health based on specific criteria.
 */
class Animal
{
public:
    /**
     * @brief Constructor for the Animal class.
     * @param name The name of the animal.
     * @param temp The body temperature of the animal in degrees Celsius.
     * @param breath The breathing rate of the animal in breaths per minute.
     * @param heart The heart rate of the animal in beats per minute.
     */
    Animal(std::string name, double temp, double breath, double heart);

    /**
     * @brief Destructor for the Animal class.
     */
    ~Animal();

    /**
     * @brief Pure virtual function to check the health of the animal.
     * @return Returns true if the animal is healthy, false otherwise.
     */
    virtual bool check_health() = 0;

    /**
     * @brief Get the name of the animal.
     * @return Returns the name as a string.
     */
    std::string get_name() const;

    /**
     * @brief Get the body temperature of the animal.
     * @return Returns the body temperature in degrees Celsius.
     */
    double get_temp() const;

    /**
     * @brief Get the breathing rate of the animal.
     * @return Returns the breathing rate in breaths per minute.
     */
    double get_breath() const;

    /**
     * @brief Get the heart rate of the animal.
     * @return Returns the heart rate in beats per minute.
     */
    double get_heart() const;

private:
    std::string m_name; ///< The name of the animal.
    double m_temp;      ///< The body temperature of the animal, measured in degrees Celsius.
    double m_breath;    ///< The breathing rate of the animal, measured in breaths per minute.
    double m_heart;     ///< The heart rate of the animal, measured in beats per minute.
};

#endif