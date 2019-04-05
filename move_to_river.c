#include <kipr/botball.h>
#include <stdlib.h>

void moveInMeter(double distance, int power, int direction);
void rotate(double ratioOfCircle, int power, int direction);

const double ticksToMeter = 7503.018746;
const double pi = 3.141592654;
const double circumfranceOfBot = 0.14*3.141592654;
const int light_sensor_port = 0;
const int COUNTER_CLOCKWISE = -1;
const int CLOCKWISE = 1;

int main()
{
    //wait_for_light(light_sensor_port);
    shut_down_in(119);
    
    
    rotate(.25, 70, CLOCKWISE);
    moveInMeter(.3, 60, 1);
    rotate(.25, 70, COUNTER_CLOCKWISE);
    moveInMeter(.7, 60, 1);
    
    return 0;
}

void moveInMeter(double distance, int power, int direction){
   	cmpc(0);
    while(abs(gmpc(0)) <= distance*ticksToMeter){
		motor(0,direction*power);
    	motor(1,direction*power);
    } 
    ao();
}

void rotate(double ratioOfCircle, int power, int direction){
   	cmpc(0);
    while(abs(gmpc(0)) <= ratioOfCircle*circumfranceOfBot*ticksToMeter){
		motor(0,direction*power);
    	motor(1,-1*direction*power);
    } 
    ao();
    
}
