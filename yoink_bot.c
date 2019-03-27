
#include <kipr/botball.h>

void yoink();
void move_to_river();
void move_to_dropoff();
void rotate(double ratioOfCircle, int power, int direction);
void moveInMeter(double distance, int power, int direction);

const int LEFT = 1;
const int RIGHT = -1;
const double ticksToMeter = 7503.018746;
const double pi = 3.141592654;
const double circumfranceOfBot = 0.14*3.141592654;

int main()
{
    // these vals need to be tested and checked
    int threshhold_min = 2500;
    int threshhold_max = 3000;
    
    while(1){
    	// bot moves up to top left of river
        move_to_river();
        
        int count = 0;
        // this doesn't work
        if(analog(0) > threshhold_min && analog(0) < threshhold_max){
            if(count % 2 == 0){
                count = count + 1;
            }
            else{
                yoink();     
                count = count + 1;
            }
    	}

    // using the range finder it counts the instances that an obj is close to it
    // once we hit the 2nd intance the bot excecutes the yoink function
    }
    return 0;
}

void move_to_river(){
    // this needs to be filled out
}

void identify_non_burning_hospital(){
    // camera
}

void yoink(){
    int yoink_arm = 3;
    int up = 2040;
    int down = 300;
    
    rotate(.25, 20, LEFT);
    set_servo_position(yoink_arm, up);
    
    // values should be adjusted after testing
    // the purpose of this is to move up to prepare for yoink
    motor(0, 60);
    motor(1, 60);
    msleep(800);
    
    set_servo_position(yoink_arm, down);
    
    // values should be adjusted after testing
    // the purpose of this is to move back and yoink
    motor(0, -60);
    motor(1, -60);
    msleep(800);

    rotate(.25, 20, RIGHT);
}

void rotate(double ratioOfCircle, int power, int direction){
   	cmpc(0);
    while(gmpc(0) <= ratioOfCircle*circumfranceOfBot*ticksToMeter){
		motor(0,direction*power);
    	motor(1,-1*direction*power);
    } 
    ao();
    
}

void moveInMeter(double distance, int power, int direction){
   	cmpc(0);
    while(gmpc(0) <= distance*ticksToMeter){
		motor(0,direction*power);
    	motor(1,direction*power);
    } 
    ao();
}
