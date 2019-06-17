#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>
#include "heart.h"

class Animal {
public:
	//Constructor of Animal
    Animal(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs);

    //Destructor of Animal
    ~Animal();

    //a function that will increase the weight of an animal
    void grow(int weight);


    //print the information related to the animal see the output for more information
    void print();

    //get the heart information
    int check_heartbeat();
    int get_max_heartbeat();
    int get_min_heartbeat();

    //get the various attributes of the animal
    int get_weight();
    int get_legs();

private:
    int weight;
    int num_of_legs;
    Heart heart;
};

#endif
