#include <kipr/botball.h>

void yoink();
void move_to_river();
void move_to_dropoff();
void rotate(double ratioOfCircle, int power, int direction);
void moveInMeter(double distance, int power, int direction);

const int yoink_arm_port = 3;
const int light_sensor_port = 0;
const int range_sensor_port = 1;
const int UP = 2040;
const int DOWN = 300;
const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int threshhold_min = 1500;
const int threshhold_max = 2500;
const double ticksToMeter = 7503.018746;
const double pi = 3.141592654;
const double circumfranceOfBot = 0.14*3.141592654;

int main()
{
    wait_for_light(light_sensor_port);
    shut_down_in(119);

    // these vals need to be tested and checked
    int close_count = 0;
    int allow_add = 1;

    motor(0, 60);
    motor(1, 60);
    
    printf("start; ");
	// bot moves UP to top left of river
    move_to_river();

    // yoink all the ppl pieces
    while(1){
        motor(0, 40);
        motor(1, 40);
        // in-progress yoink detect
        if(analog(range_sensor_port) > threshhold_min && analog(range_sensor_port) < threshhold_max){
            if(allow_add && close_count % 2 == 0){
                printf("wall count; ");
                close_count = close_count + 1;
                allow_add = 0;
            }
            else if (allow_add && close_count % 2 == 1){
                printf("yoink; ");
                yoink();
                close_count = close_count + 1;
                allow_add = 0;
            }
    	}
        else if(analog(range_sensor_port) < threshhold_min){
            printf("far detect; ");
            allow_add = 1;
        }

    // using the range finder it counts the instances that an obj is close to it
    // once we hit the 2nd intance the bot excecutes the yoink function
    }
    return 0;
}

void move_to_river(){
    rotate(.25, 30, CLOCKWISE);
    moveInMeter(.5, 60, 1);
    rotate(.25, 30, COUNTER_CLOCKWISE);
    moveInMeter(.68, 60, 1);
    rotate(.28, 30, COUNTER_CLOCKWISE);
}

void identify_non_burning_hospital(){
    
}

void yoink(){
    
    rotate(.25, 20, CLOCKWISE);
    set_servo_position(yoink_arm_port, UP);
    
    // values should be adjusted after testing
    // the purpose of this is to move UP to prepare for yoink
    motor(0, 60);
    motor(1, 60);
    msleep(800);
    
    set_servo_position(yoink_arm_port, DOWN);
    
    // values should be adjusted after testing
    // the purpose of this is to move back and yoink
    motor(0, -60);
    motor(1, -60);
    msleep(800);

    rotate(.25, 20, COUNTER_CLOCKWISE);
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
