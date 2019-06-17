#ifndef DOG_HPP_
#define DOG_HPP_

#include "heart.h"
using namespace std;

class Dog : private Heart    // Private inheritance
{
public:

    // Constructor of Dog
    Dog(int heartbeat, int max_heartbeat, int min_heartbeat, int speed, int weight);

    // Destructor of Dog
    ~Dog();

    //This function will move the dog for the given time duration with the speed, refer to the output for the details
    void move(int time);

    //prints the heart info, it will be used in the print() function
    void print_heart_info(){
        cout << "heartbeat: " << check_heartbeat()
             << "\tmax_heartbeat: " << get_max_heartbeat()
             << "\tmin_heartbeat: " << get_min_heartbeat();
    }

    //print the dog information (including heart information, weight and speed)
    void print();

    //get the heart information
    int check_heartbeat();
    int get_max_heartbeat();
    int get_min_heartbeat();

    //get the weight and speed information of the Dog
    int get_weight();
    int get_speed();

    //change the state of heart these two function should call the corresponding functions in the Heart class
    void boost_heartbeat();
    void decrease_heartbeat();

private:
    int speed;
    int weight;

};

#endif
