#include <kipr/botball.h>

int main()
{
    # these vals need to be tested and checked
    threshhold_min = 2500;
    threshhold_max = 3000;
    yoink_arm = 3;
    up = 2040;
    down = 300;
    while(1){
    	# bot moves up to top left of river
        move_to_river();
        
        count = 0;
        if(analog(0) > threshhold_min && analog(0) < threshhold_max){
            if(count % 2 == 0){
                count = count + 1;
            }
            else{
                # yoink();
                rotateL90();
                set_servo_position(yoink_arm, up);
                
                count = count + 1
            }
    }
        
    
        
    # using the range finder it counts the instances that an obj is close to it
    # once we hit the 2nd intance the bot excecutes the yoink function
    
    
    }
    return 0;
}