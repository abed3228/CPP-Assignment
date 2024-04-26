# Animal Health Management System

This project includes a set of classes that simulate an animal health management system based on specific health criteria for different animal types. Below is the outline of the classes and their functionalities as described by the UML diagram.

## Classes

### Abstract Class: Animal

- **Fields**:

  - `name` (string): Name of the animal.
  - `temp` (double): Body temperature in Celsius.
  - `breath` (double): Respiration rate (breaths per minute).
  - `heart` (double): Heart rate (beats per minute).

- **Constructor**:

  - `Animal(string name, double temp, double breath, double heart)`

- **Method**:
  - `check_health()`: Abstract method that checks if the animal's vital stats are within a healthy range.

### Derived Class: Dog

- **Additional Field**:

  - `is_large` (bool): True if the dog is of a large breed, false otherwise.

- **Health Check**:
  - Temperature: 38 to 39.2 degrees Celsius.
  - Respiration: 10 to 35 breaths per minute.
  - Heart rate: 60 to 100 beats per minute if large, 100 to 140 if small.

### Derived Class: Cat

- **Health Check**:
  - Temperature: 38 to 39.2 degrees Celsius.
  - Respiration: 16 to 40 breaths per minute.
  - Heart rate: 120 to 140 beats per minute.

### Derived Class: Cow

- **Additional Field**:

  - `milk` (double): Milk production in litres per day.

- **Health Check**:
  - Temperature: 38.5 to 39.5 degrees Celsius.
  - Respiration: 26 to 50 breaths per minute.
  - Heart rate: 48 to 84 beats per minute.
  - Milk Production: 30 or more litres per day.

## Vet Class (Singleton)

- **Responsibility**:

  - Manages a collection of animals, maintaining their health records and statuses.

- **Methods**:
  - `get_instance()`: Returns a reference to the singleton Vet instance.
  - `add_animal(Animal* animal)`: Adds an animal to the Vet's records.
  - `show_sick()`: Displays the names of all sick animals.
  - `show_sick_dogs()`: Specifically displays the names of sick dogs.

**Note**: This class ensures that all dynamically allocated Animal objects are properly managed and deleted when the Vet instance is destroyed.

## Usage

To interact with the system, instantiate animals and add them to the Vet instance. Utilize the Vet's methods to assess and display health statuses as needed.

## HOW RUN TEST

- \*\*make tests

## HOW BUILD CLASS

- \*\*make task2
