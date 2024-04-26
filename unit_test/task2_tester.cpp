#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_set>

#include "../Vet/Vet.hpp"

/// Test Fixture for Vet Class
class VetTest : public ::testing::Test
{
protected:
    Vet &vet = Vet::get_instance();

    void SetUp() override
    {
        // Setup code here, adding initial animals to the vet system
        vet.add_animal(new Dog("dog1", 38.5, 20, 80, true));  // healthy dog
        vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));  // not healthy dog (temp too high)
        vet.add_animal(new Dog("dog3", 38.5, 20, 80, false)); // not healthy dog (heart rate too little for small breed)
        vet.add_animal(new Cat("cat1", 38.7, 30, 130));       // healthy cat
        vet.add_animal(new Cat("cat2", 38.7, 42, 130));       // not healthy cat (breath is too high)
        vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32));    // healthy cow
        vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20));    // not healthy cow (milk production too low)
    }

    void TearDown() override
    {
        // Teardown code here, if any.
    }
};

/// Test to verify the singleton instance of Vet
TEST_F(VetTest, SingletonInstance)
{
    Vet &vet2 = Vet::get_instance();
    ASSERT_EQ(&vet, &vet2) << "Both pointers should point to the same instance";
}

/// Test to identify sick animals
TEST_F(VetTest, IdentifySickAnimals)
{
    std::unordered_set<std::string> expected = {"dog2", "dog3", "cat2", "cow2"};
    std::unordered_set<std::string> result = vet.show_sick();
    ASSERT_EQ(result, expected);
}

/// Test to specifically identify sick dogs
TEST_F(VetTest, IdentifySickDogs)
{
    std::unordered_set<std::string> expected = {"dog2", "dog3"};
    std::unordered_set<std::string> result = vet.show_sick_dogs();
    ASSERT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
