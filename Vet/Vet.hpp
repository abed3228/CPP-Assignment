#ifndef VET_HPP
#define VET_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <unordered_set>
#include <vector>
#include <string>
#include <mutex>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"

/**
 * @class Vet
 * @brief Manages a veterinary clinic using the Singleton design pattern.
 *
 * This class is implemented as a Singleton to ensure there is only one instance managing the list of animals in the clinic.
 * It provides functionality to add animals, retrieve the list of sick animals, and the list of sick dogs specifically.
 * Copy constructor and assignment operator are deleted to prevent multiple instances.
 */
class Vet
{
public:
  /**
   * @brief Deleted copy constructor to prevent the creation of another instance.
   */
  Vet(const Vet &) = delete;

  /**
   * @brief Deleted assignment operator to prevent copying the singleton instance.
   */
  Vet &operator=(const Vet &) = delete;

  /**
   * @brief Provides access to the singleton instance of the Vet class.
   * Uses lazy initialization and is thread-safe.
   * @return Reference to the singleton Vet instance.
   */
  static Vet &get_instance();

  /**
   * @brief Adds an animal to the clinic's records.
   * @param a Pointer to an animal object to be added to the clinic.
   */
  void add_animal(Animal *a);

  /**
   * @brief Retrieves names of all sick animals in the clinic.
   * @return An unordered_set containing the names of all sick animals.
   */
  std::unordered_set<std::string> show_sick();

  /**
   * @brief Retrieves names of all sick dogs in the clinic.
   * @return An unordered_set containing the names of all sick dogs.
   */
  std::unordered_set<std::string> show_sick_dogs();

private:
  /**
   * @brief Vector to store pointers to Animal objects.
   */
  std::vector<Animal *> animals;
  /**
   * @brief Number of animals currently managed by the clinic.
   */
  size_t size;

  /**
   * @brief Pointer to the singleton instance of the Vet class.
   */
  static Vet *instance;


  /**
   * @brief Mutex used to ensure thread-safe initialization of the singleton instance.
   */
  static std::once_flag onceFlag;

  /**
   * @brief Private constructor to restrict instantiation outside the class.
   * Singleton pattern implementation.
   */
  Vet();

  /**
   * @brief Destructor for the Vet class.
   */
  ~Vet();
};

#endif