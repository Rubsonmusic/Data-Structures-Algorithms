#ifndef LION_HPP_
#define LION_HPP_

#include <iostream>
#include "animal.h"

class Lion : public Animal {
public:
	//Constructor of Lion
    Lion(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs, int speed);

    //Destructor of Lion
    ~Lion();

    //This function will move the lion for the given time duration with the speed, refer to the output for the details
    void move(int time);

    //This function will grow the lion for weight units, refer to the output for the details
    void grow(int weight);

    //This function prints the information of the Lion, refer to the output for the details
    void print();

private:
    int speed;
};

#endif
