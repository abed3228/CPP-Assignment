#include "Vet.hpp"
// Initialize pointer to zero so that it can be initialized in first call to getInstance
Vet *Vet::instance = nullptr;
std::once_flag Vet::onceFlag;

Vet::Vet()
{
}

Vet::~Vet()
{
    // Automatic cleanup handled by vector and unique_ptr, explicit clear not required unless desired for specific reasons
}

Vet &Vet::get_instance()
{
    // Uses call_once to ensure that the instance is created only once
    std::call_once(onceFlag, []()
                   { instance = new Vet(); });
    return *instance;
}

void Vet::add_animal(Animal *a)
{
    this->animals.push_back(a);
}

std::unordered_set<std::string> Vet::show_sick()
{
    std::unordered_set<std::string> sick_animals;
    for (const auto &animal : animals)
        if (!animal->check_health())
            sick_animals.insert(animal->get_name());
    return sick_animals;
}

std::unordered_set<std::string> Vet::show_sick_dogs()
{
    std::unordered_set<std::string> sick_dogs;
    for (const auto &animal : animals)
    {
        Dog *dogPtr = dynamic_cast<Dog *>(animal); // Safe dynamic cast
        if (dogPtr && !dogPtr->check_health())
            sick_dogs.insert(dogPtr->get_name());
    }
    return sick_dogs;
}
