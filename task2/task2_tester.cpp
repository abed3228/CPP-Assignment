//you can add the following main to your task2.cpp to test it

#include <iostream>
#include "task2.cpp"

/*
 check if animal is Interfaces beguase uml 

*/
using namespace std;
int main() {
    cout << "program start" << endl;
    Vet& vet = Vet::get_instance();
    //Vet vet;
    //healthy dog
    vet.add_animal(new Dog("dog1", 38.5, 20, 80, true)); 
    //not healthy dog (temp too high)
    vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));
    
    //not healthy dog (heart rate too little for small breed)
    vet.add_animal(new Dog("dog3", 38.5, 20, 80, false)); 

    //healthy cat
    vet.add_animal(new Cat("cat1", 38.7, 30, 130)); 

    //not healthy cat (breath is too high)
    vet.add_animal(new Cat("cat2", 38.7, 42, 130));
 
    //healthy cow
    vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32)); 

    //not healthy cow (milk production too low)
    vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20)); 
    
    vet.show_sick(); //should print: dog2 dog3 cat2 cow2
    vet.show_sick_dogs(); //should print: dog2 dog3


    cout << &vet <<endl;
    Vet& vet2 = Vet::get_instance();
    cout << &vet2 <<endl;

}