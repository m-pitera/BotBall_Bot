
#include <kipr/botball.h>

int rotateL90(){
    // these vals should change after testing so that it's more accurate
    motor(0, 50);
    motor(1, -50);
    msleep(2000);
}

int yoink(){
    int yoink_arm = 3;
    int up = 2040;
    int down = 300;
    
    rotateL90();
    set_servo_position(yoink_arm, up);
    
    // values should be adjusted after testing
    motor(0, 60);
    motor(1, 60);
    msleep(950);
    
    return 0;
}

int main()
{
    // these vals need to be tested and checked
    int threshhold_min = 2500;
    int threshhold_max = 3000;
    
    while(1){
    	// bot moves up to top left of river
        move_to_river();
        
        count = 0;
        if(analog(0) > threshhold_min && analog(0) < threshhold_max){
            if(count % 2 == 0){
                count = count + 1;
            }
            else{
                yoink();
                
                
                count = count + 1
            }
    }
        
    
        
    // using the range finder it counts the instances that an obj is close to it
    // once we hit the 2nd intance the bot excecutes the yoink function
    
    
    }
    return 0;
}
