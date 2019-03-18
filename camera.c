#include <kipr/botball.h>

int main()
{
    camera_open_black();
    int a=0;
    while(1){
        motor(a%2,(((get_object_count(0)==0)?0:(get_object_center_x(0,0)<80)?1:-1)*((a%2)*2)-1)*(analog(1)-2500)/(25));
        if(get_object_count(0)==0){
        	printf("Nothing\n");   
        }
        
        a+=1;
        while(!camera_update());
    }
}
