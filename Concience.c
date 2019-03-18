#include <kipr/botball.h>

#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>



int main(){
	create_connect();
    
    create_drive_direct(100,100);
   
    msleep(1000);
    create_set_angle(0);
    create_drive_direct(-100,100);
    while(get_create_total_angle() < 90);
    msleep(2000);
    
    create_stop();
    create_disconnect();
    return 0;
}
