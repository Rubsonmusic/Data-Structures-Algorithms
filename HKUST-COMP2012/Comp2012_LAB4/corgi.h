#ifndef CORGI_HPP_
#define CORGI_HPP_

#include "dog.h"

class Corgi : protected Dog {
public:
    //Constructor of Corgi
    Corgi(int heartbeat, int max_heartbeat, int min_heartbeat, int speed, int weight);

    //Destructor of Corgi
    ~Corgi();

    //print the info of the Corgi, this function will call Dog::print_heart_info(), refer to the output for the details
    void print();

    //This function will move the Corgi for the given time duration with the speed, refer to the output for the details
    void move(int time);

    //get the weight and speed information of the Corgi
    int get_weight();
    int get_speed();

    //change the state of heart these two function should call the corresponding functions in the Heart class
    void boost_heartbeat();
    void decrease_heartbeat();
};


#endif
