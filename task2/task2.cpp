#include<iostream>
#include<stdexcept>
#include<cmath>
#include<iomanip>
#include<vector>
    
using namespace std;

class Animal{  
    public:
        string name;
        double temp;
        double breath;
        double heart;
        virtual bool check_health() = 0;

        Animal(string name, double temp, double breath, double heart):name(name),temp(temp),breath(breath),heart(heart){
        } 
        ~Animal(){
        }
};


class Dog:public Animal{
    public:
        bool is_large;
        Dog(string name, double temp, double breath, double heart, bool is_large):Animal(name,temp,breath,heart),is_large(is_large){
        }
        ~Dog(){

        }
        bool check_health(){
            if(is_large == true && (38 <= temp && temp <= 39.2) && (10 <= breath && breath <= 35) && (60 <= heart && heart <= 100))
                return true;
            if(is_large == false &&(38 <= temp && temp <= 39.2) && (10 <= breath && breath <= 35) && (100 <= heart && heart <= 140))
                return true;
            return false; 
        }
};

class Cat:public Animal{
public:
    Cat(string name, double temp, double breath, double heart):Animal(name,temp,breath,heart){

    }
    ~Cat();
    bool check_health(){
        if((38 <= temp && temp <= 39.2) && (16 <= breath && breath <= 40) && (120 <= heart && heart <= 140))
            return true;
        return false;
    }
};

class Cow:public Animal{
public:
    double milk;
    Cow(string name, double temp, double breath, double heart, double litres):Animal(name,temp,breath,heart),milk(litres){
    }
    ~Cow();
    bool check_health(){
        if((38.5 <= temp && temp <= 39.5) && (26 <= breath && breath <= 50)
             && (48 <= heart && heart <= 84) && (30 <= milk))
                return true;
            return false;
        }
};

class Vet{
    private:
        vector<Animal*> animals;
        size_t size;
        //Singleton
        static bool instanceFlag;
        static Vet *single;
        Vet():size(0){
            
        }
        ~Vet(){
            instanceFlag = false;
            animals.clear();
            size=0;
        }
    public:

        static Vet &get_instance(){
            if(!instanceFlag){
                single = new Vet();
                instanceFlag = true;
                return *single;
            }
            else
                return *single;
        }

        void add_animal(Animal* a){
            this->animals.push_back(a);
            size++;

        }
        void show_sick(){
            for (size_t i = 0 ; i<size; i++)
                if(!animals[i]->check_health())
                    cout << animals[i]->name << " ";
            cout << endl;
        }
        void show_sick_dogs(){
           for (size_t i = 0 ; i<size; i++){
                if(typeid(*animals[i]) == typeid(Dog)){
                    if(!animals[i]->check_health())
                        cout << animals[i]->name << " ";
                }
            }
            cout << endl;

        }

        
};

bool Vet::instanceFlag = false;
Vet* Vet::single = NULL;